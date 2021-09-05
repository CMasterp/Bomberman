/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibKeyboardTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Keyboard/Keyboard.hpp"

TEST(KeyboardTest, isKeyPressedTest)
{
    Raylib::Keyboard test;
    size_t key = 1;
    EXPECT_EQ(false, test.isKeyPressed(key));
}

TEST(KeyboardTest, isKeyDownTest)
{
    Raylib::Keyboard test;
    size_t key = 1;
    EXPECT_EQ(false, test.isKeyDown(key));
}

TEST(KeyboardTest, isKeyReleased)
{
    Raylib::Keyboard test;
    size_t key = 1;
    EXPECT_EQ(false, test.isKeyReleased(key));
}

TEST(KeyboardTest, isKeyUp)
{
    Raylib::Keyboard test;
    size_t key = 1;
    EXPECT_EQ(true, test.isKeyUp(key));
}

TEST(KeyboardTest, setExitKeyTest)
{
    try {
        Raylib::Keyboard test;
        size_t key = 1;
        test.setExitKey(key);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Set a custom key", ex.what());
    }
}

TEST(KeyboardTest, getKeyPressedTest)
{
    try {
        Raylib::Keyboard test;
        test.getKeyPressed();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Get key pressed (keycode)", ex.what());
    }
}

TEST(KeyboardTest, getCharPressedTest)
{
    try {
        Raylib::Keyboard test;
        test.getCharPressed();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Get char pressed (unicode)", ex.what());
    }
}