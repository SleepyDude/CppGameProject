#pragma once

#include "gameentity.h"
#include "box2d.h"
#include <list>
#include "gameentityfactory.h"
#include "bullet.h"
#include "gun.h"


class Space
{
public:
  Space() = default;

  // Методы для получения значений положения и габаритов
  Point2D const & position() const;
  float xDim() const;
  float yDim() const;
  Box2D const & Box() const;
  // Установка размеров
  void SetDimension(float width, float height);

  std::list<GameEntity*> const & List() const;
  std::list<std::unique_ptr<GameEntity>> const & Bullets() const;

  void Add(GameEntity* element);
  void AddBullet();

  void Update();

  Gun & SpaceGun();

private:
  Box2D m_box = { 0.0f, 0.0f, 800.0f, 600.0f };
  GameEntityFactory m_factory;
  Gun m_gun = { {0, 5}, {48, 40}, 1, 100 };
  std::list<std::unique_ptr<GameEntity>> m_bullets;
  std::list<GameEntity*> m_list;
};
