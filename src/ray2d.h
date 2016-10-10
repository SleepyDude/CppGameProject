#pragma once

#include <ostream>
#include <cmath>
#include "point2d.hpp"
#include "box2d.h"
#include "matrix.hpp"


class Ray2D
{
public:
  // Конструктор по умолчанию
  Ray2D() = default;
  // Конструктор по 2м точкам
  Ray2D(Point2D const & origin, Point2D const & direction);
  // Конструктор копирования
  Ray2D(Ray2D const & obj);
  // Конструктор по 4м координатам
  Ray2D(float f1, float f2, float f3, float f4);
  // Конструктор перемещения
  Ray2D(Ray2D && obj);

  // Методы возврата значений точки старта и точки, определяющей направляющий вектор
  Point2D const & origin() const;
  Point2D const & direction() const;

  // Перегрузка логического равенства
  bool operator == (Ray2D const & obj) const;
  // Перегрузка логического неравенства
  bool operator != (Ray2D const & obj) const;
  // Перегрузка квадратных скобок
  Point2D operator [] (unsigned int index) const;
  // Перегрузка оператора присваивания
  Ray2D & operator = (Ray2D const & obj);
  // Метод, определяющий пересечение с отрезком
  bool Intersect(Point2D a, Point2D b);
  // Определение оператора пересечения с прямоугольником
  bool operator % (Box2D & obj);
  // Оператор перемещения
  Ray2D & operator = (Ray2D && obj);

private:
  Point2D m_origin = { 0.0f, 0.0f }, m_direction = { 0.0f, 1.0f };
};
