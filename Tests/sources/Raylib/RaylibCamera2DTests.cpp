/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibCamera2DTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Camera2D/Camera2D.hpp"
#include "../Tests/Lib/XRaylib/Raylib/Vector2/Vector2.hpp"

TEST(Camera2DTests, initCopyConstructor)
{
    ::Camera2D cameraC;

    cameraC.offset = Raylib::Vector2(0, 0).getCStruct();
    cameraC.target = Raylib::Vector2(0, 0).getCStruct();
    cameraC.rotation = 1;
    cameraC.zoom = 1;
    Raylib::Camera2D camera(cameraC);
    EXPECT_EQ(camera.getCStruct().offset.x, cameraC.offset.x);
    EXPECT_EQ(camera.getCStruct().offset.y, cameraC.offset.y);
    EXPECT_EQ(camera.getCStruct().target.x, cameraC.target.x);
    EXPECT_EQ(camera.getCStruct().target.y, cameraC.target.y);
    EXPECT_EQ(camera.getCStruct().rotation, cameraC.rotation);
    EXPECT_EQ(camera.getCStruct().zoom, cameraC.zoom);
}

TEST(Camera2DTests, getCameraMatrixTests)
{
    ::Camera2D cameraC;

    cameraC.offset = Raylib::Vector2(12, 12).getCStruct();
    cameraC.target = Raylib::Vector2(12, 12).getCStruct();
    cameraC.rotation = 1;
    cameraC.zoom = 1;
    Raylib::Camera2D camera(cameraC);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m0 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m1 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m2 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m3 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m4 >= 0, false);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m5 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m6 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m7 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m8 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m9 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m10 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m11 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m12 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m13 >= 0, false);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m14 >= 0, true);
    EXPECT_EQ(camera.getCameraMatrix2D(camera).m15 >= 0, true);
}


TEST(Camera2DTests, getWorldToScreen2D)
{
    ::Camera2D cameraC;

    cameraC.offset = Raylib::Vector2(12, 12).getCStruct();
    cameraC.target = Raylib::Vector2(12, 12).getCStruct();
    cameraC.rotation = 1;
    cameraC.zoom = 1;
    Raylib::Camera2D camera(cameraC);
    EXPECT_EQ(camera.getWorldToScreen2D(Raylib::Vector2(0,0).getCStruct(), camera).x >= 0, true);
    EXPECT_EQ(camera.getWorldToScreen2D(Raylib::Vector2(0,0).getCStruct(), camera).y >= 0, false);
}

TEST(Camera2DTests, getScreenToWorld2D)
{
    ::Camera2D cameraC;

    cameraC.offset = Raylib::Vector2(12, 12).getCStruct();
    cameraC.target = Raylib::Vector2(12, 12).getCStruct();
    cameraC.rotation = 1;
    cameraC.zoom = 1;
    Raylib::Camera2D camera(cameraC);
    EXPECT_EQ(camera.getScreenToWorld2D(Raylib::Vector2(0,0).getCStruct(), camera).x >= 0, false);
    EXPECT_EQ(camera.getScreenToWorld2D(Raylib::Vector2(0,0).getCStruct(), camera).y >= 0, true);
}
