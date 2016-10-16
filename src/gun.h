#pragma once

#include "gameentity.h"
#include "holder.h"

class Gun : public GameEntity
{
public:
  // Конструктор по умолчанию
  Gun();
  // Конструктор с двумя аргументами
  Gun(float rate, float hp);
  // Конструктор с 5ю аргументами
  Gun(Point2D pos, float xDim, float yDim, float rate, float hp);
  // Конструктор с 6ю аргументами
  Gun(float xPos, float yPos, float xDim, float yDim, float rate, float hp);

  // Перегрузка логического равенства
  bool operator == (Gun const & obj) const;

  // Методы для получения значений скорострельности и здоровья
  float const & rate() const;
  float const & hp() const;

  // Методы для получения значения кол-ва патронов
  unsigned int ammo() const;
  // Методы установки значений rate и hp
  void SetRate(float rate);
  void SetHp(float hp);

  // Метод смещения пушки влево или вправо
  void Move(float offset);

  // Метод стрельбы
  void Shot();

  void Update() override;
  ~Gun() override;
private:
  // Скорострельность и хилпоинты
  float m_rate = 1.0f , m_hp = 100.0f;
  Holder m_holder;
};
