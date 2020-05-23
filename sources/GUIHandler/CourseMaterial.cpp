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
    , m_customScene_1(new PaintScene(this))
    , m_customScene_2(new PaintScene(this))
    , m_customScene_3(new PaintScene(this))
    , m_scene_1(new QGraphicsScene(this))
    , m_scene_2(new QGraphicsScene(this))
    , m_scene_3(new QGraphicsScene(this))
    , m_scene_4(new QGraphicsScene(this))
    , m_scene_5(new QGraphicsScene(this))
    , m_A(0, -40)
    , m_B(25, 40)
    , m_C(-25, 40)
    , m_polygon({m_A, m_B, m_C})
    , m_QTextToSpeech(this)
    , m_isCreated(false)
    , m_isAdminActive(false)
{
    qDebug() << "GUIHandlerCourseMaterial::GUIHandlerCourseMaterial";

    m_ui->setupUi(this);

    m_ui->sub_dot_view->setScene(m_scene_1.get());
    m_ui->sub_line_view->setScene(m_scene_2.get());
    m_ui->sub_beam_view->setScene(m_scene_3.get());
    m_ui->sub_line_seg_view->setScene(m_scene_4.get());
    m_ui->sub_angled_line_view->setScene(m_scene_5.get());

    m_ui->task_1_view->setScene(m_customScene_1.get());
    m_ui->task_2_view->setScene(m_customScene_2.get());
    m_ui->task_3_view->setScene(m_customScene_3.get());
    //move to showEvent
    switch (m_activeSubject)
    {
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {
        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_TITLE))
        {
            m_ui->sub_title_text->append(str);
        }

        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_DOT))
        {
            m_ui->sub_dot_text->append(str);
        }

        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_LINE))
        {
            m_ui->sub_line_text->append(str);
        }

        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_BEAM))
        {
            m_ui->sub_beam_text->append(str);
        }

        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_LINE_SEG))
        {
            m_ui->sub_line_seg_text->append(str);
        }

        foreach (const auto& str, m_Facade->getText(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_ANGLED_LINE))
        {
            m_ui->sub_angled_line_text->append(str);
        }


        QTextCharFormat fmt;
        fmt.setBackground(Qt::white);

        QTextCursor cursorTitle(m_ui->sub_title_text->document());
        cursorTitle.setPosition(0, QTextCursor::MoveAnchor);
        cursorTitle.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorTitle.setCharFormat(fmt);
        m_ui->sub_title_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        QTextCursor cursorDot(m_ui->sub_dot_text->document());
        cursorDot.setPosition(0, QTextCursor::MoveAnchor);
        cursorDot.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorDot.setCharFormat(fmt);
        m_ui->sub_dot_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        QTextCursor cursorLine(m_ui->sub_line_text->document());
        cursorLine.setPosition(0, QTextCursor::MoveAnchor);
        cursorLine.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorLine.setCharFormat(fmt);
        m_ui->sub_line_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        QTextCursor cursorBeam(m_ui->sub_beam_text->document());
        cursorBeam.setPosition(0, QTextCursor::MoveAnchor);
        cursorBeam.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorBeam.setCharFormat(fmt);
        m_ui->sub_beam_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        QTextCursor cursorLineSeg(m_ui->sub_line_seg_text->document());
        cursorLineSeg.setPosition(0, QTextCursor::MoveAnchor);
        cursorLineSeg.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorLineSeg.setCharFormat(fmt);
        m_ui->sub_line_seg_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        QTextCursor cursorAngledLine(m_ui->sub_angled_line_text->document());
        cursorAngledLine.setPosition(0, QTextCursor::MoveAnchor);
        cursorAngledLine.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        cursorAngledLine.setCharFormat(fmt);
        m_ui->sub_angled_line_text->setStyleSheet("QTextEdit {font: 14pt \"Papyrus\"; color: black; selection-color: rgb(247, 0, 14);}");

        // TODO off/on panel and view items

        //------------------------

        m_text1 = m_scene_1->addText("A(0, -30)");
        m_text1->setPos(0, -30);
        m_text1->setOpacity(m_opacity);
        m_elipse1Item = m_scene_1->addEllipse(QRect(0, -10, 10, 10), QPen(Qt::NoPen), QBrush(Qt::black));
        m_elipse1Item->setOpacity(m_opacity);

        m_text2 = m_scene_1->addText("B(100, -30)");
        m_text2->setPos(100, -30);
        m_text2->setOpacity(m_opacity);
        m_elipse2Item = m_scene_1->addEllipse(QRect(100, -10, 10, 10), QPen(Qt::NoPen), QBrush(Qt::black));
        m_elipse2Item->setOpacity(m_opacity);

        //------------------------

        QLine line2(0, 100, 200, 100);
        m_line1Item = m_scene_2->addLine(line2, QPen(Qt::black, 4));
        m_line1Item->setOpacity(1);

        m_text3 = m_scene_2->addText("a");
        m_text3->setPos(0, 70);
        m_text3->setOpacity(1);

        QPainterPath line_;
        line_.moveTo(0, 100);
        line_.lineTo(500, 100);
        m_line_PathItem = m_scene_2->addPath(line_,QPen(Qt::black, 4));
        m_line_PathItem->setOpacity(1);

        //------------------------

        QPainterPath curve;
        curve.moveTo(0, 200);
        curve.cubicTo(0, 200, 200, 400, 300, 200);
        curve.cubicTo(300, 200, 500, 400, 600, 200);
        m_curvePathItem = m_scene_3->addPath(curve,QPen(Qt::black, 4));
        m_curvePathItem->setOpacity(1);

        QPainterPath line;
        line.moveTo(0, 300);
        line.lineTo(300, 50);
        m_linePathItem = m_scene_3->addPath(line,QPen(Qt::blue, 4));
        m_linePathItem->setOpacity(1);

        QLine line1(0, 150, 600, 150);
        m_lineItem = m_scene_3->addLine(line1, QPen(Qt::green, 4));
        m_lineItem->setOpacity(1);

        //------------------------

        QPainterPath line_seg;
        line_seg.moveTo(100, 100);
        line_seg.addText(100, 100, QFont("Times", 20, QFont::Thin), "A");
        line_seg.lineTo(500, 100);
        line_seg.addText(500, 100, QFont("Times", 20, QFont::Thin), "B");
        m_lineSegPathItem = m_scene_4->addPath(line_seg, QPen(Qt::black, 4));
        m_lineSegPathItem->setOpacity(1);

        //------------------------

        QPainterPath angledPath;
        angledPath.moveTo(80, 250);
        angledPath.addText(80, 250, QFont("Times", 20, QFont::Thin), "A");

        angledPath.lineTo(10, 100);
        angledPath.addText(10, 100, QFont("Times", 20, QFont::Thin), "B");

        angledPath.lineTo(100, 20);
        angledPath.addText(100, 20, QFont("Times", 20, QFont::Thin), "C");

        angledPath.lineTo(200, 120);
        angledPath.addText(200, 120, QFont("Times", 20, QFont::Thin), "D");

        angledPath.lineTo(120, 250);
        angledPath.addText(120, 250, QFont("Times", 20, QFont::Thin), "F");

        angledPath.lineTo(100, 100);
        angledPath.addText(100, 100, QFont("Times", 20, QFont::Thin), "G");

        m_angledPathItem = m_scene_5->addPath(angledPath, QPen(Qt::black, 4));
        //m_pathItem->setFlag(QGraphicsItem::ItemIsMovable);
        m_angledPathItem->setOpacity(1);

        break;
    }
    case type::eSubject::SHAPES_AND_THEIR_ELEMENTS:
    {
        /*
        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            //m_ui->sub_1_text->append(str);
            //m_ui->sub_2_text->append(str);
        }
        */
        // TODO off/on panel and view items
/*
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
*/
        break;
    }
    case type::eSubject::BASIC_THEOREMS_OF_INITIAL_GEOMENTRY:
    {
        /*
        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            //m_ui->sub_1_text->append(str);
            //m_ui->sub_2_text->append(str);
        }
        // TODO off/on panel and view items
        */
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
    /*this->close();

    if (!m_isCreated)
    {
        qDebug() << "+++++++++++++++++Creating of CourseMaterial+++++++++++++++++++++++";
        m_CourseMaterial_next = QSharedPointer<CourseMaterial>::create(type::eSubject::SHAPES_AND_THEIR_ELEMENTS, true, m_Facade, this);
    }

    connect(m_CourseMaterial_next.get(), &CourseMaterial::GUIHandlerCourseMaterialNextSignal, this, &CourseMaterial::show);
    m_CourseMaterial_next->show();
    */
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

    if (m_QTextToSpeech.state() == QTextToSpeech::State::Speaking)
    {
        m_QTextToSpeech.stop();
    }
    else
    {
        QString toSpeech;

        foreach (const auto& str, m_Facade->getText(m_activeSubject))
        {
            qDebug() << "ToSpeech " << str;
            toSpeech.append(str);
        }

        m_QTextToSpeech.say(toSpeech);
    }
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
    /* TODO
    qDebug() << "GUIHandlerCourseMaterial::on_sound_1_clicked";
    m_QTextToSpeech.stop();
    QString toSpeech;

    foreach (const auto& str, m_Facade->getText(m_activeSubject))
    {
        qDebug() << "ToSpeech " << str;
        toSpeech.append(str);
    }

    m_QTextToSpeech.say(toSpeech);
    */
}

