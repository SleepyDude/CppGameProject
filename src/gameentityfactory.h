#pragma once

#include "gameentity.h"
#include <unordered_map>

class GameEntityFactory
{
public:
  GameEntityFactory() = default;

  bool Register(std::unique_ptr<GameEntity> && entity);
  void Unregister(std::unique_ptr<GameEntity> const & entity);

  std::unique_ptr<GameEntity> Create(FactoryType type);

private:
  using Templates = std::unordered_map<int,std::unique_ptr<GameEntity>>;
  Templates m_templates;
};
