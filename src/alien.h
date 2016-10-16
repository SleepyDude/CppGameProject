#pragma once

#include "gameentity.h"
#include "holder.h"

class Alien: public GameEntity
{
public:
  // Конструктор по умолчанию
  Alien();
  // Конструктор с тремя аргументами
  Alien(float rate, float hp, float velocity);
  // Конструктор с 6ю аргументами
  Alien(Point2D pos, float xDim, float yDim, float rate, float hp, float velocity);
  // Конструктор с 7ю аргументами
  Alien(float xPos, float yPos, float xDim, float yDim, float rate, float hp, float velocity);

  // Перегрузка логического равенства
  bool operator == (Alien const & obj) const;

  // Методы для получения значений скорострельности и здоровья
  float const & rate() const;
  float const & hp() const;
  // Методы для получения значения кол-ва патронов
  unsigned int ammo() const;
  // Методы для получения значения скорости
  float const & velocity() const;

  // Методы установки значений
  void SetRate(float rate);
  void SetHp(float hp);
  void SetAmmo(unsigned int ammo);
  void SetVelocity(float velocity);

  // Метод смещения пушки влево или вправо
  void Move(float offset);

  // Метод стрельбы
  void Shot();

  void Update() override;
  ~Alien() override;
private:
  // Скорострельность и хилпоинты
  float m_rate = 1.0f , m_hp = 10.0f, m_velocity = 1.0f;
  Holder m_holder;
};
