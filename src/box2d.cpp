#include "box2d.h"

Box2D::Box2D(Point2D const & boxMin, Point2D const & boxMax)
  : m_boxMin(boxMin), m_boxMax(boxMax)
{}
Box2D::Box2D(Box2D const & obj)
  : m_boxMin(obj.m_boxMin), m_boxMax(obj.m_boxMax)
{}
Box2D::Box2D(float f1, float f2, float f3, float f4)
  : m_boxMin(f1, f2), m_boxMax(f3, f4)
{}

Box2D::Box2D(Box2D && obj)
{
std::swap(m_boxMax, obj.m_boxMax);
std::swap(m_boxMin, obj.m_boxMin);
}

Point2D Box2D::boxMin() { return m_boxMin; }
Point2D Box2D::boxMax() { return m_boxMax; }

Box2D Box2D::SetMin(Point2D const & point)
{
  if (point <<= m_boxMax) m_boxMin = point;
  return *this;
}
Box2D Box2D::SetMax(Point2D const & point)
{
  if (m_boxMin <<= point) m_boxMax = point;
  return *this;
}

// Оператор логического равенства.
bool Box2D::operator == (Box2D const & obj) const
{
  return (m_boxMin == obj.m_boxMin) && (m_boxMax == obj.m_boxMax);
}

// Оператор присваивания.
Box2D & Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  m_boxMin = obj.m_boxMin;
  m_boxMax = obj.m_boxMax;
  return *this;
}

// Метод смещения бокса
Box2D Box2D::Shift(Point2D const & obj)
{
  m_boxMin += obj;
  m_boxMax += obj;
}

// Оператор логического неравенства.
bool Box2D::operator != (Box2D const & obj) const
{
  return !Box2D::operator == (obj);
}

// Переопределение оператора [].
Point2D Box2D::operator [] (unsigned int index) const
{
  if (index >= 2) return { 0.0f, 0.0f };
  return index == 0 ? m_boxMin : m_boxMax;
}

// Оператор проверки пересечения
bool Box2D::operator % (Box2D const & obj)
{
  if (m_boxMax.x() < obj.m_boxMin.x()) return false;
  if (m_boxMin.x() > obj.m_boxMax.x()) return false;
  if (m_boxMax.y() < obj.m_boxMin.y()) return false;
  if (m_boxMin.y() > obj.m_boxMax.y()) return false;
  return true;
}
