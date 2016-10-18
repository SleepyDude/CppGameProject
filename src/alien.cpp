#include "alien.h"

Alien::Alien(float rate, float hp, float velocity)
  : m_rate(rate), m_hp(hp), m_velocity(velocity)
{
  if ( rate <= 0 || velocity < 0 || hp < 0 )
  {
    throw std::invalid_argument("rate, velocity and hp must be positive");
  }
}

Alien::Alien(Point2D const & position, Point2D const & dimension, float rate, float hp, float velocity)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_rate(rate), m_hp(hp), m_velocity(velocity)
{
  if ( rate <= 0 || velocity < 0 || hp < 0 )
  {
    throw std::invalid_argument("rate, velocity and hp must be positive");
  }
}

// Оператор логического равенства.
bool Alien::operator == (Alien const & obj) const
{
  return (Box() == obj.Box()) && (m_rate == obj.m_rate) && (m_hp == obj.m_hp) && (m_velocity == obj.m_velocity);
}

// Методы для получения значений скорострельности и здоровья
float const & Alien::rate() const { return m_rate; }
float const & Alien::hp() const { return m_hp; }
// Методы для получения значения кол-ва патронов
unsigned int Alien::ammo() const { return m_holder.ammo(); }
// Методы для получения значения скорости
float const & Alien::velocity() const { return m_velocity; }

// Методы установки значений
void Alien::SetRate(float rate)
{
  if ( rate <= 0 )
  {
    throw std::invalid_argument("rate must be positive");
  }
  m_rate = rate;
}
void Alien::SetHp(float hp)
{
  if ( hp <= 0 )
  {
    throw std::invalid_argument("hp must be positive");
  }
  m_hp = hp;
}
void Alien::SetAmmo(unsigned int ammo)
{
  m_holder.SetAmmo(ammo);
}
void Alien::SetVelocity(float velocity)
{
  if ( velocity < 0 )
  {
    throw std::invalid_argument("velocity must be positive");
  }
  m_velocity = velocity;
}

// Метод смещения пришельца вверх и вниз
void Alien::Move(float offset)
{
  GameEntity::Move( { 0.0f, offset } );
}
// Метод стрельбы
void Alien::Shot()
{
  m_holder--;
}
void Alien::Update()
{}
