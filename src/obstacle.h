#pragma once

#include "gameentity.h"

class Obstacle: public GameEntity
{
public:
  Obstacle() = default;

  Obstacle(float hp);

  Obstacle(Point2D const & position, Point2D const & dimension, float hp);

  // Перегрузка логического равенства
  bool operator == (Obstacle const & obj) const;

  // Метод получения значения здоровья
  float const & hp() const;

  // Метод установки значения hp
  void SetHp(float hp);

  void Update() override;
  ~Obstacle() override = default;
private:
  float m_hp = 1000.0f;
};
