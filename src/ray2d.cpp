#include "ray2d.h"

Ray2D::Ray2D(Point2D origin, Point2D direction)
  : m_origin(origin), m_direction(direction)
{}

Ray2D::Ray2D(Ray2D const & obj)
  : m_origin(obj.m_origin), m_direction(obj.m_direction)
{}

Ray2D::Ray2D(float f1, float f2, float f3, float f4)
  : m_origin(f1,f2), m_direction(f3,f4)
{}


// Оператор логического равенства.
bool Ray2D::operator == (Ray2D const & obj) const
{
  return (m_origin == obj.m_origin)&&(m_direction == obj.m_direction);
}

Point2D & Ray2D::origin() { return m_origin; }
Point2D & Ray2D::direction() { return m_direction; }

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
  return !Ray2D::operator==(obj);
}

// Переопределение оператора [].
Point2D Ray2D::operator [] (unsigned int index) const
{
  if (index >= 2) return { 0.0f, 0.0f };
  return index == 0 ? m_origin : m_direction;
}

float Ray2D::Determinant(float ** m) {
  return m[0][0]*m[1][1]-m[0][1]*m[1][0];
}

float ** Ray2D::ColumnReplace(float ** m, float * rep, int column) {
  // Выделяю память для матрицы 2х2
  float ** matrix = new float*[2];
  for(int i=0;i<2;i++)
    matrix[i]=new float[2];
  // Заполняю её элементами исходной матрицы
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      matrix[i][j] = m[i][j];
  // Заменяю один из столбцов, чтобы получить новую матрицу
  for (int i = 0; i < 2; i++){
    matrix[i][column] = rep[i];
  }
  return matrix;
}


// Функция проверки пересечения луча и отрезка методом Крамера
bool Ray2D::Intersect(Point2D a, Point2D b)
{
  float ** matrix = new float*[2];
  for(int i=0;i<2;i++)
    matrix[i]=new float[2];

  float hyp = sqrt( pow( m_direction.x(), 2 ) + pow( m_direction.y(), 2 ));
  float cos = m_direction.x()/hyp;
  float sin = m_direction.y()/hyp;

  matrix[0][0] = b.x() - a.x();
  matrix[0][1] = -cos;
  matrix[1][0] = b.y() - a.y();
  matrix[1][1] = -sin;

  float res[2];
  res[0] = -( a.x() - m_origin.x() );
  res[1] = -( a.y() - m_origin.y() );

  float D = Determinant(matrix);

  if (D==0) { return false; }

  float** m1 = ColumnReplace(matrix,res,0);
  float** m2 = ColumnReplace(matrix,res,1);

  float D1 = Determinant(m1);
  float D2 = Determinant(m2);

  float T1 = D1/D;
  float T2 = D2/D;
  // Освобождаю память, выделенную для трех матриц 2х2
  for (int i = 0; i < 2; i++)
  {
    delete [] matrix[i];
    delete [] m1[i];
    delete [] m2[i];
  }

  if( T2 >= 0 && ( T1 >= 0 && T1 <= 1 ))
    return true;
  else
    return false;
}

// Оператор проверки пересечения луча и бокса
bool Ray2D::operator % (Box2D & obj)
{
  Point2D p1 = obj.p1(), p2 = { obj.p1().x(), obj.p2().y() },
          p3 = obj.p2(), p4 = { obj.p2().x(), obj.p1().y() };

  bool s1 = Intersect(p1,p2),
       s2 = Intersect(p2,p3),
       s3 = Intersect(p3,p4),
       s4 = Intersect(p4,p1);
  return s1 || s2 || s3 || s4;
}
