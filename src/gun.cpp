#include "gun.h"

Gun::Gun(float rate, float hp)
  : m_rate(rate), m_hp(hp)
{}

Gun::Gun(Point2D const & position, Point2D const & dimension, float rate, float hp)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_rate(rate), m_hp(hp)
{}

// Оператор логического равенства.
bool Gun::operator == (Gun const & obj) const
{
  return (Box() == obj.Box()) && (m_rate == obj.m_rate) && (m_hp == obj.m_hp);
}

// Методы для получения значений скорострельности и здоровья
float const & Gun::rate() const { return m_rate; }
float const & Gun::hp() const { return m_hp; }
// Методы для получения значения кол-ва патронов
unsigned int Gun::ammo() const { return m_holder.ammo(); }

// Методы установки значений rate и hp и ammo
void Gun::SetRate(float rate) { m_rate = rate; }
void Gun::SetHp(float hp) { m_hp = hp; }
void Gun::SetAmmo(unsigned int ammo) { m_holder.SetAmmo(ammo); }

// Метод смещения пушки влево или вправо
void Gun::Move(float offset)
{
  GameEntity::Move( { offset, 0.0f } );
}
// Метод стрельбы
void Gun::Shot()
{
  m_holder--;
}
void Gun::Update()
{
  printf("I am gun\n");
}
