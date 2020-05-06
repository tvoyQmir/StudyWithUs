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

private:
    /**
      *
      * private methods
      *
      */
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void doPainting();

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
    QSharedPointer<QGraphicsScene>       m_scene;
    QSharedPointer<PaintScene>           m_customScene;

    QGraphicsEllipseItem* m_elipseItem;
    QGraphicsPolygonItem* m_polygonItem;
    QGraphicsRectItem* m_rectItem;
    QGraphicsLineItem* m_lineItem;

    QGraphicsTextItem* m_text1;
    QGraphicsTextItem* m_text2;
    QGraphicsTextItem* m_text3;

    QPoint m_A;
    QPoint m_B;
    QPoint m_C;
    QPolygon m_polygon;
    QTextToSpeech m_QTextToSpeech;
    bool m_isCreated;
};
