#include "snakecontroller.h"
#include <Qt3DCore/qtransform.h>

SnakeController::SnakeController(QObject *parent)
    : QObject(parent)
    , m_target(nullptr)
    , m_matrix()
    , m_moveX(0.0f)
    , m_moveY(0.5f)
{
}

void SnakeController::setTarget(Qt3DCore::QTransform *target)
{
    if(m_target != target)
    {
        m_target=target;
        emit targetChanged();
    }
}

Qt3DCore::QTransform *SnakeController::target() const
{
    return m_target;
}

void SnakeController::setMoveX(float moveX)
{
    if(!qFuzzyCompare(moveX, m_moveX))
    {
        m_moveX=moveX;
        updateMatrix();
        emit moveXChanged();
    }
}

float SnakeController::moveX() const
{
    return m_moveX;
}

void SnakeController::setMoveY(float moveY)
{
    if(!qFuzzyCompare(moveY, m_moveY))
    {
        m_moveY=moveY;
        updateMatrix();
        emit moveYChanged();
    }
}

float SnakeController::moveY() const
{
    return m_moveY;
}

void SnakeController::updateMatrix()
{
    m_matrix.setToIdentity();
    m_matrix.translate(m_moveX,0.5f,m_moveY);
    m_target->setMatrix(m_matrix);
}
