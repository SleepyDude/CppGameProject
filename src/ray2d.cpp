#include "ray2d.h"

Ray2D::Ray2D(Point2D const & origin, Point2D const & direction)
  : m_origin(origin), m_direction(direction)
{}

Ray2D::Ray2D(Ray2D const & obj)
  : m_origin(obj.m_origin), m_direction(obj.m_direction)
{}

Ray2D::Ray2D(float f1, float f2, float f3, float f4)
  : m_origin(f1, f2), m_direction(f3, f4)
{}


// Оператор логического равенства.
bool Ray2D::operator == (Ray2D const & obj) const
{
  return (m_origin == obj.m_origin) && (m_direction == obj.m_direction);
}

Point2D & Ray2D::origin() { return m_origin; }
Point2D const & Ray2D::direction() { return m_direction; }

// Оператор присваивания.
Ray2D & Ray2D::operator = (Ray2D const & obj)
{
  if (this == &obj) return *this;
  m_origin = obj.m_origin;
  m_direction = obj.m_direction;
  return *this;
}

// Оператор логического неравенства.
bool Ray2D::operator != (Ray2D const & obj) const
{
  return !Ray2D::operator == (obj);
}

// Переопределение оператора [].
Point2D Ray2D::operator [] (unsigned int index) const
{
  if (index >= 2) return { 0.0f, 0.0f };
  return index == 0 ? m_origin : m_direction;
}

// Функция проверки пересечения луча и отрезка методом Крамера
bool Ray2D::Intersect(Point2D a, Point2D b)
{
  Matrix m, m1, m2;
  float hyp = sqrt( m_direction.x()*m_direction.x() + m_direction.y()*m_direction.y());
  float cos = m_direction.x() / hyp;
  float sin = m_direction.y() / hyp;

  m.m00() = b.x() - a.x();
  m.m01() = -cos;
  m.m10() = b.y() - a.y();
  m.m11() = -sin;

  float res[2];
  res[0] = -( a.x() - m_origin.x() );
  res[1] = -( a.y() - m_origin.y() );

  float D = m.Determinant();

  if (D == 0) { return false; }

  m1 = m;
  m2 = m;
  m1.ColumnReplace(res,0);
  m2.ColumnReplace(res,1);
  float D1 = m1.Determinant();
  float D2 = m2.Determinant();

  float T1 = D1/D;
  float T2 = D2/D;

  if( T2 >= 0 && ( T1 >= 0 && T1 <= 1 ))
    return true;
  else
    return false;
}

// Оператор проверки пересечения луча и бокса
bool Ray2D::operator % (Box2D & obj)
{
  Point2D p1 = obj.boxMin(), p2 = { obj.boxMin().x(), obj.boxMax().y() },
          p3 = obj.boxMax(), p4 = { obj.boxMax().x(), obj.boxMin().y() };
  return Intersect(p1,p2) || Intersect(p2,p3) || Intersect(p3,p4) || Intersect(p4,p1);
}
