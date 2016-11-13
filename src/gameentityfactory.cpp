#include "gameentityfactory.h"

bool GameEntityFactory::Register(std::unique_ptr<GameEntity> && entity)
{
  if (m_templates.find(entity->GetType()) != m_templates.end())
    return false;

  m_templates[entity->GetType()] = std::move(entity);
  return true;
}

void GameEntityFactory::Unregister(std::unique_ptr<GameEntity> const & entity)
{
  m_templates[entity->GetType()] = nullptr;
}

std::unique_ptr<GameEntity> GameEntityFactory::Create(FactoryType type)
{
  if (m_templates.find(type) == m_templates.end())
    return nullptr;
  return m_templates[type]->Create();
}
