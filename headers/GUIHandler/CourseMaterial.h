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

#include "headers/paintscene.h"

class Facade;

namespace Ui {
class CourseMaterial;
}

class CourseMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit CourseMaterial(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~CourseMaterial();

signals:
    void GUIHandlerCourseMaterialSignal();

private slots:
    void on_next_clicked();
    void on_backToCourseMenu_clicked();

private:    
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void doPainting();

    qreal m_opacity;
    int m_timerId;
    bool m_TimerIsActive;

    QSharedPointer<Ui::CourseMaterial> m_ui;
    QSharedPointer<Facade> m_Facade;
    QGraphicsScene* mp_scene;
    QGraphicsEllipseItem* mp_elipseItem;
    QGraphicsRectItem* mp_rectItem;
    QGraphicsPolygonItem* mp_polygonItem;
    QPolygon m_polygon;
    QPointF m_previousPoint;
    PaintScene* mp_customScene;
    QGraphicsLineItem* mp_lineItem;
    QGraphicsTextItem* mp_text1;
    QGraphicsTextItem* mp_text2;
    QGraphicsTextItem* mp_text3;
    QPoint m_A;
    QPoint m_B;
    QPoint m_C;
};
