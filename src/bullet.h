#pragma once

#include "gameentity.h"

class Bullet: public GameEntity
{
public:
  Bullet() = default;

  Bullet(float damage, float velocity, Point2D direction);

  Bullet(Point2D const & position, Point2D const & dimension, float damage, float velocity, Point2D direction);

  // Перегрузка логического равенства
  bool operator == (Bullet const & obj) const;

  // Методы для получения значений
  float const & damage() const;
  float const & velocity() const;
  Point2D direction() const;

  // Методы установки значений
  void SetDamage(float damage);
  void SetVelocity(float velocity);
  void SetDirection(Point2D direction);

  // Метод смещения пули в заданном направлении
  void Move();

  void Update() override;
  ~Bullet() override = default;
private:
  float m_damage = 1.0f, m_velocity = 1.0f;
  Ray2D m_ray = { Box().boxMid().x(), Box().boxMid().y(), 0.0f, 1.0f };
};
