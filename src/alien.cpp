#include "alien.h"

// Конструктор без параметров
Alien::Alien()
  : GameEntity()
{}
// Конструктор с тремя аргументами
Alien::Alien(float rate, float hp, float velocity)
  : m_rate(rate), m_hp(hp), m_velocity(velocity)
{}
// Конструктор с 6ю аргументами
Alien::Alien(Point2D pos, float xDim, float yDim, float rate, float hp, float velocity)
  : GameEntity(pos, xDim, yDim), m_rate(rate), m_hp(hp), m_velocity(velocity)
{}
// Конструктор с 7ю аргументами
Alien::Alien(float xPos, float yPos, float xDim, float yDim, float rate, float hp, float velocity)
  : GameEntity(xPos, yPos, xDim, yDim), m_rate(rate), m_hp(hp), m_velocity(velocity)
{}

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
void Alien::SetRate(float rate) { m_rate = rate; }
void Alien::SetHp(float hp) { m_hp = hp; }
void Alien::SetAmmo(unsigned int ammo) { m_holder.SetAmmo(ammo); }
void Alien::SetVelocity(float velocity) { m_velocity = velocity; }

// Метод смещения пришельца вверх и вниз
void Alien::Move(float offset)
{
  this->GameEntity::Move( { 0.0f, offset } );
}
// Метод стрельбы
void Alien::Shot()
{
  m_holder--;
}
void Alien::Update()
{}

Alien::~Alien()
{}
