#include "gun.h"

// Конструктор без параметров
Gun::Gun()
  : GameEntity()
{}
// Конструктор с двумя аргументами
Gun::Gun(float rate, float hp)
  : m_rate(rate), m_hp(hp)
{}
// Конструктор с 5ю аргументами
Gun::Gun(Point2D pos, float xDim, float yDim, float rate, float hp)
  : GameEntity(pos, xDim, yDim), m_rate(rate), m_hp(hp)
{}
// Конструктор с 6ю аргументами
Gun::Gun(float xPos, float yPos, float xDim, float yDim, float rate, float hp)
  : GameEntity(xPos, yPos, xDim, yDim), m_rate(rate), m_hp(hp)
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
  this->GameEntity::Move( { offset, 0.0f } );
}
// Метод стрельбы
void Gun::Shot()
{
  m_holder--;
}
void Gun::Update()
{}

Gun::~Gun()
{}