void CourseMaterial::on_save_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_clicked";

    // TODO redo to the QShared
    m_progDialog = new QProgressDialog("Saving...", "", 0, 100, this);
    m_progDialog->setWindowModality(Qt::WindowModal);
    m_progDialog->setCancelButton(0);
    m_progDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_progDialog->setValue(0);
    m_progDialog->show();

    m_ui->sub_title_text->setReadOnly(true); // TODO
    saveText();
    m_progDialog->close();
}

void CourseMaterial::on_save_2_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_2_clicked";
}

void CourseMaterial::on_save_3_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_3_clicked";
}

void CourseMaterial::on_save_5_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_5_clicked";
}

void CourseMaterial::on_save_6_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_6_clicked";
}

void CourseMaterial::on_save_7_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_7_clicked";
}

void CourseMaterial::on_save_8_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_8_clicked";
}

void CourseMaterial::on_save_9_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_9_clicked";
}

void CourseMaterial::on_save_10_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_10_clicked";
}

void CourseMaterial::on_save_11_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_save_11_clicked";
}

void CourseMaterial::on_edit_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_clicked";
    m_ui->sub_title_text->setReadOnly(false);
    // TODO message box
}

void CourseMaterial::on_edit_2_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_2_clicked";
}

void CourseMaterial::on_edit_3_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_3_clicked";
}

