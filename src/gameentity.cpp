#include "gameentity.h"

GameEntity::GameEntity(Point2D const & pos, float xDim, float yDim)
  : m_box(pos.x(), pos.y(), pos.x() + xDim, pos.y() + yDim)
{}

GameEntity::GameEntity(float xPos, float yPos, float xDim, float yDim)
  : m_box(xPos, yPos, xPos + xDim, yPos + yDim)
{}

// Методы для получения значений положения и габаритов
Point2D const & GameEntity::position() const { return m_box.boxMin(); }
float GameEntity::xDim() const { return ( m_box.boxMax() - m_box.boxMin() ).x(); }
float GameEntity::yDim() const { return ( m_box.boxMax() - m_box.boxMin() ).y(); }
Box2D const & GameEntity::Box() const { return m_box; }

GameEntity::~GameEntity()
{}

void GameEntity::Move(Point2D const & offset)
{
  m_box.Shift(offset);
}

void GameEntity::Scale(float factor)
{
  if ( factor <= 0 )
  {
    throw std::invalid_argument("scale factor must be positive");
  }
  m_box.SetMax(m_box.boxMin() + ( m_box.boxMax() - m_box.boxMin() ) * factor);
}
