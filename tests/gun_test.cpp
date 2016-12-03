#include "gtest/gtest.h"
#include "gun.h"
#include "logger.h"

TEST(gun_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  try
  {
    Gun g1;
    Point2D pt_1;
    EXPECT_EQ(g1.xDim(), 1.0f);
    EXPECT_EQ(g1.yDim(), 1.0f);
    EXPECT_EQ(g1.position(), pt_1);
    EXPECT_EQ(g1.rate(), 1.0f);
    EXPECT_EQ(g1.hp(), 100.0f);
    EXPECT_EQ(g1.ammo(), 20);

    Gun g2(15, 150);
    EXPECT_EQ(g2.xDim(), 1.0f);
    EXPECT_EQ(g2.yDim(), 1.0f);
    EXPECT_EQ(g2.position(), pt_1);
    EXPECT_EQ(g2.rate(), 15.0f);
    EXPECT_EQ(g2.hp(), 150.0f);

    Point2D pt_2 = { 4.0f, 7.0f };
    Gun g4({4, 7}, {3, 4}, 40, 180);
    EXPECT_EQ(g4.xDim(), 3.0f);
    EXPECT_EQ(g4.yDim(), 4.0f);
    EXPECT_EQ(g4.position(), pt_2);
    EXPECT_EQ(g4.rate(), 40.0f);
    EXPECT_EQ(g4.hp(), 180.0f);
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(gun_test, test_equal)
{
  // Тест на логическое равенство
  try
  {
    Gun g1 = { {1, 2}, {3, 4}, 10, 50 };
    Gun g2 = { {1, 2}, {3, 4}, 10, 50 };
    EXPECT_EQ(g1, g2);
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(gun_test, test_Move)
{
  // Тест на смещение ( Влево или вправо )
  try
  {
    Gun g1;
    g1.Move(4);
    Gun g2({4, 0}, {1, 1}, 1, 100);
    EXPECT_EQ(g2, g1);
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(gun_test, test_Scale)
{
  // Тест на масштабирование
  try
  {
    Gun g1;
    float f1 = 3.0f;
    g1.Scale(f1, f1);
    Gun g2({0, 0}, {3, 3}, 1, 100);
    EXPECT_EQ(g2, g1);
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(gun_test, test_set)
{
  // Тест на Set методы
  try
  {
    Gun g1;
    g1.SetRate(60);
    g1.SetHp(20);
    Gun g2(60, 20);
    EXPECT_EQ(g2, g1);
  }
  catch (std::invalid_argument const & ex)
  {
    std::cerr << ex.what();
  }
}

TEST(gun_test, test_shot)
{
  // Тест на стрельбу
  Gun g1;
  g1.Shot();
  EXPECT_EQ(g1.ammo(), 19);
  g1.Shot();
  EXPECT_EQ(g1.ammo(), 18);
  g1.SetAmmo(1);
  EXPECT_EQ(g1.ammo(), 1);
  g1.Shot();
  EXPECT_EQ(g1.ammo(), 0);
  g1.Shot();
  EXPECT_EQ(g1.ammo(), 0);
}

TEST(gun_test, test_exceptions)
{
  Gun g1;
  EXPECT_THROW(Gun g2({0, 0}, {-3, 3}, 1, 100), std::invalid_argument);
  EXPECT_THROW(Gun g2({0, 0}, {3, -3}, 1, 100), std::invalid_argument);
  EXPECT_THROW(Gun g2({0, 0}, {3, 3}, -1, 100), std::invalid_argument);
  EXPECT_THROW(Gun g2({0, 0}, {3, 3}, 1, -100), std::invalid_argument);
  EXPECT_THROW(g1.SetAmmo(-6);, std::invalid_argument);
  EXPECT_THROW(g1.SetHp(-8);, std::invalid_argument);
  EXPECT_THROW(g1.SetRate(0);, std::invalid_argument);
}
