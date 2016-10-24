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
  Logger log;
  Gun g1;
  log << g1;
}

TEST(logger_test, test_obstacle)
{
  Logger log;
  Obstacle o1;
  log << o1;
}

TEST(logger_test, test_bullet)
{
  Logger log;
  Bullet b1;
  log << b1;
}

TEST(logger_test, test_alien)
{
  Logger log;
  Alien a1;
  log << a1;
}

TEST(logger_test, test_ray)
{
  Logger log;
  Ray2D r1;
  log << r1;
}

TEST(logger_test, test_holder)
{
  Logger log;
  Holder h1;
  log << h1;
}

TEST(logger_test, test_box)
{
  Logger log;
  Box2D b1;
  log << b1;
}

TEST(logger_test, test_list)
{
  try
  {
    Logger log;
    Gun g1;
    Gun g2(20,30);
    Gun g3({4, 7}, {3, 4}, 40, 180);
    std::list<Gun> gunList {g1, g2, g3};
    log << gunList;
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}
