/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibCamera3DTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Camera3D/Camera3D.hpp"

TEST(Camera3dTest, updateCameraTest)
{
    try {
        Raylib::Camera3D test;
        test.updateCamera();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera update", ex.what());
    }
}

TEST(Camera3dTest, setCameraPanControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraPanControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera pan control", ex.what());
    }
}

TEST(Camera3dTest, setCameraAltControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraAltControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera altitude control", ex.what());
    }
}

TEST(Camera3dTest, setCameraSmoothZoomControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraSmoothZoomControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera Smooth Zoom Control", ex.what());
    }
}

TEST(Camera3dTest, setCameraMoveControls1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraMoveControls(1,1,1,1,1,1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera move controls", ex.what());
    }
}

TEST(Camera3dTest, setCameraMoveControls0Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraMoveControls(0,0,0,0,0,0);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera move controls", ex.what());
    }
}