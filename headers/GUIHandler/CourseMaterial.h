#pragma once
#include <QDialog>
#include <QSharedPointer>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QtTextToSpeech>
#include <QProgressDialog>

#include "headers/paintscene.h"
#include "headers/CustomTypes.h"

class Facade;

namespace Ui {
class CourseMaterial;
}

class CourseMaterial : public QDialog
{
    Q_OBJECT

public:
     CourseMaterial(const type::eSubject subject, const bool isPreviousCourseMaterial, QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~CourseMaterial();
     void init();

signals:
    void GUIHandlerCourseMaterialSignal();
    void GUIHandlerCourseMaterialNextSignal();

private slots:
    void on_dot_clicked();
    void on_line_clicked();
    void on_line_segment_clicked();
    void on_curve_line_clicked();
    void on_triangle_clicked();
    void on_rectangle_clicked();

    void on_dot_2_clicked();
    void on_line_2_clicked();
    void on_line_segment_2_clicked();
    void on_curve_line_2_clicked();
    void on_triangle_2_clicked();
    void on_rectangle_2_clicked();

    void on_dot_3_clicked();
    void on_line_3_clicked();
    void on_line_segment_3_clicked();
    void on_curve_line_3_clicked();
    void on_triangle_3_clicked();
    void on_rectangle_3_clicked();

    void on_dot_4_clicked();
    void on_line_4_clicked();
    void on_line_segment_4_clicked();
    void on_curve_line_4_clicked();
    void on_triangle_4_clicked();
    void on_rectangle_4_clicked();

    void on_dot_5_clicked();
    void on_line_5_clicked();
    void on_line_segment_5_clicked();
    void on_curve_line_5_clicked();
    void on_triangle_5_clicked();
    void on_rectangle_5_clicked();

    void on_next_clicked();
    void on_back_clicked();
    void on_sound_clicked();

    void on_next_1_clicked();
    void on_back_1_clicked();
    void on_sound_1_clicked();

    void on_save_title_clicked();
    void on_save_first_paragraph_clicked();
    void on_save_second_paragraph_clicked();
    void on_save_third_paragraph_clicked();
    void on_save_fourth_paragraph_clicked();
    void on_save_fifth_paragraph_clicked();

    void on_edit_title_clicked();
    void on_edit_first_paragraph_clicked();
    void on_edit_second_paragraph_clicked();
    void on_edit_third_paragraph_clicked();
    void on_edit_fourth_paragraph_clicked();
    void on_edit_fifth_paragraph_clicked();

private:
    /**
      *
      * private methods
      *
      */

    void showEvent(QShowEvent* e) override;
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void doPainting();
    void preparationForAdminAccount();
    void saveText();
    void highlightText();
    void prepareAllText(); // TODO add -s
    void prepareALlShapes();
    void onSaveClicked();
    void onEditClicked();
    void onDotClicked(QSharedPointer<QGraphicsScene> scene);
    void onLineClicked(QSharedPointer<QGraphicsScene> scene);
    void onLineSegClicked(QSharedPointer<QGraphicsScene> scene);
    void onCurveLineClicked(QSharedPointer<QGraphicsScene> scene);
    void onTriangleClicked(QSharedPointer<QGraphicsScene> scene);
    void onRectangleClicked(QSharedPointer<QGraphicsScene> scene);

    /**
      *
      * private variables
      *
      */

    qreal m_opacity;
    int m_timerId;
    bool m_TimerIsActive;
    bool m_isPreviousCourseMaterial;
    type::eSubject m_activeSubject;
    QTextToSpeech m_QTextToSpeech;
    bool m_isCreated;
    bool m_isAdminActive;

    QSharedPointer<Ui::CourseMaterial>   m_ui;
    QSharedPointer<Facade>               m_Facade;
    QSharedPointer<CourseMaterial>       m_CourseMaterial_next;
    QSharedPointer<PaintScene>           m_customScene_1;
    QSharedPointer<PaintScene>           m_customScene_2;
    QSharedPointer<PaintScene>           m_customScene_3;
    QSharedPointer<QGraphicsScene>       m_scene_1;
    QSharedPointer<QGraphicsScene>       m_scene_2;
    QSharedPointer<QGraphicsScene>       m_scene_3;
    QSharedPointer<QGraphicsScene>       m_scene_4;
    QSharedPointer<QGraphicsScene>       m_scene_5;

    // dot
    QGraphicsEllipseItem* m_DotItem;
    QGraphicsTextItem* m_textDot;
    QRect m_dot;

    // Line
    QGraphicsPathItem* m_line_PathItem;
    QGraphicsLineItem* m_line1Item;
    QGraphicsTextItem* m_text_line;
    QLine m_line;

    // Curve
    QGraphicsPathItem* m_curvePathItem;
    QGraphicsPathItem* m_linePathItem;
    QGraphicsLineItem* m_lineItem;

    // Line Seg
    QGraphicsLineItem* m_lineSegItem;
    QGraphicsTextItem* m_text_line_seg_begin;
    QGraphicsTextItem* m_text_line_seg_end;
    QLine m_line_seg;

    //Angled
    QGraphicsPathItem* m_angledPathItem;

    //triangle
    QGraphicsPolygonItem* m_polygonItem;
    QPolygon m_polygon;

    //cirle
    QGraphicsEllipseItem* m_circleItem;

    //rectangle
    QGraphicsRectItem* m_rectItem;
};
