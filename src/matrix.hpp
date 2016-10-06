#pragma once

#include <cmath>

class Matrix
{
public:
  Matrix() = default;
  Matrix(float m00, float m01, float m10, float m11)
    : m_m00(m00), m_m01(m01), m_m10(m10), m_m11(m11)
  {}
  float & m00() { return m_m00; }
  float & m01() { return m_m01; }
  float & m10() { return m_m10; }
  float & m11() { return m_m11; }

  Matrix & operator = (Matrix const & obj)
  {
    if (this == &obj) return *this;
    m_m00 = obj.m_m00;
    m_m01 = obj.m_m01;
    m_m10 = obj.m_m10;
    m_m11 = obj.m_m11;
    return *this;
  }

  float Determinant() const
  {
    return m_m00*m_m11-m_m01*m_m10;
  }

  void ColumnReplace(float * rep, int column)
  {
    if (column == 0) { m_m00 = rep[0]; m_m10 = rep[1]; }
    if (column == 1) { m_m01 = rep[0]; m_m11 = rep[1]; }
  }
private:
  float m_m00 = 0.0f, m_m01 = 0.0f, m_m10 = 0.0f, m_m11 = 0.0f;
};
