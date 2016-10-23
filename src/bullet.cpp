#include "bullet.h"

Bullet::Bullet(float damage, float velocity, Point2D direction)
  : m_damage(damage), m_velocity(velocity), m_ray(Box().boxMid(), direction)
{
  if (damage <= 0 || velocity <= 0)
  {
    throw std::invalid_argument("damage and velocity must be positive");
  }
}

Bullet::Bullet(Point2D const & position, Point2D const & dimension, float damage, float velocity, Point2D direction)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_damage(damage), m_velocity(velocity), m_ray(Box().boxMid(), direction)
{
  if (damage <= 0 || velocity <= 0)
  {
    throw std::invalid_argument("damage and velocity must be positive");
  }
}

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
void Bullet::SetDamage(float damage)
{
  if (damage <= 0)
  {
    throw std::invalid_argument("damage must be positive");
  }
  m_damage = damage;
}
void Bullet::SetVelocity(float velocity)
{
  if (velocity <= 0)
  {
    throw std::invalid_argument("velocity must be positive");
  }
  m_velocity = velocity;
}
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

std::ostream & operator << (std::ostream & os, Bullet const & obj)
{
  os << "**Bullet** Position = {" << obj.position().x() << " " << obj.position().y() << "} " << "Gabarites = {" << obj.xDim() << " " << obj.yDim() << "} " << \
  " Direction = " << obj.direction() << " Damage = " << obj.damage() << " Velocity = " << obj.velocity() << "\n";
  return os;
}
