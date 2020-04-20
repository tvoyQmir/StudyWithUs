#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QWidget>

class CourseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CourseWindow(QWidget *parent = nullptr);

signals:
    void CourseWindowSignal();

};

#endif // COURSEWINDOW_H