void CourseMaterial::on_edit_5_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_5_clicked";
}

void CourseMaterial::on_edit_6_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_6_clicked";
}

void CourseMaterial::on_edit_7_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_7_clicked";
}

void CourseMaterial::on_edit_8_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_8_clicked";
}

void CourseMaterial::on_edit_9_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_9_clicked";
}

void CourseMaterial::on_edit_10_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_10_clicked";
}

void CourseMaterial::on_edit_11_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_edit_11_clicked";
}

void CourseMaterial::showEvent(QShowEvent* e)
{
    qDebug() << "CourseMaterial::showEvent";
    m_isAdminActive = m_Facade->checkActiveAdminAccont();

    if (m_isAdminActive)
    {
        qDebug() << "The admin account is active";
        preparationForAdminAccount();
    }
    else
    {
        qDebug() << "The student account is active. Don't do special preparation";\

        m_ui->edit->setVisible(false);
        m_ui->edit_2->setVisible(false);
        m_ui->edit_3->setVisible(false);
        m_ui->edit_5->setVisible(false);
        m_ui->edit_6->setVisible(false);
        m_ui->edit_7->setVisible(false);
        m_ui->edit_8->setVisible(false);
        m_ui->edit_9->setVisible(false);
        m_ui->edit_10->setVisible(false);
        m_ui->edit_11->setVisible(false);

        m_ui->save->setVisible(false);
        m_ui->save_2->setVisible(false);
        m_ui->save_3->setVisible(false);
        m_ui->save_5->setVisible(false);
        m_ui->save_6->setVisible(false);
        m_ui->save_7->setVisible(false);
        m_ui->save_8->setVisible(false);
        m_ui->save_9->setVisible(false);
        m_ui->save_10->setVisible(false);
        m_ui->save_11->setVisible(false);
    }

    Q_UNUSED(e);
}

void CourseMaterial::paintEvent(QPaintEvent *e)
{
    //qDebug() << "CourseMaterial::paintEvent";

    Q_UNUSED(e);

    if (!m_TimerIsActive)
    {
        //qDebug() << "Timer is stopped";
        m_timerId = startTimer(100);
        m_TimerIsActive = true;
    }
    else
    {
        doPainting();
    }
}

void CourseMaterial::timerEvent(QTimerEvent *e)
{
    //qDebug() << "CourseMaterial::timerEvent";
    Q_UNUSED(e);

    repaint();
}

