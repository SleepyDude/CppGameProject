#include "obstacle.h"

Obstacle::Obstacle(float hp)
  : m_hp(hp)
{}

Obstacle::Obstacle(Point2D const & position, Point2D const & dimension, float hp)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_hp(hp)
{}

// Оператор логического равенства.
bool Obstacle::operator == (Obstacle const & obj) const
{
  return (Box() == obj.Box()) && (m_hp == obj.m_hp);
}

// Метод получения значения здоровья
float const & Obstacle::hp() const { return m_hp; }

// Метод установки значения hp
void Obstacle::SetHp(float hp) { m_hp = hp; }

void Obstacle::Update()
{
  printf("I am obstacle\n");
}
