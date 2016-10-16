#pragma once

#include "gameentity.h"

class Obstacle: public GameEntity
{
public:
  // Конструктор по умолчанию
  Obstacle();
  // Конструктор с одним аргументом
  Obstacle(float hp);
  // Конструктор с 4мя аргументами
  Obstacle(Point2D pos, float xDim, float yDim, float hp);
  // Конструктор с 5ю аргументами
  Obstacle(float xPos, float yPos, float xDim, float yDim, float hp);

  // Перегрузка логического равенства
  bool operator == (Obstacle const & obj) const;

  // Метод получения значения здоровья
  float const & hp() const;

  // Метод установки значения hp
  void SetHp(float hp);

  void Update() override;
  ~Obstacle() override;
private:
  float m_hp = 1000.0f;
};
