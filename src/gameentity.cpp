#include "gameentity.h"

GameEntity::GameEntity(Point2D const & pos, float xDim, float yDim)
  : m_box(pos.x(), pos.y(), pos.x() + xDim, pos.y() + yDim)
{
  if (xDim <= 0 || yDim <= 0)
  {
    throw std::invalid_argument("dimension must be positive");
  }
}

GameEntity::GameEntity(float xPos, float yPos, float xDim, float yDim)
  : m_box(xPos, yPos, xPos + xDim, yPos + yDim)
{
  if (xDim <= 0 || yDim <= 0)
  {
    throw std::invalid_argument("dimension must be positive");
  }
}

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

void GameEntity::Scale(float factorW,float factorH)
{
  if (factorW <= 0 || factorH <= 0)
  {
    throw std::invalid_argument("scale factor must be positive");
  }
  Point2D dim = { xDim()*factorW, yDim()*factorH };
  m_box.SetMax(m_box.boxMin() + dim);
}

void GameEntity::SetDimension(float width, float height)
{
  m_box.SetMax({width, height});
}

void GameEntity::SetPosition(float x, float y)
{
  m_box.SetPosition({x, y});
}
