#include "mainscene.h"
#include "snakecontroller.h"

MainScene::MainScene()
{
    rootEntity = new Qt3DCore::QEntity;
    //Plane shape data
    Qt3DExtras::QPlaneMesh *planeMesh=new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(20);
    planeMesh->setHeight(20);

    // Material Plane
    Qt3DExtras::QPhongMaterial *materialPlane = new Qt3DExtras::QPhongMaterial(rootEntity);
    materialPlane->setDiffuse(QColor(0x00c600));

    // Material Cuboid
    Qt3DExtras::QPhongMaterial *materialCuboid = new Qt3DExtras::QPhongMaterial(rootEntity);
    materialCuboid->setDiffuse(QColor(QRgb(0xffd300)));

    // Material Wall
    Qt3DExtras::QPhongMaterial *materialWall = new Qt3DExtras::QPhongMaterial(rootEntity);
    materialWall->setDiffuse(QColor(255, 0, 0, 127));

    //Plane mesh transform
    Qt3DCore::QTransform *planeTransform=new Qt3DCore::QTransform();
    planeTransform->setScale(1.3f);

    //Plane
    Qt3DCore::QEntity *m_planeEntity=new Qt3DCore::QEntity(rootEntity);
    m_planeEntity->addComponent(planeMesh);
    m_planeEntity->addComponent(planeTransform);
    m_planeEntity->addComponent(materialPlane);

    // Snake
        cuboidEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *cuboidEntity1 = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *cuboidEntity2 = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *cuboidEntity3 = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *cuboidEntity4 = new Qt3DCore::QEntity(rootEntity);
        cuboidMesh = new Qt3DExtras::QCuboidMesh;
        cuboidMesh->setXExtent(1.0f);
        cuboidMesh->setZExtent(1.0f);
        Qt3DCore::QTransform *cuboidTransform = new Qt3DCore::QTransform;
        cuboidTransform->setTranslation(QVector3D(0.0,0.5f,0.0f));
        Qt3DCore::QTransform *cuboidTransform1 = new Qt3DCore::QTransform;
        cuboidTransform1->setTranslation(QVector3D(1.1f,0.5f,0.0f));
        Qt3DCore::QTransform *cuboidTransform2 = new Qt3DCore::QTransform;
        cuboidTransform2->setTranslation(QVector3D(2.2f,0.5f,0.0f));
        Qt3DCore::QTransform *cuboidTransform3 = new Qt3DCore::QTransform;
        cuboidTransform3->setTranslation(QVector3D(3.3f,0.5f,0.0f));
        Qt3DCore::QTransform *cuboidTransform4 = new Qt3DCore::QTransform;
        cuboidTransform4->setTranslation(QVector3D(4.4f,0.5f,0.0f));

        animation=new QPropertyAnimation(cuboidTransform);
        animation1=new QPropertyAnimation(cuboidTransform1);
        animation2=new QPropertyAnimation(cuboidTransform2);
        animation3=new QPropertyAnimation(cuboidTransform3);
        animation4=new QPropertyAnimation(cuboidTransform4);

        cuboidEntity->addComponent(cuboidMesh);
        cuboidEntity->addComponent(cuboidTransform);
        cuboidEntity->addComponent(materialCuboid);
        cuboidEntity1->addComponent(cuboidMesh);
        cuboidEntity1->addComponent(cuboidTransform1);
        cuboidEntity1->addComponent(materialCuboid);
        cuboidEntity2->addComponent(cuboidMesh);
        cuboidEntity2->addComponent(cuboidTransform2);
        cuboidEntity2->addComponent(materialCuboid);
        cuboidEntity3->addComponent(cuboidMesh);
        cuboidEntity3->addComponent(cuboidTransform3);
        cuboidEntity3->addComponent(materialCuboid);
        cuboidEntity4->addComponent(cuboidMesh);
        cuboidEntity4->addComponent(cuboidTransform4);
        cuboidEntity4->addComponent(materialCuboid);

        // Set snake controller
        controller=new SnakeController(cuboidTransform);
        controller->setTarget(cuboidTransform);
        controller->setMoveY(0.5f);
        controller1=new SnakeController(cuboidTransform1);
        controller1->setTarget(cuboidTransform1);
        controller1->setMoveY(0.5f);
        controller2=new SnakeController(cuboidTransform2);
        controller2->setTarget(cuboidTransform2);
        controller2->setMoveY(0.5f);
        controller3=new SnakeController(cuboidTransform3);
        controller3->setTarget(cuboidTransform3);
        controller3->setMoveY(0.5f);
        controller4=new SnakeController(cuboidTransform4);
        controller4->setTarget(cuboidTransform4);
        controller4->setMoveY(0.5f);


        TimerChecker *timer=new TimerChecker(controller,cuboidTransform,animation);

    // Wall
        Qt3DCore::QEntity *wallEntityL = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *wallEntityR = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *wallEntityU = new Qt3DCore::QEntity(rootEntity);
        Qt3DCore::QEntity *wallEntityD = new Qt3DCore::QEntity(rootEntity);
        Qt3DExtras::QCuboidMesh *wallMesh = new Qt3DExtras::QCuboidMesh;
        wallMesh->setXExtent(25.0f);
        wallMesh->setZExtent(1.0f);


        Qt3DCore::QTransform *wallTransformL = new Qt3DCore::QTransform;
        wallTransformL->setRotationY(90.0f);
        wallTransformL->setTranslation(QVector3D(-12.0f,0.5f,0.0f));

        Qt3DCore::QTransform *wallTransformR = new Qt3DCore::QTransform;
        wallTransformR->setRotationY(90.0f);
        wallTransformR->setTranslation(QVector3D(12.0f,0.5f,0.0f));

        Qt3DCore::QTransform *wallTransformU = new Qt3DCore::QTransform;
        wallTransformU->setTranslation(QVector3D(0.0f,0.5f,12.0f));

        Qt3DCore::QTransform *wallTransformD = new Qt3DCore::QTransform;
        wallTransformD->setTranslation(QVector3D(0.0f,0.5f,-12.0f));

        wallEntityL->addComponent(wallMesh);
        wallEntityL->addComponent(wallTransformL);
        wallEntityL->addComponent(materialWall);
        wallEntityR->addComponent(wallMesh);
        wallEntityR->addComponent(wallTransformR);
        wallEntityR->addComponent(materialWall);
        wallEntityU->addComponent(wallMesh);
        wallEntityU->addComponent(wallTransformU);
        wallEntityU->addComponent(materialWall);
        wallEntityD->addComponent(wallMesh);
        wallEntityD->addComponent(wallTransformD);
        wallEntityD->addComponent(materialWall);

}

