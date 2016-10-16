#include "gtest/gtest.h"
#include "gun.h"

TEST(gun_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Gun g1;
  Point2D pt_1;
  EXPECT_EQ(g1.xDim(), 1.0f);
  EXPECT_EQ(g1.yDim(), 1.0f);
  EXPECT_EQ(g1.position(), pt_1);
  EXPECT_EQ(g1.rate(), 1.0f);
  EXPECT_EQ(g1.hp(), 100.0f);

  // Тест конструктора с 2мя аргументами
  Gun g2(15, 150);
  EXPECT_EQ(g2.xDim(), 1.0f);
  EXPECT_EQ(g2.yDim(), 1.0f);
  EXPECT_EQ(g2.position(), pt_1);
  EXPECT_EQ(g2.rate(), 15.0f);
  EXPECT_EQ(g2.hp(), 150.0f);

  // Тест конструктора с 5ю аргументами
  Point2D pt_2 = { 4.0f, 7.0f };
  Gun g3(pt_2, 3, 4, 15, 150);
  EXPECT_EQ(g3.xDim(), 3.0f);
  EXPECT_EQ(g3.yDim(), 4.0f);
  EXPECT_EQ(g3.position(), pt_2);
  EXPECT_EQ(g3.rate(), 15.0f);
  EXPECT_EQ(g3.hp(), 150.0f);

  // Тест конструктора с 6ю аргументами
  Gun g4(4, 7, 3, 4, 40, 180);
  EXPECT_EQ(g4.xDim(), 3.0f);
  EXPECT_EQ(g4.yDim(), 4.0f);
  EXPECT_EQ(g4.position(), pt_2);
  EXPECT_EQ(g4.rate(), 40.0f);
  EXPECT_EQ(g4.hp(), 180.0f);
}
/*
TEST(gun_test, test_Move)
{
  Gun g1;
  Point2D p1 = { 4.0f, -3.0f };
  g1.Move(p1);
  Gun g2(p1, 1, 1);
  EXPECT_EQ(g2, 180.0f);
}
*/
