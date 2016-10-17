#pragma once

#include "gameentity.h"
#include "box2d.h"
#include <list>


class Space
{
public:
  Space() = default;

  float const & rate() const;
  float const & hp() const;

  // Методы для получения значений положения и габаритов
  Point2D const & position() const;
  float xDim() const;
  float yDim() const;
  Box2D const & Box() const;

  std::list<GameEntity*> const & List() const;

  void Add(GameEntity* element);

  void Update();

private:
  Box2D m_box = { -1.0f, -1.0f, 20.0f, 50.0f };
  std::list<GameEntity*> m_list;
};
