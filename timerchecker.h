#ifndef TIMERCHECKER_H
#define TIMERCHECKER_H
#include "snakecontroller.h"
#include <QObject>
#include <QTimer>
#include <QPropertyAnimation>
#include <Qt3DCore/QTransform>

class TimerChecker: public QObject
{
    Q_OBJECT

public:
    TimerChecker(SnakeController *controller,Qt3DCore::QTransform *transform,QPropertyAnimation *animation);
    QTimer *timer;
public slots:
    void Checker();
private:
    SnakeController *m_controller;
    Qt3DCore::QTransform *m_transform;
    QPropertyAnimation *m_animation;
};

#endif // TIMERCHECKER_H
