/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibCursorTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Cursor/Cursor.hpp"

TEST(CursorTest, isCursorHiddenTestTrue)
{
    Raylib::Cursor test;
    EXPECT_EQ(false, test.isCursorHidden());
}

TEST(CursorTest, isCursorHiddenTestFalse)
{
    Raylib::Cursor test;
    EXPECT_EQ(false, test.isCursorHidden());
}

TEST(CursorTest, isCursorOnScreenTestFalse)
{
    Raylib::Cursor test;
    EXPECT_EQ(false, test.isCursorOnScreen());
}