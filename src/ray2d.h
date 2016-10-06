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
  Ray2D(Point2D const &,Point2D const &);
  // Конструктор копирования
  Ray2D(Ray2D const &);
  // Конструктор по 4м координатам
  Ray2D(float,float,float,float);

  // Методы возврата значений точки старта и точки, определяющей направляющий вектор
  Point2D & origin();
  Point2D & direction();

  // Перегрузка логического равенства
  bool operator == (Ray2D const &) const;
  // Перегрузка логического неравенства
  bool operator != (Ray2D const &) const;
  // Перегрузка квадратных скобок
  Point2D operator [] (unsigned int index) const;
  // Перегрузка оператора присваивания
  Ray2D & operator = (Ray2D const &);
  // Метод, определяющий пересечение с отрезком
  bool Intersect(Point2D, Point2D);
  // Определение оператора пересечения с прямоугольником
  bool operator % (Box2D &);

private:
  Point2D m_origin = { 0.0f, 0.0f }, m_direction = { 0.0f, 1.0f };
};
