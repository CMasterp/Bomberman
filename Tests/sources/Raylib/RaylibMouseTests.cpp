/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibMouseTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Mouse/Mouse.hpp"

TEST(MouseTest, isButtonPressedTest)
{
    Raylib::Mouse test;
    size_t button = 1;
    EXPECT_EQ(false, test.isButtonPressed(button));
}

TEST(MouseTest, isButtonDownTest)
{
    Raylib::Mouse test;
    size_t button = 1;
    EXPECT_EQ(false, test.isButtonDown(button));
}

TEST(MouseTest, isButtonReleasedTest)
{
    Raylib::Mouse test;
    size_t button = 1;
    EXPECT_EQ(false, test.isButtonReleased(button));
}

TEST(MouseTest, isButtonUpTest)
{
    Raylib::Mouse test;
    size_t button = 1;
    EXPECT_EQ(true, test.isButtonUp(button));
}

TEST(MouseTest, getMouseXTest)
{
    try {
        Raylib::Mouse test;
        test.getMouseX();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid mouse position X", ex.what());
    }
}

TEST(MouseTest, getMouseYTest)
{
    try {
        Raylib::Mouse test;
        test.getMouseY();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid mouse position Y", ex.what());
    }
}

TEST(MouseTest, setMouseScaleTest)
{
    try {
        Raylib::Mouse test;
        size_t scaleX = 1;
        size_t scaleY = 1;
        test.setMouseScale(scaleX, scaleY);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Set the Mouse Scale", ex.what());
    }
}

TEST(MouseTest, setMouseOffsetTest)
{
    try {
        Raylib::Mouse test;
        size_t scaleX = 1;
        size_t scaleY = 1;
        test.setMouseOffset(scaleX, scaleY);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Set the Mouse Scale", ex.what());
    }
}

TEST(MouseTest, getMouseWheelMoveTest)
{
    try {
        Raylib::Mouse test;
        test.getMouseWheelMove();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Mouse Wheel Move", ex.what());
    }
}

TEST(MouseTest, getTouchXTest)
{
    try {
        Raylib::Mouse test;
        test.getTouchX();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid touch position X", ex.what());
    }
}

TEST(MouseTest, getTouchYTest)
{
    try {
        Raylib::Mouse test;
        test.getTouchY();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid touch position Y", ex.what());
    }
}