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

int const & Star::getTime1() const
{
  return m_time1;
}

float const & Star::getTime2() const
{
  return m_time2;
}

QOpenGLTexture * const & Star::getTexture() const
{
  return m_texture;
}
