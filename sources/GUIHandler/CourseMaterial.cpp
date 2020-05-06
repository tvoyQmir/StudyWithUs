#include <QDebug>

#include "headers/GUIHandler/CourseMaterial.h"
#include "headers/Facade.h"
#include "ui_CourseMaterial.h"

CourseMaterial::CourseMaterial(const type::eSubject subject, const bool isPreviousCourseMaterial, QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_opacity(0)
    , m_timerId(0)
    , m_TimerIsActive(false)
    , m_isPreviousCourseMaterial(isPreviousCourseMaterial)
    , m_activeSubject(subject)
    , m_ui(new Ui::CourseMaterial)
    , m_Facade(facade)
    , m_scene(new QGraphicsScene(this))
    , m_customScene(new PaintScene(this))
    , m_A(0, -40)
    , m_B(25, 40)
    , m_C(-25, 40)
    , m_polygon({m_A, m_B, m_C})
    , m_QTextToSpeech(this)
    , m_isCreated(false)
{
    qDebug() << "GUIHandlerCourseMaterial::GUIHandlerCourseMaterial";
/*

*/
    m_ui->setupUi(this);
    m_ui->sub_1_view->setScene(m_scene.get());
    m_ui->task_1_view->setScene(m_customScene.get());

    switch (m_activeSubject)
    {
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {
        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            m_ui->sub_1_text->append(str);
            m_ui->sub_2_text->append(str);
        }
        // TODO off/on panel and view items

        QLine line(m_A, m_B);
        m_lineItem = m_scene->addLine(line, QPen(Qt::black, 6));
        m_lineItem->setFlag(QGraphicsItem::ItemIsMovable);
        m_lineItem->setOpacity(m_opacity);

        break;
    }
    case type::eSubject::SHAPES_AND_THEIR_ELEMENTS:
    {
        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            m_ui->sub_1_text->append(str);
            m_ui->sub_2_text->append(str);
        }
        // TODO off/on panel and view items

        m_text1 = m_scene->addText("A(0, -40)");
        m_text2 = m_scene->addText("B(25, 40)");
        m_text3 = m_scene->addText("C(-25, 40)");
        m_text1->setPos(m_A);
        m_text2->setPos(m_B);
        m_text3->setPos(m_C);

        m_polygonItem = m_scene->addPolygon(m_polygon, QPen(Qt::black, 2));
        m_polygonItem->setOpacity(m_opacity);

        m_elipseItem = m_scene->addEllipse(QRect(QPoint(10, 10), QPoint(100, 100)), QPen(Qt::black, 6));
        m_elipseItem->setOpacity(m_opacity);
        m_elipseItem->setFlag(QGraphicsItem::ItemIsMovable);

        m_rectItem = m_scene->addRect(-100, -100, 50, 50, QPen(Qt::black, 6));
        m_rectItem->setOpacity(m_opacity);
        m_rectItem->setFlag(QGraphicsItem::ItemIsMovable);

        break;
    }
    case type::eSubject::BASIC_THEOREMS_OF_INITIAL_GEOMENTRY:
    {
        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            m_ui->sub_1_text->append(str);
            m_ui->sub_2_text->append(str);
        }
        // TODO off/on panel and view items
        break;
    }
    default:
        qDebug() << "Unknown subject: " << static_cast<int>(m_activeSubject);
        break;
    }

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    init();
}

CourseMaterial::~CourseMaterial()
{
    qDebug() << "GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial";
}

void CourseMaterial::init()
{
    qDebug() << "GUIHandlerCourseMaterial::init";
    // TODO
}

void CourseMaterial::on_next_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_next_clicked";
    this->close();

    if (!m_isCreated)
    {
        qDebug() << "+++++++++++++++++Creating of CourseMaterial+++++++++++++++++++++++";
        m_CourseMaterial_next = QSharedPointer<CourseMaterial>::create(type::eSubject::SHAPES_AND_THEIR_ELEMENTS, true, m_Facade, this);
    }

    connect(m_CourseMaterial_next.get(), &CourseMaterial::GUIHandlerCourseMaterialNextSignal, this, &CourseMaterial::show);
    m_CourseMaterial_next->show();
}

void CourseMaterial::on_back_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_back_clicked";

    this->close();

    if (m_isPreviousCourseMaterial)
    {
        qDebug() << "GUIHandlerCourseMaterialNextSignal";
        emit GUIHandlerCourseMaterialNextSignal();
    }
    else
    {
        qDebug() << "GUIHandlerCourseMaterialSignal";
        emit GUIHandlerCourseMaterialSignal();
    }
}

void CourseMaterial::on_sound_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_sound_clicked";
    m_QTextToSpeech.stop();
    QString toSpeech;

    foreach (const auto& str, m_Facade->getText(m_activeSubject))
    {
        qDebug() << "ToSpeech " << str;
        toSpeech.append(str);
    }

    m_QTextToSpeech.say(toSpeech);
}

void CourseMaterial::on_next_1_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_next_1_clicked";
}

void CourseMaterial::on_back_1_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_back_1_clicked";

    this->close();
    emit GUIHandlerCourseMaterialSignal();
}

void CourseMaterial::on_sound_1_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_sound_1_clicked";
    m_QTextToSpeech.stop();
    QString toSpeech;

    foreach (const auto& str, m_Facade->getText(m_activeSubject))
    {
        qDebug() << "ToSpeech " << str;
        toSpeech.append(str);
    }

    m_QTextToSpeech.say(toSpeech);
}

void CourseMaterial::paintEvent(QPaintEvent *e)
{
    //qDebug() << "CourseMaterial::paintEvent";

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
    //qDebug() << "CourseMaterial::doPainting";

    if (m_opacity >= 1)
    {
        qDebug() << "timer stopped";
        m_TimerIsActive = false;
        killTimer(m_timerId);
        return;
    }

    m_opacity += 0.01;

    switch (m_activeSubject)
    {
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {
        m_lineItem->setOpacity(m_opacity);

        break;
    }
    case type::eSubject::SHAPES_AND_THEIR_ELEMENTS:
    {
        m_polygonItem->setOpacity(m_opacity);
        m_elipseItem->setOpacity(m_opacity);
        m_rectItem->setOpacity(m_opacity);

        break;
    }
    case type::eSubject::BASIC_THEOREMS_OF_INITIAL_GEOMENTRY:
    {
        // TODO off/on panel and view items
        break;
    }
    default:
        qDebug() << "Unknown subject: " << static_cast<int>(m_activeSubject);
        break;
    }
}

void CourseMaterial::timerEvent(QTimerEvent *e)
{
    //qDebug() << "CourseMaterial::timerEvent";
    Q_UNUSED(e);

    repaint();
}
