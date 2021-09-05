/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibCollision2DTest
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Collision2D/Collision2D.hpp"

TEST(Collision2DTest, checkCollisionTrue)
{
    Raylib::Collision2D collision;
    Raylib::Rectangle rec1(10, 10, 10, 10);
    Raylib::Rectangle rec2(12, 10, 10, 10);


    EXPECT_EQ(collision.checkCollision(rec1, rec1), true);
}

TEST(Collision2DTest, checkCollisionFalse)
{
    Raylib::Collision2D collision;
    Raylib::Rectangle rec1(10, 10, 10, 10);
    Raylib::Rectangle rec2(20, 20, 20, 20);


    EXPECT_EQ(collision.checkCollision(rec1, rec2), false);
}

TEST(Collision2DTest, checkCollisionVectorTrue)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, 1, vec1, 1), true);
}

TEST(Collision2DTest, checkCollisionVectorFalse)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(20, 20);

    EXPECT_EQ(collision.checkCollision(vec1, 1, vec2, 1), false);
}

TEST(Collision2DTest, checkCollisionVectorRadiusRecTrue)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Rectangle rec1(10, 10, 10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, 0, rec1), true);
}

TEST(Collision2DTest, checkCollisionVectorRadiusRecFalse)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(1, 1);
    Raylib::Rectangle rec1(20, 20, 2, 2);

    EXPECT_EQ(collision.checkCollision(vec1, 0, rec1), false);
}

TEST(Collision2DTest, checkCollisionVectorRecTrue)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Rectangle rec1(10, 10, 10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, rec1), true);
}

TEST(Collision2DTest, checkCollisionVectorRecFalse)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Rectangle rec1(20, 20, 10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, rec1), false);
}

TEST(Collision2DTest, checkCollisionVectorRadiusTrue)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, vec2, 1), true);
}

TEST(Collision2DTest, checkCollisionVectorRadiusFalse)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(20, 20);

    EXPECT_EQ(collision.checkCollision(vec1, vec2, 1), false);
}

TEST(Collision2DTest, checkCollision4Vector2False)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(20, 20);
    Raylib::Vector2 vec3(10, 10);
    Raylib::Vector2 vec4(10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, vec2, vec3, vec4), false);
}

TEST(Collision2DTest, checkCollision5Vector2True)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(20, 20);
    Raylib::Vector2 vec3(10, 10);
    Raylib::Vector2 vec4(20, 20);
    Raylib::Vector2 vec5(10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, vec2, vec3, vec4), false);
}

TEST(Collision2DTest, checkCollision5Vector2False)
{
    Raylib::Collision2D collision;
    Raylib::Vector2 vec1(10, 10);
    Raylib::Vector2 vec2(20, 20);
    Raylib::Vector2 vec3(10, 10);
    Raylib::Vector2 vec4(10, 10);
    Raylib::Vector2 vec5(10, 10);

    EXPECT_EQ(collision.checkCollision(vec1, vec2, vec3, vec4), false);
}