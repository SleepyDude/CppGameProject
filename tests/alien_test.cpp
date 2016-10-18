#include "gtest/gtest.h"
#include "alien.h"

TEST(alien_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  try
  {
    Alien a1;
    Point2D pt_1;
    EXPECT_EQ(a1.xDim(), 1.0f);
    EXPECT_EQ(a1.yDim(), 1.0f);
    EXPECT_EQ(a1.position(), pt_1);
    EXPECT_EQ(a1.rate(), 1.0f);
    EXPECT_EQ(a1.hp(), 10.0f);
    EXPECT_EQ(a1.ammo(), 20);
    EXPECT_EQ(a1.velocity(), 1);

    Alien a2(15, 150, 7);
    EXPECT_EQ(a2.xDim(), 1.0f);
    EXPECT_EQ(a2.yDim(), 1.0f);
    EXPECT_EQ(a2.position(), pt_1);
    EXPECT_EQ(a2.rate(), 15.0f);
    EXPECT_EQ(a2.hp(), 150.0f);
    EXPECT_EQ(a2.velocity(), 7);

    Point2D pt_2 = {4, 7};
    Alien a4({4, 7}, {3, 4}, 40, 180, 6);
    EXPECT_EQ(a4.xDim(), 3.0f);
    EXPECT_EQ(a4.yDim(), 4.0f);
    EXPECT_EQ(a4.position(), pt_2);
    EXPECT_EQ(a4.rate(), 40.0f);
    EXPECT_EQ(a4.hp(), 180.0f);
    EXPECT_EQ(a4.velocity(), 6);
  }
  catch(std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(alien_test, test_equal)
{
  // Тест на логическое равенство
  Alien a1 = { {1, 2}, {3, 4}, 10, 50, 6 };
  Alien a2 = { {1, 2}, {3, 4}, 10, 50, 6 };
  EXPECT_EQ(a1, a2);
}

TEST(alien_test, test_Move)
{
  // Тест на смещение ( вниз )
  Alien a1;
  a1.Move(-4);
  Alien a2({0, -4}, {1, 1}, 1, 10, 1);
  EXPECT_EQ(a2, a1);
}

TEST(alien_test, test_Scale)
{
  // Тест на масштабирование
  try
  {
    Alien a1;
    float f1 = 3.0f;
    a1.Scale(f1);
    Alien a2({0, 0}, {3, 3}, 1, 10, 1);
    EXPECT_EQ(a2, a1);
  }
  catch(std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(alien_test, test_set)
{
  // Тест на Set методы
  try
  {
    Alien a1;
    a1.SetRate(60);
    a1.SetHp(20);
    a1.SetVelocity(12);
    a1.SetAmmo(30);
    Alien a2(60, 20, 12);
    EXPECT_EQ(a2, a1);
  }
  catch(std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(alien_test, test_shot)
{
  // Тест на стрельбу
  Alien a1;
  a1.Shot();
  EXPECT_EQ(a1.ammo(), 19);
  a1.Shot();
  EXPECT_EQ(a1.ammo(), 18);
  a1.SetAmmo(1);
  EXPECT_EQ(a1.ammo(), 1);
  a1.Shot();
  EXPECT_EQ(a1.ammo(), 0);
  a1.Shot();
  EXPECT_EQ(a1.ammo(), 0);
}

TEST(alien_test, test_exceptions)
{
  Alien a2;
  ASSERT_THROW(Alien a1({4, 7}, {3, 4}, -40, 180, 6), std::invalid_argument);
  ASSERT_THROW(Alien a1({4, 7}, {3, 4}, 40, -180, 6), std::invalid_argument);
  ASSERT_THROW(Alien a1({4, 7}, {3, 4}, 40, 180, -6), std::invalid_argument);
  ASSERT_THROW(a2.SetAmmo(-3), std::invalid_argument);
  ASSERT_THROW(a2.Scale(-4.0);, std::invalid_argument);
}
