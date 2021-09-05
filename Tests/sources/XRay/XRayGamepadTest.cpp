/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** XRayCinematicClock
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/GamepadPlayerInput.hpp"

TEST(GamePadTest, shouldGoToEast)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToEast();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldGoToWest)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToWest();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldGoToNorth)
{

    GamepadPlayerInput input;

    auto res = input.shouldGoToNorth();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldGoToSouth)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToSouth();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldChangeToPrev)
{
    GamepadPlayerInput input;

    auto res = input.shouldChangeToPrev();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldChangeToNext)
{
    GamepadPlayerInput input;

    auto res = input.shouldChangeToNext();

    EXPECT_EQ(false,res);
}

TEST(GamePadTest, shouldSimulateAClick)
{
    GamepadPlayerInput input;

    auto res = input.shouldSimulateAClick();

    EXPECT_EQ(false,res);
}

