/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibColorTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Color/Color.hpp"

TEST(ColorTest, fadeTest)
{
    try {
        Raylib::Color test;
        float a = 1.0;
        auto red = test.Gray();
        test.fade(red,a);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid color with alpha applied", ex.what());
    }
}

TEST(ColorTest, colorToIntTest)
{
    Raylib::Color test;
    auto red = test.Gray();
    EXPECT_EQ(18446744071604175615, test.colorToInt(red));
}

TEST(ColorTest, colorFromHSVTest)
{
    try {
        Raylib::Color test;
        float a = 1.0;
        float b = 1.0;
        float c = 1.0;

        test.colorFromHSV(a,b,c);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid cColor from HSV values", ex.what());
    }
}

TEST(ColorTest, colorAlphaBlendTest)
{
    try {
        Raylib::Color test;
        auto a = test.Gray();
        auto b = test.Gray();
        auto c = test.Gray();

        test.colorAlphaBlend(a,b,c);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid color with alpha-blended applied", ex.what());
    }
}

TEST(ColorTest, getColorTest)
{
    try {
        Raylib::Color test;
        auto a = 030303;

        test.getColor(a);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Get Color", ex.what());
    }
}

TEST(ColorTest, getPixelDataSizeTest)
{
    Raylib::Color test;
    size_t a = 0;
    size_t b = 0;
    size_t c  = 0;
    EXPECT_EQ(0, test.getPixelDataSize(a,b,c));
}