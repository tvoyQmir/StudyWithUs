#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

private:     
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    QPointF m_previousPoint;

};

#endif // PAINTSCENE_H
