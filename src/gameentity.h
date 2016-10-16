#pragma once

#include "box2d.h"
#include "ray2d.h"
#include "point2d.hpp"
#include "movable.h"
#include "scalable.h"

// Абстрактный класс
class GameEntity: public Movable, public Scalable
{
public:
  // Конструктор по умолчанию
  GameEntity() = default;
  // Конструктор по точке и 2м габаритам
  GameEntity(Point2D pos, float xDim, float yDim);
  // Конструктор с четырмя аргументами
  GameEntity(float xPos, float yPos, float xDim, float yDim);
  // Чистая виртуальная функция
  virtual void Update() = 0;
  // Методы перемещения и маштабирования
  virtual void Move(Point2D const & offset) override;
  virtual void Scale(float factor) override;
  // Методы для получения значений положения и габаритов
  Point2D const & position() const;
  float const & xDim() const;
  float const & yDim() const;
  // Взаимосвязь параметров GameEntity и Bounding Box
  Box2D const & Box() const;
  // Чистый виртуальный деструктор
  virtual ~GameEntity() = 0;

protected:
  // За положение буду принимать левый нижний угол bounding box'а
  Point2D m_position = { 0.0f, 0.0f };
  // Габариты - размеры bounding box в направлении x и y соответственно
  float m_xDim = 1.0f, m_yDim = 1.0f;
  /*// Коробка
  Box2D m_box;*/
};
