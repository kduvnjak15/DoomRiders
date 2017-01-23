
#include "DR_Spectator.h"


Spectator::Spectator()
{
    m_pos = Vector3f(0.0f, 0.0f, 0.0f);
    m_LookAt = Vector3f(0.0f, 0.0f, -1.0f);
    m_Up = Vector3f(0.0f, 1.0f, 0.0f);
    mousePos.x = 1024/2;
    mousePos.y = 768/2;

    //HARDCODED COORDINATES
}


void Spectator::moveForward(float s )
{
    m_pos -= m_LookAt.Normalize()*s;
}

void Spectator::moveBackward(float s )
{
    m_pos += m_LookAt.Normalize() *s;
}

void Spectator::strafeLeft(float s  )
{
    m_Up.Cross(m_LookAt);
    m_pos += m_Up.Cross(m_LookAt).Normalize() * s;
}

void Spectator::strafeRight(float s )
{
    m_Up.Cross(m_LookAt);
    m_pos -= m_Up.Cross(m_LookAt).Normalize() * s;
}

void Spectator::rise(float s  )
{
    m_pos += m_Up.Normalize() * s;
}

void Spectator::fall(float s )
{
    m_pos -= m_Up.Normalize() * s;
}

Vector3f Spectator::getPos()
{
    return m_pos;
}

Vector3f Spectator::getLookAt()
{
    return m_LookAt;
}

Vector3f Spectator::getUp()
{
    return m_Up;
}

void Spectator::writePos()
{
    std::cout<<m_pos.x<<", "<<m_pos.y<<", "<<m_pos.z<<std::endl;
}

void Spectator::writeOrientation()
{
    std::cout<<m_LookAt.x<<", "<<m_LookAt.y<<", "<<m_LookAt.z<<std::endl;
}

void Spectator::updateOrientation( int X,  int Y)
{
    int DX = mousePos.x - X;
    int DY = mousePos.y - Y;

    angle_H = ToRadian( DX / 0.10f );
    angle_V = ToRadian( DY / 0.10f );

    std::cout<<angle_H<<" "<<angle_V<<std::endl;

    Vector3f tempView = m_LookAt;
    tempView.Rotate(-angle_H, m_Up);
    tempView.Normalize();

    Vector3f auxView = m_Up.Cross(tempView);
    auxView.Normalize();

    tempView.Rotate(-angle_V, auxView);

    m_LookAt = tempView;
    m_LookAt.Normalize();

    m_Up = m_LookAt.Cross(auxView);
    m_Up.Normalize();

    std::cout<<m_LookAt.x<<", "<<m_LookAt.y<<" "<<m_LookAt.z<<std::endl;

    mousePos.x = X;
    mousePos.y = Y;

}
