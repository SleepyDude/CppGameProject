#include "obstacle.h"

Obstacle::Obstacle(float hp)
  : m_hp(hp)
{
  if (hp <= 0)
  {
    throw std::invalid_argument("hp must be positive");
  }
}

Obstacle::Obstacle(Point2D const & position, Point2D const & dimension, float hp)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_hp(hp)
{
  if (hp <= 0)
  {
    throw std::invalid_argument("hp must be positive");
  }
}

// Оператор логического равенства.
bool Obstacle::operator == (Obstacle const & obj) const
{
  return (Box() == obj.Box()) && (m_hp == obj.m_hp);
}

// Метод получения значения здоровья
float const & Obstacle::hp() const { return m_hp; }

// Метод установки значения hp
void Obstacle::SetHp(float hp)
{
  if (hp <= 0)
  {
    throw std::invalid_argument("hp must be positive");
  }
  m_hp = hp;
}

void Obstacle::Update()
{
  printf("I am obstacle\n");
}

std::ostream & operator << (std::ostream & os, Obstacle const & obj)
{
  os << "**Obstacle** Position = {" << obj.position().x() << " " << obj.position().y() << "} " << "Gabarites = {" << obj.xDim() << " " << obj.yDim() << "} " << "HP = " << obj.hp() << std::endl;
  return os;
}
