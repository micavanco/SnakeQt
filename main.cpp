#include "window.h"
#include <QApplication>
#include <Qt3DExtras>
#include <Qt3DExtras/qt3dwindow.h>
#include <QWidget>
#include <QBoxLayout>
#include "window.h"
#include "mainscene.h"
#include "snakecontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window *w=new window;
    w->setMinimumSize(QSize(800,500));
    MainScene *scene=new MainScene();

    // Camera
    Qt3DRender::QCamera *camera = w->camera();
    camera->lens()->setPerspectiveProjection(30.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 45, 35.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene->rootEntity);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(camera);

    w->installEventFilter(scene);
    w->setRootEntity(scene->rootEntity);
    w->show();


    return a.exec();
}
