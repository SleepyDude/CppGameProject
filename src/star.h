#pragma once

#include <QOpenGLTexture>
#include <cmath>

class Star
{
public:
  Star();
  float const & getXScale() const;
  float const & getYScale() const;
  int const & getSize() const;
  int const & getTimeStart() const;
  float const & getTimePeriod() const;
  QOpenGLTexture * const & getTexture() const;

private:
  // random value from 0 to 1
  float m_xScale = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  float m_yScale = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  int m_size = 1 + std::rand() % 10;
  int m_timeStart = 1000 + std::rand() % 4000;
  float m_timePeriod = (1000.0f + std::rand() % 3000);
  QOpenGLTexture * m_texture = nullptr;
};
