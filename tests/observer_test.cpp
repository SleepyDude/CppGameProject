#include "gtest/gtest.h"
#include "gun.h"
#include "bullet.h"
#include "box2d.h"
#include <string>

TEST(observer_test, test_gun)
{
  Bullet b1;
  Gun g1, g2, g3, g4;
  b1.Attach(&g1);
  g1.Move(0.1);
  b1.Attach(&g2);
  g2.Move(15.0);
  g3.Move(0.99);
  g4.Move(1.01);
  b1.Attach(&g3);
  b1.Attach(&g4);
  b1.Notify([](){ Logger::Instance() << "**Start notify\n ";}, b1.Box());
}
