#include "timerchecker.h"

TimerChecker::TimerChecker(SnakeController *controller,Qt3DCore::QTransform *transform,QPropertyAnimation *animation)
    :m_controller(controller),m_transform(transform),m_animation(animation)
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Checker()));

    timer->start(100);
}

void TimerChecker::Checker()
{
    if(m_controller->moveY()>=11||m_controller->moveY()<=-11||m_controller->moveX()>=11||m_controller->moveX()<=-11)
    {
        m_animation->stop();
        m_animation=new QPropertyAnimation(m_transform);
        m_animation->setTargetObject(m_controller);
        m_animation->setPropertyName("moveX");
        m_animation->setDuration(1);
        m_animation->setStartValue(QVariant::fromValue(0.0f));
        m_animation->setEndValue(QVariant::fromValue(0.0f));
        m_animation->start();
        m_animation=new QPropertyAnimation(m_transform);
        m_animation->setTargetObject(m_controller);
        m_animation->setPropertyName("moveY");
        m_animation->setDuration(1);
        m_animation->setStartValue(QVariant::fromValue(0.0f));
        m_animation->setEndValue(QVariant::fromValue(0.0f));
        m_animation->start();
        m_controller->setMoveX(0.0f);
        m_controller->setMoveY(0.0f);
    }
}
