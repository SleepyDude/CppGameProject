#include "gtest/gtest.h"
#include "ray2d.h"
#include "box2d.h"

TEST(ray2d_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Ray2D r1;
  Point2D pt1_1 = { 0.0f, 0.0f }, pt1_2 = { 0.0f, 1.0f };
  EXPECT_EQ(r1.origin(),pt1_1);
  EXPECT_EQ(r1.direction(),pt1_2);

  // Тест на создание объекта с параметрами.
  Point2D pt2_1 = { 1.5f, 2.2f }, pt2_2 = { 11.3f, 5.7f };
  Ray2D r2(pt2_1,pt2_2);
  EXPECT_EQ(r2.origin(), pt2_1);
  EXPECT_EQ(r2.direction(), pt2_2);

  //Тест конструктора копирования
  Ray2D r3(r2);
  EXPECT_EQ(r3,r2);

  //Тест на создание объекта по 4м числам origin_x origin_y direction_x direction_y
  Ray2D r4(1.25f,6.5f,2.3f,7.2f);
  Point2D pt4_1 = { 1.25f, 6.5f }, pt4_2 = { 2.3f, 7.2f };
  EXPECT_EQ(r4.origin(), pt4_1);
  EXPECT_EQ(r4.direction(), pt4_2);
}

TEST(ray2d_test, test_equality)
{
  // Тест на равенство
  Ray2D r5_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt5_1 = { 1.43f, 5.65f }, pt5_2 = { 7.13f, 12.2f };
  Ray2D r5_2 = { pt5_1, pt5_2 };
  EXPECT_EQ(r5_1,r5_2);
}

TEST(ray2d_test, test_non_equality)
{
  // Тест на неравенство
  Ray2D r6_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt6_1 = { 1.43f, 5.75f }, pt6_2 = { 7.13f, 12.2f };
  Ray2D r6_2 = { pt6_1, pt6_2 };
  EXPECT_NE(r6_1,r6_2);
}

TEST(ray2d_test, test_square_brackets)
{
  // Тест на использование квадратных скобок
  Ray2D r7_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt7_1 = { 1.43f, 5.65f }, pt7_2 = { 7.13f, 12.2f }, pt7_3;
  EXPECT_EQ(r7_1[0],pt7_1);
  EXPECT_EQ(r7_1[1],pt7_2);
  EXPECT_EQ(r7_1[2],pt7_3);
}

TEST(ray2d_test, test_Intersect_segment)
{
  // Тест на пересечение луча и отрезка
  Ray2D r8_1 = { 5.0f, 2.0f, -2.0f, -1.0f };
  Point2D pt8_1 = { -5.0f, 0.0f }, pt8_2 = { 0.0f, -4.0f },
          pt8_3 = { -3.0f, 1.0f }, pt8_4 = { -1.0f, 3.0f },
          pt8_5 = { 2.0f, -4.0f }, pt8_6 = { 2.0f, 2.0f },
          pt8_7 = { -2.0f, -2.0f }, pt8_8 = { -1.0f, 1.0f },
          pt8_9 = { 6.0f, 2.0f }, pt8_10 = { 7.0f, 5.0f };
  EXPECT_EQ(r8_1.Intersect(pt8_1,pt8_2),true);
  EXPECT_EQ(r8_1.Intersect(pt8_3,pt8_4),false);
  EXPECT_EQ(r8_1.Intersect(pt8_5,pt8_6),true);
  EXPECT_EQ(r8_1.Intersect(pt8_7,pt8_8),true);
  EXPECT_EQ(r8_1.Intersect(pt8_9,pt8_10),false);
}

TEST(ray2d_test, test_Intersect_box2d)
{
  // Тест на пересечение луча и бокса
  Ray2D r9_1 = { 2.0f, -3.0f, -1.0f, 2.0f };
  Box2D b9_1 = { -2.0f, 4.0f, 2.0f, 7.0f },
        b9_2 = { 3.0f, -5.0f, 5.0f, -3.0f },
        b9_3 = { 1.0f, -4.0f, 3.0f, -1.0f },
        b9_4 = { -6.0f, 3.0f, -3.0f, 6.0f },
        b9_5 = { -4.0f, -4.0f, -2.0f, -1.0f },
        b9_6 = { -2.0f, 2.0f, 3.0f, 3.0f };
  EXPECT_EQ( r9_1 % b9_1 ,true);
  EXPECT_EQ( r9_1 % b9_2 ,false);
  EXPECT_EQ( r9_1 % b9_3 ,true);
  EXPECT_EQ( r9_1 % b9_4 ,false);
  EXPECT_EQ( r9_1 % b9_5 ,false);
  EXPECT_EQ( r9_1 % b9_6 ,true);
}

TEST(ray2d_test, test_move_semantic)
{
  // Тест на конструктор перемещения
  Box2D r10_1 = { 3.33f, 4.12f, 6.41f, 8.14f };
  Box2D r10_2;
  Box2D r10_3(std::move(r10_1));
  Box2D r10_4 = { 3.33f, 4.12f, 6.41f, 8.14f };
  EXPECT_EQ(r10_3,r10_4);
  EXPECT_EQ(r10_2,r10_1);
}
