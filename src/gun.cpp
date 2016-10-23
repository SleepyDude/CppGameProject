#include "gun.h"

Gun::Gun(float rate, float hp)
  : m_rate(rate), m_hp(hp)
{
  if (rate <= 0 || hp <= 0)
  {
    throw std::invalid_argument("rate and hp must be positive");
  }
}

Gun::Gun(Point2D const & position, Point2D const & dimension, float rate, float hp)
  : GameEntity(position.x(), position.y(), dimension.x(), dimension.y()), m_rate(rate), m_hp(hp)
{
  if (rate <= 0 || hp <= 0)
  {
    throw std::invalid_argument("rate and hp must be positive");
  }
}

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
void Gun::SetRate(float rate)
{
  if (rate <= 0)
  {
    throw std::invalid_argument("rate must be positive");
  }
  m_rate = rate;
}
void Gun::SetHp(float hp)
{
  if (hp <= 0)
  {
    throw std::invalid_argument("hp must be positive");
  }
  m_hp = hp;
}
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

std::ostream & operator << (std::ostream & os, Gun const & obj)
{
  os << "**Gun** Position = {" << obj.position().x() << " " << obj.position().y() << "} " << "Gabarites = {" << obj.xDim() << " " << obj.yDim() << "} " << "HP = " << obj.hp() << \
  " Rate = " << obj.rate() << " Ammo = " << obj.ammo() << "\n";
  return os;
}