MainScene::~MainScene()
{
}

bool MainScene::eventFilter(QObject *obj, QEvent *event)
{

    if(event->type()==QEvent::KeyPress)
    {
        QKeyEvent *keyEvent=static_cast<QKeyEvent*>( event );
        if(keyEvent->key()==Qt::Key_W)
        {
            group.stop();
            group.clear();
            setAnimation("moveY",controller->moveY(),controller->moveY()-25.0f,cuboidTransform,controller,animation);
            setAnimation("moveY",controller1->moveY(),controller1->moveY()-25.0f,cuboidTransform1,controller1,animation1);
            group.start();
        }
        else if(keyEvent->key()==Qt::Key_S)
        {
            group.stop();
            group.clear();
            setAnimation("moveY",controller->moveY(),controller->moveY()+25.0f,cuboidTransform,controller,animation);
            setAnimation("moveY",controller1->moveY(),controller1->moveY()+25.0f,cuboidTransform1,controller1,animation1);
            group.start();
        }
        else if(keyEvent->key()==Qt::Key_A)
        {
            group.stop();
            group.clear();
            setAnimation("moveX",controller->moveX(),controller->moveX()-25.0f,cuboidTransform,controller,animation);
            setAnimation("moveX",controller1->moveX(),controller1->moveX()-25.0f,cuboidTransform1,controller1,animation1);
            group.start();
        }
        else if(keyEvent->key()==Qt::Key_D)
        {
            group.stop();
            group.clear();
            setAnimation("moveX",controller->moveX(),controller->moveX()+25.0f,cuboidTransform,controller,animation);
            setAnimation("moveX",controller1->moveX(),controller1->moveX()+25.0f,cuboidTransform1,controller1,animation1);
            group.start();
        }
    }
    return QObject::eventFilter(obj, event);
}

void MainScene::setAnimation(const char* os, float f,float d,Qt3DCore::QTransform *transform,SnakeController *control,QPropertyAnimation *anim)
{
    anim->stop();
    anim=new QPropertyAnimation(transform);
    anim->setTargetObject(control);
    anim->setPropertyName(os);
    anim->setDuration(3000);
    anim->setStartValue(QVariant::fromValue(f));
    anim->setEndValue(QVariant::fromValue(d));
    group.addAnimation(anim);
}
