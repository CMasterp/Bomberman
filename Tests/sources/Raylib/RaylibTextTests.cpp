/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibTextTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Text/Text.hpp"


TEST(TextTest, drawTextTest)
{
    try {
        Raylib::Text test;
        Raylib::Color color;
        color.Red();
        test.drawText("test", 0, 0, 1,color);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}

TEST(TextTest, measureTextTest)
{
    try {
        Raylib::Text test;
        test.measureText("test", 1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Measure string width", ex.what());
    }
}

TEST(TextTest, textIsEqualTest)
{
    Raylib::Text test;
    EXPECT_EQ(true, test.textIsEqual("test","test"));
}

TEST(TextTest, textLengthTest)
{
    try {
        Raylib::Text test;
        test.textLength("test");
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Measure string length", ex.what());
    }
}