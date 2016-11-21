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
