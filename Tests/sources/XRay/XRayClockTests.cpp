/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** XRayCinematicClock
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/Clock.hpp"

TEST(ClockTests, timeisElapsed)
{
    Clock clock;

    EXPECT_EQ(true, clock.doesTimeElapsed(0, false));
}

TEST(ClockTests, timeisElapsedwithreset)
{
    Clock clock;

    EXPECT_EQ(true, clock.doesTimeElapsed(0, true));
}

TEST(ClockTests, timeisntElapsed)
{
    Clock clock;

    EXPECT_EQ(false, clock.doesTimeElapsed(100, false));
}

TEST(ClockTests, timeisntElapsedwithreset)
{
    Clock clock;

    EXPECT_EQ(false, clock.doesTimeElapsed(100, true));
}