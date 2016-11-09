#include "gtest/gtest.h"
#include "gun.h"
#include "logger.h"
#include "obstacle.h"
#include "bullet.h"
#include "alien.h"
#include "box2d.h"
#include "ray2d.h"
#include "holder.h"
#include <list>

TEST(logger_test, test_gun)
{
  Gun g1;
  Logger::Instance() << g1;
}

TEST(logger_test, test_obstacle)
{
  Obstacle o1;
  Logger::Instance() << o1;
}

TEST(logger_test, test_bullet)
{
  Bullet b1;
  Logger::Instance() << b1;
}

TEST(logger_test, test_alien)
{
  Alien a1;
  Logger::Instance() << a1;
}

TEST(logger_test, test_ray)
{
  Ray2D r1;
  Logger::Instance() << r1;
}

TEST(logger_test, test_holder)
{
  Holder h1;
  Logger::Instance() << h1;
}

TEST(logger_test, test_box)
{
  Box2D b1;
  Logger::Instance() << b1;
}

TEST(logger_test, test_list)
{
  try
  {
    Gun g1;
    Gun g2(20,30);
    Gun g3({4, 7}, {3, 4}, 40, 180);
    std::list<Gun> gunList {g1, g2, g3};
    Logger::Instance() << gunList;
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}
