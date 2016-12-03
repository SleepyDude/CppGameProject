#include "space.h"

// Методы для получения значений положения и габаритов
Point2D const & Space::position() const { return m_box.boxMin(); }
float Space::xDim() const { return ( m_box.boxMax() - m_box.boxMin() ).x(); }
float Space::yDim() const { return ( m_box.boxMax() - m_box.boxMin() ).y(); }
Box2D const & Space::Box() const { return m_box; }

std::list<GameEntity*> const & Space::List() const
{
  return m_list;
}

void Space::Add(GameEntity* element)
{
  m_list.push_back(element);
}

void Space::AddBullet()
{
  m_factory.Register(Bullet().Create());
  m_bullets.push_back(m_factory.Create(FactoryType::BulletType));
}

void Space::Update()
{
  for(auto it = m_list.begin(); it != m_list.end(); ++it)
  {
    (*it)->Update();
  }
}

Gun & Space::SpaceGun() { return m_gun; }

void Space::SetDimension(float width, float height)
{
  m_gun.Scale( width / xDim(), height / yDim() );
  m_gun.SetPosition(m_gun.position().x() * width / xDim(),m_gun.position().y() * height / yDim());
  m_box.SetMax( {width, height} );
}
