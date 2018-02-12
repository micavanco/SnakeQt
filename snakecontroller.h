#ifndef SNAKECONTROLLER_H
#define SNAKECONTROLLER_H
#include <QObject>
#include <QMatrix4x4>

namespace Qt3DCore {
class QTransform;
}

class SnakeController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(Qt3DCore::QTransform* target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float moveX READ moveX WRITE setMoveX NOTIFY moveXChanged)
    Q_PROPERTY(float moveY READ moveY WRITE setMoveY NOTIFY moveYChanged)
public:
    SnakeController(QObject *parent=0);

    void setTarget(Qt3DCore::QTransform *target);
    Qt3DCore::QTransform *target() const;

    void setMoveX(float moveX);
    float moveX() const;

    void setMoveY(float moveY);
    float moveY() const;

signals:
    void targetChanged();
    void moveXChanged();
    void moveYChanged();

protected:
    void updateMatrix();

private:
    Qt3DCore::QTransform *m_target;
    QMatrix4x4 m_matrix;
    float m_moveX;
    float m_moveY;
};

#endif // SNAKECONTROLLER_H
