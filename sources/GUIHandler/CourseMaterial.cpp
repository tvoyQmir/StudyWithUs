#include <QDebug>

#include "headers/GUIHandler/CourseMaterial.h"
#include "headers/Facade.h"
#include "ui_CourseMaterial.h"

CourseMaterial::CourseMaterial(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_TimerIsActive(false)
    , m_ui(new Ui::CourseMaterial)
    , m_Facade(facade)
    , mp_text1(nullptr)
    , mp_text2(nullptr)
    , mp_text3(nullptr)
    , m_A(0, -40)
    , m_B(25, 40)
    , m_C(-25, 40)
{
    qDebug() << "GUIHandlerCourseMaterial::GUIHandlerCourseMaterial";

    m_ui->setupUi(this);
    mp_scene = new QGraphicsScene(this);
    mp_customScene = new PaintScene(this);
    m_ui->graphicsView->setScene(mp_scene);
    m_ui->graphicsView_2->setScene(mp_customScene);

    foreach (const auto& str, m_Facade->getText(1))
    {
        m_ui->textBrowser->append(str);
    }

    //connect(mp_courseWindow, &CourseWindow::CourseWindowSignal, this, &CourseMaterial::show);
    //connect(m_GUIHandlerCourseResultWindow.get(), &CourseResult::GUIHandlerCourseResultSignal, this, &Menu::show);

    qDebug() << "creating shapes: begin";
    m_polygon << m_A << m_B << m_C;

    mp_text1 = mp_scene->addText("A(0, -40)");
    mp_text2 = mp_scene->addText("B(25, 40)");
    mp_text3 = mp_scene->addText("C(-25, 40)");
    mp_text1->setPos(m_A);
    mp_text2->setPos(m_B);
    mp_text3->setPos(m_C);

    mp_polygonItem = mp_scene->addPolygon(m_polygon, QPen(Qt::black, 2));
    //mp_polygonItem->setFlag(QGraphicsItem::ItemIsMovable);

    QLine line(m_A, m_B);
    mp_lineItem = mp_scene->addLine(line, QPen(Qt::black, 6));
    mp_lineItem->setFlag(QGraphicsItem::ItemIsMovable);

    QRect rect(QPoint(10, 10), QPoint(100, 100));
    mp_elipseItem = mp_scene->addEllipse(rect, QPen(Qt::black, 6));
    mp_elipseItem->setFlag(QGraphicsItem::ItemIsMovable);

    mp_rectItem = mp_scene->addRect(-100, -100, 50, 50, QPen(Qt::black, 6));
    mp_rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    qDebug() << "creating shapes: end";

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    qDebug() << "appearance effect: begin";
    m_opacity = 0;
    mp_lineItem->setOpacity(m_opacity);
    mp_polygonItem->setOpacity(m_opacity);
    mp_elipseItem->setOpacity(m_opacity);
    mp_rectItem->setOpacity(m_opacity);

    qDebug() << "appearance effect: end";
}

CourseMaterial::~CourseMaterial()
{
    qDebug() << "GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial";
}

void CourseMaterial::on_next_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_next_clicked";
}

void CourseMaterial::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseMaterialSignal();
}

void CourseMaterial::paintEvent(QPaintEvent *e)
{
    qDebug() << "CourseMaterial::paintEvent";

    Q_UNUSED(e);

    if (!m_TimerIsActive)
    {
        qDebug() << "Timer is stopped";
        m_timerId = startTimer(100);
        m_TimerIsActive = true;
    }
    else
    {
        doPainting();
    }
}

void CourseMaterial::doPainting()
{
    qDebug() << "CourseMaterial::doPainting";

    if (m_opacity >= 1)
    {
        qDebug() << "timer stopped";
        m_TimerIsActive = false;
        killTimer(m_timerId);
        return;
    }

    m_opacity += 0.01;

    mp_lineItem->setOpacity(m_opacity);
    mp_polygonItem->setOpacity(m_opacity);
    mp_elipseItem->setOpacity(m_opacity);
    mp_rectItem->setOpacity(m_opacity);
}

void CourseMaterial::timerEvent(QTimerEvent *e)
{
    qDebug() << "CourseMaterial::timerEvent";
    Q_UNUSED(e);

    repaint();
}
