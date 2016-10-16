#include "gtest/gtest.h"
#include "bullet.h"

TEST(bullet_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Bullet b1;
  Point2D pt_1;
  Point2D pt_2 = { 0.0f, 1.0f };
  EXPECT_EQ(b1.xDim(), 1.0f);
  EXPECT_EQ(b1.yDim(), 1.0f);
  EXPECT_EQ(b1.position(), pt_1);
  EXPECT_EQ(b1.damage(), 1.0f);
  EXPECT_EQ(b1.velocity(), 1.0f);
  EXPECT_EQ(b1.direction(), pt_2);

  // Тест конструктора с тремя аргументами
  Point2D pt_3 = { 3.0f, 1.0f };
  Bullet b2 = { 10, 5, pt_3 };
  EXPECT_EQ(b2.xDim(), 1.0f);
  EXPECT_EQ(b2.yDim(), 1.0f);
  EXPECT_EQ(b2.position(), pt_1);
  EXPECT_EQ(b2.damage(), 10.0f);
  EXPECT_EQ(b2.velocity(), 5.0f);
  EXPECT_EQ(b2.direction(), pt_3);

  // Тест конструктора с 6ю аргументами
  Point2D pt_4 = { 4.0f, 7.0f };
  Bullet b3(pt_4, 3, 4, 10, 5, pt_3);
  EXPECT_EQ(b3.xDim(), 3.0f);
  EXPECT_EQ(b3.yDim(), 4.0f);
  EXPECT_EQ(b3.position(), pt_4);
  EXPECT_EQ(b2.damage(), 10.0f);
  EXPECT_EQ(b2.velocity(), 5.0f);
  EXPECT_EQ(b2.direction(), pt_3);

  // Тест конструктора с 7ю аргументами
  Bullet b4(4, 7, 3, 4, 10, 5, pt_3);
  EXPECT_EQ(b4.xDim(), 3.0f);
  EXPECT_EQ(b4.yDim(), 4.0f);
  EXPECT_EQ(b4.position(), pt_4);
  EXPECT_EQ(b2.damage(), 10.0f);
  EXPECT_EQ(b2.velocity(), 5.0f);
  EXPECT_EQ(b2.direction(), pt_3);
}

TEST(bullet_test, test_equal)
{
  Point2D pt_1 = { 3.0f, 1.0f };
  // Тест на логическое равенство
  Bullet b1 = { 1, 2, 3, 4, 10, 50, pt_1 };
  Bullet b2 = { 1, 2, 3, 4, 10, 50, pt_1 };
  EXPECT_EQ(b1, b2);
}

TEST(bullet_test, test_Move)
{
  // Тест на смещение
  Bullet b1;
  b1.SetDirection( { 2, 2 } );
  b1.Move();
  b1.Move();
  Bullet b2(sqrt(2), sqrt(2), 1, 1, 1, 1, { sqrt(2)/2, sqrt(2)/2 });
  EXPECT_EQ(b2, b1);
}

TEST(bullet_test, test_Scale)
{
  // Тест на масштабирование
  Bullet b1;
  float f1 = 3.0f;
  b1.Scale(f1);
  Bullet b2(0, 0, 3, 3, 1, 1, { 0.0f, 1.0f });
  EXPECT_EQ(b2, b1);
}

TEST(bullet_test, test_set)
{
  // Тест на Set методы
  Bullet b1;
  b1.SetDamage(60);
  b1.SetDirection({ 2, 3 });
  b1.SetVelocity(15);
  Bullet b2(60, 15, { 2, 3 });
  EXPECT_EQ(b2, b1);
}
