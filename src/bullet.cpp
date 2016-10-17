#include "bullet.h"

Bullet::Bullet(float damage, float velocity, Point2D direction)
  : m_damage(damage), m_velocity(velocity), m_ray(Box().boxMid(), direction)
{}

Bullet::Bullet(Point2D const & position, Point2D const & dimension, float damage, float velocity, Point2D direction)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_damage(damage), m_velocity(velocity), m_ray(Box().boxMid(), direction)
{}

// Оператор логического равенства.
bool Bullet::operator == (Bullet const & obj) const
{
  return (Box() == obj.Box()) && (m_damage == obj.m_damage) && (m_velocity == obj.m_velocity) && (m_ray.direction() == obj.m_ray.direction());
}

// Методы для получения значений
float const & Bullet::damage() const { return m_damage; }
float const & Bullet::velocity() const { return m_velocity; }
Point2D Bullet::direction() const { return m_ray.direction(); }

// Методы установки значений
void Bullet::SetDamage(float damage) { m_damage = damage; }
void Bullet::SetVelocity(float velocity) { m_velocity = velocity; }
void Bullet::SetDirection(Point2D direction) { m_ray.SetDirection(direction); }

// Метод смещения пули в заданном направлении
void Bullet::Move()
{
  m_ray.Normalization();
  GameEntity::Move(m_ray.direction());
  m_ray.SetOrigin(Box().boxMid());
}

void Bullet::Update()
{}