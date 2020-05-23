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
    void on_next_clicked();
    void on_back_clicked();
    void on_sound_clicked();

    void on_next_1_clicked();
    void on_back_1_clicked();
    void on_sound_1_clicked();

    void on_save_clicked();
    void on_save_2_clicked();
    void on_save_3_clicked();
    void on_save_5_clicked();
    void on_save_6_clicked();
    void on_save_7_clicked();
    void on_save_8_clicked();
    void on_save_9_clicked();
    void on_save_10_clicked();
    void on_save_11_clicked();

    void on_edit_clicked();
    void on_edit_2_clicked();
    void on_edit_3_clicked();
    void on_edit_5_clicked();
    void on_edit_6_clicked();
    void on_edit_7_clicked();
    void on_edit_8_clicked();
    void on_edit_9_clicked();
    void on_edit_10_clicked();
    void on_edit_11_clicked();

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
    QProgressDialog*      m_progDialog;

    QGraphicsEllipseItem* m_elipseItem;
    QGraphicsPolygonItem* m_polygonItem;
    QGraphicsRectItem* m_rectItem;

    QGraphicsEllipseItem* m_elipse1Item;
    QGraphicsEllipseItem* m_elipse2Item;
    QGraphicsLineItem* m_line1Item;
    QGraphicsLineItem* m_lineItem;
    QGraphicsPathItem* m_line_PathItem;
    QGraphicsPathItem* m_curvePathItem;
    QGraphicsPathItem* m_linePathItem;
    QGraphicsPathItem* m_lineSegPathItem;
    QGraphicsPathItem* m_angledPathItem;

    QGraphicsTextItem* m_text1;
    QGraphicsTextItem* m_text2;
    QGraphicsTextItem* m_text3;

    QPoint m_A;
    QPoint m_B;
    QPoint m_C;
    QPolygon m_polygon;
    QTextToSpeech m_QTextToSpeech;
    bool m_isCreated;
    bool m_isAdminActive;
};
