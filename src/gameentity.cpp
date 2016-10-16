#include "gameentity.h"

// Конструктор по точке и 2м габаритам
GameEntity::GameEntity(Point2D pos, float xDim, float yDim)
  : m_position(pos), m_xDim(xDim), m_yDim(yDim)
{}
// Конструктор с четырмя аргументами
GameEntity::GameEntity(float xPos, float yPos, float xDim, float yDim)
  : m_position(xPos, yPos), m_xDim(xDim), m_yDim(yDim)
{}

// Методы для получения значений положения и габаритов
Point2D const & GameEntity::position() const { return m_position; }
float const & GameEntity::xDim() const { return m_xDim; }
float const & GameEntity::yDim() const { return m_yDim; }

GameEntity::~GameEntity()
{}

void GameEntity::Move(Point2D const & offset)
{
  m_position += offset;
}

void GameEntity::Scale(float factor)
{
  m_xDim *= factor;
  m_yDim *= factor;
}
/*
Box2D const & GameEntity::Box() const
{
  Point2D max = { m_position.x() + m_xDim, m_position.y() + m_yDim};
  m_box = {m_position, max};
  return m_box;
}
*/
