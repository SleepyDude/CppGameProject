#include "star.h"

Star::Star()
{
  int number = std::rand() % 6 + 1;
  char name[20];
  sprintf(name, "%s%d%s", "data/star", number,".png");
  m_texture = new QOpenGLTexture(QImage(name));
}

float const & Star::getXScale() const
{
  return m_xScale;
}

float const & Star::getYScale() const
{
  return m_yScale;
}

int const & Star::getSize() const
{
  return m_size;
}

float const & Star::getTimePeriod() const
{
  return m_timePeriod;
}

int const & Star::getTimeStart() const
{
  return m_timeStart;
}

QOpenGLTexture * const & Star::getTexture() const
{
  return m_texture;
}

void Star::Move(float offsetX, float offsetY)
{
  m_xScale += offsetX;
  m_yScale += offsetY;

  if (m_xScale < 0.01f)
    m_xScale = 0.99f;

  if (m_yScale < 0.01f)
    m_yScale = 0.99f;

  if (m_xScale > 1.0f)
    m_xScale = 0.02f;

  if (m_yScale > 1.0f)
    m_yScale = 0.02f;
}