void CourseMaterial::doPainting()
{
    //qDebug() << "CourseMaterial::doPainting";

    if (m_opacity >= 1)
    {
        //qDebug() << "timer stopped";
        m_TimerIsActive = false;
        killTimer(m_timerId);
        return;
    }

    m_opacity += 0.01;

    switch (m_activeSubject)
    {
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {

       // m_lineItem->setOpacity(m_opacity);
        m_elipse1Item->setOpacity(m_opacity);
        m_elipse2Item->setOpacity(m_opacity);
        /*m_line1Item->setOpacity(m_opacity);
        m_lineItem->setOpacity(m_opacity);
        m_line_PathItem->setOpacity(m_opacity);
        m_curvePathItem->setOpacity(m_opacity);
        m_linePathItem->setOpacity(m_opacity);
        m_lineSegPathItem->setOpacity(m_opacity);
        m_angledPathItem->setOpacity(m_opacity);*/

        m_text1->setOpacity(m_opacity);
        m_text2->setOpacity(m_opacity);
        m_text3->setOpacity(m_opacity);

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

void CourseMaterial::preparationForAdminAccount()
{
    qDebug() << "CourseMaterial::preparationForAdminAccount()";

    m_ui->edit->setVisible(true);
    m_ui->edit_2->setVisible(true);
    m_ui->edit_3->setVisible(true);
    m_ui->edit_5->setVisible(true);
    m_ui->edit_6->setVisible(true);
    m_ui->edit_7->setVisible(true);
    m_ui->edit_8->setVisible(true);
    m_ui->edit_9->setVisible(true);
    m_ui->edit_10->setVisible(true);
    m_ui->edit_11->setVisible(true);

    m_ui->save->setVisible(true);
    m_ui->save_2->setVisible(true);
    m_ui->save_3->setVisible(true);
    m_ui->save_5->setVisible(true);
    m_ui->save_6->setVisible(true);
    m_ui->save_7->setVisible(true);
    m_ui->save_8->setVisible(true);
    m_ui->save_9->setVisible(true);
    m_ui->save_10->setVisible(true);
    m_ui->save_11->setVisible(true);
    qDebug() << "CourseMaterial::preparationForAdminAccount() end";
}

void CourseMaterial::saveText()
{
    qDebug() << "CourseMaterial::saveText()";
    m_progDialog->setValue(0);
    QStringList strList;
    strList.push_back(type::g_KeyStarts);
    m_progDialog->setValue(4);
    strList.push_back(type::g_firstSubjectKeyStarts);
    m_progDialog->setValue(8);
    strList.push_back(type::g_firstSubjectTitleKeyStarts);
    m_progDialog->setValue(12);
    strList.push_back(m_ui->sub_title_text->toPlainText());
    m_progDialog->setValue(16);
    strList.push_back(type::g_firstSubjectTitleKeyEnds);
    m_progDialog->setValue(20);

    strList.push_back(type::g_firstSubjectDotKeyStarts);
    m_progDialog->setValue(24);
    strList.push_back(m_ui->sub_dot_text->toPlainText());
    m_progDialog->setValue(28);
    strList.push_back(type::g_firstSubjectDotKeyEnds);
    m_progDialog->setValue(32);

    strList.push_back(type::g_firstSubjectLineKeyStarts);
    m_progDialog->setValue(36);
    strList.push_back(m_ui->sub_line_text->toPlainText());
    m_progDialog->setValue(40);
    strList.push_back(type::g_firstSubjectLineKeyEnds);
    m_progDialog->setValue(44);

    strList.push_back(type::g_firstSubjectBeamKeyStarts);
    m_progDialog->setValue(48);
    strList.push_back(m_ui->sub_beam_text->toPlainText());
    m_progDialog->setValue(52);
    strList.push_back(type::g_firstSubjectBeamKeyEnds);
    m_progDialog->setValue(56);

    strList.push_back(type::g_firstSubjectLineSegKeyStarts);
    m_progDialog->setValue(60);
    strList.push_back(m_ui->sub_line_seg_text->toPlainText());
    m_progDialog->setValue(64);
    strList.push_back(type::g_firstSubjectLineSegKeyEnds);
    m_progDialog->setValue(68);

    strList.push_back(type::g_firstSubjectAngledLineKeyStarts);
    m_progDialog->setValue(72);
    strList.push_back(m_ui->sub_angled_line_text->toPlainText());
    m_progDialog->setValue(76);
    strList.push_back(type::g_firstSubjectAngledLineKeyEnds);
    m_progDialog->setValue(82);

    strList.push_back(type::g_firstSubjectKeyEnds);
    m_progDialog->setValue(86);
    strList.push_back(type::g_KeyEnds);
    m_progDialog->setValue(90);

    if (m_Facade->saveText(strList))
    {
        m_progDialog->setValue(100);
    }
    else
    {
        // TODO close and show an error popup
    }
}
