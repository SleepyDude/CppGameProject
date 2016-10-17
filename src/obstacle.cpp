#include "obstacle.h"

// Конструктор без параметров
Obstacle::Obstacle()
  : GameEntity()
{}
// Конструктор с одним аргументом
Obstacle::Obstacle(float hp)
  : m_hp(hp)
{}
// Конструктор с 4мя аргументами
Obstacle::Obstacle(Point2D pos, float xDim, float yDim, float hp)
  : GameEntity(pos, xDim, yDim), m_hp(hp)
{}
// Конструктор с 5ю аргументами
Obstacle::Obstacle(float xPos, float yPos, float xDim, float yDim, float hp)
  : GameEntity(xPos, yPos, xDim, yDim), m_hp(hp)
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

Obstacle::~Obstacle()
{}
