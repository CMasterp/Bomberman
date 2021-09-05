/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibRectangleTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Rectangle/Rectangle.hpp"

TEST(RectangleTest, constructor)
{
    Raylib::Rectangle rectangle;

    EXPECT_EQ(0, rectangle.getCStruct().height);
    EXPECT_EQ(0, rectangle.getCStruct().width);
    EXPECT_EQ(0, rectangle.getCStruct().x);
    EXPECT_EQ(0, rectangle.getCStruct().y);
}

TEST(RectangleTest, copy_const)
{
    ::Rectangle rec1 = {1, 1, 1, 1};
    Raylib::Rectangle rectangle(rec1);

    EXPECT_EQ(rec1.height, rectangle.getCStruct().height);
    EXPECT_EQ(rec1.width, rectangle.getCStruct().width);
    EXPECT_EQ(rec1.x, rectangle.getCStruct().x);
    EXPECT_EQ(rec1.y, rectangle.getCStruct().y);
}

TEST(RectangleTest, copy_const2Vector2)
{
    Raylib::Rectangle rectangle(Raylib::Vector2(1, 1), Raylib::Vector2(2, 2));

    EXPECT_EQ(2, rectangle.getCStruct().height);
    EXPECT_EQ(2, rectangle.getCStruct().width);
    EXPECT_EQ(1, rectangle.getCStruct().x);
    EXPECT_EQ(1, rectangle.getCStruct().y);
}

TEST(RectangleTest, copy_constVector)
{
    Raylib::Rectangle rectangle(Raylib::Vector2(1, 1));

    EXPECT_EQ(1, rectangle.getCStruct().height);
    EXPECT_EQ(1, rectangle.getCStruct().width);
    EXPECT_EQ(0, rectangle.getCStruct().x);
    EXPECT_EQ(0, rectangle.getCStruct().y);
}

TEST(RectangleTest, operatorequal)
{
    Raylib::Rectangle rectangle(Raylib::Vector2(1, 1), Raylib::Vector2(2, 2));
    Raylib::Rectangle rectangle2 = rectangle;

    EXPECT_EQ(rectangle.getCStruct().height, rectangle2.getCStruct().height);
    EXPECT_EQ(rectangle.getCStruct().width, rectangle2.getCStruct().width);
    EXPECT_EQ(rectangle.getCStruct().x, rectangle2.getCStruct().x);
    EXPECT_EQ(rectangle.getCStruct().y, rectangle2.getCStruct().y);
}