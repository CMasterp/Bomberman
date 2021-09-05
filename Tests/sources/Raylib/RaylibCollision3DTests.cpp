/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibCollision3DTest
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Collision3D/Collision3D.hpp"

TEST(Collision3DTest, checkCollisionTrue)
{
    Raylib::Collision3D collision;
    Raylib::Vector3 vec(10, 10, 10);
    Raylib::Vector3 vec2(10, 10, 10);

    EXPECT_EQ(collision.checkCollision(vec, 1, vec2, 1), true);
}

TEST(Collision3DTest, checkCollisionFalse)
{
    Raylib::Collision3D collision;
    Raylib::Vector3 vec(10, 10, 10);
    Raylib::Vector3 vec2(20, 20, 20);

    EXPECT_EQ(collision.checkCollision(vec, 1, vec2, 1), false);
}

TEST(Collision3DTest, checkCollisionBoundingBoxTrue)
{
    Raylib::Collision3D collision;
    ::BoundingBox box;
    ::BoundingBox box2;

    box.min = Raylib::Vector3(0, 0, 0).getCStruct();
    box.max = Raylib::Vector3(20, 20, 20).getCStruct();
    box2.min = Raylib::Vector3(0, 0, 0).getCStruct();
    box2.max = Raylib::Vector3(10, 10, 10).getCStruct();

    EXPECT_EQ(collision.checkCollision(box, box2), true);
}

TEST(Collision3DTest, checkCollisionBoundingBoxFalse)
{
    Raylib::Collision3D collision;
    ::BoundingBox box;
    ::BoundingBox box2;

    box.min = Raylib::Vector3(3, 3, 3).getCStruct();
    box.max = Raylib::Vector3(5, 5, 5).getCStruct();
    box2.min = Raylib::Vector3(6, 6, 6).getCStruct();
    box2.max = Raylib::Vector3(10, 10, 10).getCStruct();

    EXPECT_EQ(collision.checkCollision(box, box2), false);
}

TEST(Collision3DTest, checkCollisionBoundingBoxVectorTrue)
{
    Raylib::Collision3D collision;
    ::BoundingBox box;
    Raylib::Vector3 vec(10, 10, 10);

    box.min = Raylib::Vector3(3, 3, 3).getCStruct();
    box.max = Raylib::Vector3(20, 20, 20).getCStruct();

    EXPECT_EQ(collision.checkCollision(box, vec, 0), true);
}

TEST(Collision3DTest, checkCollisionBoundingBoxVectorFalse)
{
    Raylib::Collision3D collision;
    ::BoundingBox box;
    Raylib::Vector3 vec(10, 10, 10);

    box.min = Raylib::Vector3(3, 3, 3).getCStruct();
    box.max = Raylib::Vector3(5, 5, 5).getCStruct();

    EXPECT_EQ(collision.checkCollision(box, vec, 0), false);
}

TEST(Collision3DTest, checkCollisionRayVectorTrue)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    Raylib::Vector3 vec(10, 10, 10);

    ray.position = Raylib::Vector3(3, 3, 3).getCStruct();
    ray.direction = Raylib::Vector3(5, 5, 5).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, vec, 0), true);
}

TEST(Collision3DTest, checkCollisionRayVectorFalse)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    Raylib::Vector3 vec(2, 2, 2);

    ray.position = Raylib::Vector3(3, 3, 3).getCStruct();
    ray.direction = Raylib::Vector3(5, 5, 5).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, vec, 0), true);
}

TEST(Collision3DTest, checkCollisionRay2VectorTrue)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    Raylib::Vector3 vec(2, 2, 2);
    Raylib::Vector3 vec2(2, 2, 2);

    ray.position = Raylib::Vector3(3, 3, 3).getCStruct();
    ray.direction = Raylib::Vector3(5, 5, 5).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, vec, 0, vec2), true);
}

TEST(Collision3DTest, checkCollisionRay2VectorFalse)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    Raylib::Vector3 vec(2, 2, 2);
    Raylib::Vector3 vec2(10, 10, 10);

    ray.position = Raylib::Vector3(0, 0, 0).getCStruct();
    ray.direction = Raylib::Vector3(0, 0, 0).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, vec, 0, vec2), false);
}

TEST(Collision3DTest, checkCollisionRayBoundingBoxTrue)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    ::BoundingBox box;

    box.min = Raylib::Vector3(3, 3, 3).getCStruct();
    box.max = Raylib::Vector3(5, 5, 5).getCStruct();
    ray.position = Raylib::Vector3(0, 0, 0).getCStruct();
    ray.direction = Raylib::Vector3(0, 0, 0).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, box), true);
}

TEST(Collision3DTest, checkCollisionRayBoundingBoxFalse)
{
    Raylib::Collision3D collision;
    ::Ray ray;
    ::BoundingBox box;

    box.min = Raylib::Vector3(10, 10, 10).getCStruct();
    box.max = Raylib::Vector3(15, 15, 15).getCStruct();
    ray.position = Raylib::Vector3(0, 0, 0).getCStruct();
    ray.direction = Raylib::Vector3(0, 0, 0).getCStruct();

    EXPECT_EQ(collision.checkCollision(ray, box), true);
}