#pragma once

#include <memory>
#include "box2d.h"
#include "ray2d.h"
#include "point2d.hpp"
#include "movable.h"
#include "scalable.h"
#include "logger.h"
#include <chrono>

enum FactoryType
{
GunType,
AlienType,
BulletType,
ObstacleType,
};

// Абстрактный класс
class GameEntity: public Movable, public Scalable
{
public:
  GameEntity() = default;

  GameEntity(Point2D const & pos, float xDim, float yDim);

  GameEntity(float xPos, float yPos, float xDim, float yDim);
  // Чистая виртуальная функция
  virtual void Update() = 0;
  // Методы перемещения и маштабирования
  virtual void Move(Point2D const & offset) override;
  virtual void Scale(float factorW,float factorH) override;
  // Методы для получения значений положения и габаритов
  Point2D const & position() const;
  float xDim() const;
  float yDim() const;

  void SetDimension(float width, float height);
  void SetPosition(float x, float y);

  Box2D const & Box() const;
  // Чистый виртуальный деструктор
  virtual ~GameEntity() = 0;
  // Виртульные методы для фабрики
  virtual FactoryType GetType() = 0;
  virtual std::unique_ptr<GameEntity> Create() = 0;

protected:
  Box2D m_box = { 0.0f, 0.0f, 1.0f, 1.0f };
};
