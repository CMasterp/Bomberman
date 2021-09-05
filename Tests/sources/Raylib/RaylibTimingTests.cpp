/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibTimingTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Timing/Timing.hpp"

TEST(TimingTest, setTargetFPSTest)
{
    try {
        Raylib::Timing test;
        test.setTargetFPS(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Set Framerate Per Second", ex.what());
    }
}

TEST(TimingTest, getFPSTest)
{
    try {
        Raylib::Timing test;
        test.getFPS();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Get Framerate Per Second", ex.what());
    }
}

TEST(TimingTest, getTimeTest)
{
    try {
        Raylib::Timing test;
        test.getTime();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Get time since window initialization", ex.what());
    }
}