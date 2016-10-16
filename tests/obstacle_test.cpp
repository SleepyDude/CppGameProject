#include "gtest/gtest.h"
#include "obstacle.h"

TEST(obstacle_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Obstacle o1;
  Point2D pt_1;
  EXPECT_EQ(o1.xDim(), 1.0f);
  EXPECT_EQ(o1.yDim(), 1.0f);
  EXPECT_EQ(o1.position(), pt_1);
  EXPECT_EQ(o1.hp(), 1000.0f);

  // Тест конструктора с одним аргументом
  Obstacle o2(150);
  EXPECT_EQ(o2.xDim(), 1.0f);
  EXPECT_EQ(o2.yDim(), 1.0f);
  EXPECT_EQ(o2.position(), pt_1);
  EXPECT_EQ(o2.hp(), 150.0f);

  // Тест конструктора с 4мя аргументами
  Point2D pt_2 = { 4.0f, 7.0f };
  Obstacle o3(pt_2, 3, 4, 150);
  EXPECT_EQ(o3.xDim(), 3.0f);
  EXPECT_EQ(o3.yDim(), 4.0f);
  EXPECT_EQ(o3.position(), pt_2);
  EXPECT_EQ(o3.hp(), 150.0f);

  // Тест конструктора с 5ю аргументами
  Obstacle o4(4, 7, 3, 4, 180);
  EXPECT_EQ(o4.xDim(), 3.0f);
  EXPECT_EQ(o4.yDim(), 4.0f);
  EXPECT_EQ(o4.position(), pt_2);
  EXPECT_EQ(o4.hp(), 180.0f);
}

TEST(obstacle_test, test_equal)
{
  // Тест на логическое равенство
  Obstacle o1 = { 1, 2, 3, 4, 50 };
  Obstacle o2 = { 1, 2, 3, 4, 50 };
  EXPECT_EQ(o1, o2);
}

TEST(obstacle_test, test_Scale)
{
  // Тест на масштабирование
  Obstacle o1;
  float f1 = 3.0f;
  o1.Scale(f1);
  Obstacle o2(0, 0, 3, 3, 1000);
  EXPECT_EQ(o2, o1);
}

TEST(obstacle_test, test_set)
{
  // Тест на Set методы
  Obstacle o1;
  o1.SetHp(60);
  Obstacle o2(60);
  EXPECT_EQ(o2, o1);
}
