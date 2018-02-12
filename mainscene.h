#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QtCore/QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DCore/QTransform>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QKeyEvent>

#include "snakecontroller.h"
#include "timerchecker.h"


class MainScene:public Qt3DCore::QEntity
{

public:
    MainScene();
    ~MainScene();
Qt3DCore::QEntity *rootEntity;

Qt3DCore::QTransform *cuboidTransform;
Qt3DCore::QTransform *cuboidTransform1;
Qt3DCore::QTransform *cuboidTransform2;
Qt3DCore::QTransform *cuboidTransform3;
Qt3DCore::QTransform *cuboidTransform4;
Qt3DExtras::QCuboidMesh *cuboidMesh;
Qt3DCore::QEntity *cuboidEntity;
    void setAnimation(const char* os, float f,float d,Qt3DCore::QTransform *transform,SnakeController *control,QPropertyAnimation *anim);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    SnakeController *controller;
    SnakeController *controller1;
    SnakeController *controller2;
    SnakeController *controller3;
    SnakeController *controller4;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QPropertyAnimation *animation4;
    QParallelAnimationGroup group;
};

#endif // MAINSCENE_H
