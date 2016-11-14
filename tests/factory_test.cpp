#include "gtest/gtest.h"

#include "gun.h"
#include "obstacle.h"
#include "bullet.h"
#include "alien.h"
#include "logger.h"
#include "gameentityfactory.h"

template<typename TDerived, typename TBase>
std::unique_ptr<TDerived> static_unique_ptr_cast(std::unique_ptr<TBase> && p)
{
  return std::unique_ptr<TDerived>(static_cast<TDerived *>(p.release()));
}

TEST(factory_test, test_construction)
{
  // Тест на создание объектов
  try
  {
    GameEntityFactory factory;
    factory.Register(Gun().Create());
    auto gun1 = static_unique_ptr_cast<Gun>(factory.Create(FactoryType::GunType));
    auto gun2 = static_unique_ptr_cast<Gun>(factory.Create(FactoryType::GunType));
    gun1->SetHp(17);
    Logger::Instance() << *gun1;
    Logger::Instance() << *gun2;

    factory.Register(Bullet().Create());
    auto bullet1 = static_unique_ptr_cast<Bullet>(factory.Create(FactoryType::BulletType));
    auto bullet2 = static_unique_ptr_cast<Bullet>(factory.Create(FactoryType::BulletType));
    bullet1->SetVelocity(42);
    Logger::Instance() << *bullet1;
    Logger::Instance() << *bullet2;

    factory.Register(Alien().Create());
    auto alien1 = static_unique_ptr_cast<Alien>(factory.Create(FactoryType::AlienType));
    auto alien2 = static_unique_ptr_cast<Alien>(factory.Create(FactoryType::AlienType));
    alien1->SetRate(42);
    Logger::Instance() << *alien1;
    Logger::Instance() << *alien2;

    factory.Register(Obstacle().Create());
    auto obstacle1 = static_unique_ptr_cast<Obstacle>(factory.Create(FactoryType::ObstacleType));
    auto obstacle2 = static_unique_ptr_cast<Obstacle>(factory.Create(FactoryType::ObstacleType));
    obstacle1->SetHp(42);
    Logger::Instance() << *obstacle1;
    Logger::Instance() << *obstacle2;

    factory.Unregister(Gun().Create());
    factory.Unregister(Alien().Create());
    factory.Unregister(Bullet().Create());
    factory.Unregister(Obstacle().Create());
  }
  catch(std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}
