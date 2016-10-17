#include "gtest/gtest.h"

#include "space.h"
#include "gun.h"
#include "obstacle.h"

TEST(space_test, test_constructor)
{
  // Тест на создание объекта по умолчанию.
  Space s1;
  Point2D pt_1 = { -1, -1 };
  EXPECT_EQ(s1.xDim(), 21.0f);
  EXPECT_EQ(s1.yDim(), 51.0f);
  EXPECT_EQ(s1.position(), pt_1);
  EXPECT_EQ(s1.List().size(), 0);
}

TEST(space_test, test_add)
{
  // Тест на добавление сущностей.
  Space s1;
  Gun g1, g2, g3, g4;
  Obstacle o1, o2, o3;

  s1.Add(&g1);
  EXPECT_EQ(s1.List().size(), 1);
  s1.Add(&o1);
  s1.Add(&g2);
  s1.Add(&o2);
  s1.Add(&g3);
  s1.Add(&o3);
  s1.Add(&g4);
  EXPECT_EQ(s1.List().size(), 7);
  s1.Update();
}
