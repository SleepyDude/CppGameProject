#pragma once

#include "gameentity.h"

class Bullet: public GameEntity
{
public:
  // Конструктор по умолчанию
  Bullet();
  // Конструктор с тремя аргументами
  Bullet(float damage, float velocity, Point2D direction);
  // Конструктор с 6ю аргументами
  Bullet(Point2D pos, float xDim, float yDim, float damage, float velocity, Point2D direction);
  // Конструктор с 7ю аргументами
  Bullet(float xPos, float yPos, float xDim, float yDim, float damage, float velocity, Point2D direction);

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
  ~Bullet() override;
private:
  float m_damage = 1.0f, m_velocity = 1.0f;
  Ray2D m_ray = { Box().boxMid().x(), Box().boxMid().y(), 0.0f, 1.0f };
};
