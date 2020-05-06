#include <QDebug>

#include "headers/paintscene.h"

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene(parent)
    , m_previousPoint(0, 0)
{
    qDebug() << "PaintScene::PaintScene()";
}

PaintScene::~PaintScene()
{
    qDebug() << "PaintScene::~PaintScene()";
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - 5, event->scenePos().y() - 5, 5, 5, QPen(Qt::NoPen), QBrush(Qt::black));
    qDebug() << "PaintScene::mousePressEvent(): mousePress on: " << event->scenePos().x() << event->scenePos().y();

    m_previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(m_previousPoint.x(), m_previousPoint.y(), event->scenePos().x(), event->scenePos().y(), QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
    qDebug() << "PaintScene::mouseMoveEvent(): previous point =" << m_previousPoint.x() << m_previousPoint.y()
                                               << ", scenePos =" << event->scenePos().x() << event->scenePos().y();
    m_previousPoint = event->scenePos();
}
