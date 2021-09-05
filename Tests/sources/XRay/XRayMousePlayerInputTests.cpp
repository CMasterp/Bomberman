/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MousePlayerInputTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/MousePlayerInput.hpp"

TEST(MousePlayerInput, GoToEast)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldGoToEast(), 0);
}

TEST(MousePlayerInput, GoToWest)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldGoToWest(), 0);
}

TEST(MousePlayerInput, GoToNorth)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldGoToNorth(), 0);
}

TEST(MousePlayerInput, GoToSouth)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldGoToSouth(), 0);
}

TEST(MousePlayerInput, ChangeToPrev)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldChangeToPrev(), 0);
}

TEST(MousePlayerInput, ChangeToNext)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldChangeToNext(), 0);
}

TEST(MousePlayerInput, SimulateAClick)
{
    MousePlayerInput input;

    EXPECT_EQ(input.shouldSimulateAClick(), 0);
}