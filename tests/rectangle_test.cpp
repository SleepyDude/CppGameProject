#include "gtest/gtest.h"
#include "rectangle.h"

TEST(rectangle_test, test_rect_construction)
{
  // Тест на создание объекта по умолчанию.
  Rectangle r1;
  Point2D pt1_1 = { 0.0f, 0.0f }, pt1_2 = { 1.0f, 1.0f };
  EXPECT_EQ(r1.p1(),pt1_1);
  EXPECT_EQ(r1.p2(),pt1_2);

  // Тест на создание объекта с параметрами.
  Point2D pt2_1 = { 1.5f, 2.2f }, pt2_2 = { 11.3f, 5.7f };
  Rectangle r2(pt2_1,pt2_2);
  EXPECT_EQ(r2.p1(), pt2_1);
  EXPECT_EQ(r2.p2(), pt2_2);

  // Тест на создание копии объекта.
  Rectangle r3(r2);
  EXPECT_EQ(r3, r2);
}

TEST(rectangle_test, test_4th_constructor)
{
  //Тест на создание объекта по 4м числам x1 y1 x2 y2
  Rectangle r4(1.25f,6.5f,2.3f,7.2f);
  Point2D pt4_1 = { 1.25f, 6.5f }, pt4_2 = { 2.3f, 7.2f };
  EXPECT_EQ(r4.p1(), pt4_1);
  EXPECT_EQ(r4.p2(), pt4_2);
}


TEST(rectangle_test, test_rect_equality)
{
  // Тест на равенство
  Rectangle r5_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt5_1 = { 1.43f, 5.65f }, pt5_2 = { 7.13f, 12.2f };
  Rectangle r5_2 = { pt5_1, pt5_2 };
  EXPECT_EQ(r5_1,r5_2);
}

TEST(rectangle_test, test_rect_non_equality)
{
  // Тест на неравенство
  Rectangle r6_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt6_1 = { 1.43f, 5.75f }, pt6_2 = { 7.13f, 12.2f };
  Rectangle r6_2 = { pt6_1, pt6_2 };
  EXPECT_NE(r6_1,r6_2);
}

TEST(rectangle_test, test_rect_square_brackets)
{
  // Тест на использование квадратных скобок
  Rectangle r7_1 = { 1.43f, 5.65f, 7.13f, 12.2f };
  Point2D pt7_1 = { 1.43f, 5.65f }, pt7_2 = { 7.13f, 12.2f }, pt7_3;
  EXPECT_EQ(r7_1[0],pt7_1);
  EXPECT_EQ(r7_1[1],pt7_2);
  EXPECT_EQ(r7_1[2],pt7_3);
}

TEST(rectangle_test, test_rect_intersection)
{
  // Тест на пересечение
  Rectangle r8_1 = { 0.1f, 0.3f, 2.6f, 2.1f };
  Rectangle r8_2 = { 6.1f, 1.1f, 12.5f, 6.6f };
  Rectangle r8_3 = { 11.0f, 4.7f, 12.2f, 9.9f };
  Rectangle r8_4 = { 11.4f, 2.1f, 17.2f, 4.0f };
  Rectangle r8_5 = { 4.1f, 3.1f, 9.0f, 8.0f };
  Rectangle r8_6 = { 4.2f, 9.5f, 9.7f, 12.6f };
  Rectangle r8_7 = { 3.3f, 8.9f, 10.6f, 14.2f };
  Rectangle r8_8 = { 15.6f, 0.9f, 21.0f, 6.1f };
  Rectangle r8_9 = { 13.1f, 0.7f, 14.9f, 6.3f };

  EXPECT_EQ(r8_1 % r8_2,false);
  EXPECT_EQ(r8_6 % r8_7,true);
  EXPECT_EQ(r8_4 % r8_9,true);
  EXPECT_EQ(r8_4 % r8_8,true);
  EXPECT_EQ(r8_2 % r8_6,false);
  EXPECT_EQ(r8_2 % r8_3,true);
  EXPECT_EQ(r8_2 % r8_5,true);
  EXPECT_EQ(r8_3 % r8_4,false);
  EXPECT_EQ(r8_2 % r8_4,true);
}



