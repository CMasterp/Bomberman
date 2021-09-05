/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** XrayMouseTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/MousePlayerInput.hpp"

TEST(MousePlayerTest, shouldGoToEast)
{
    MousePlayerInput input;

    auto res = input.shouldGoToEast();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldGoToWest)
{
    MousePlayerInput input;

    auto res = input.shouldGoToWest();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldGoToNorth)
{

    MousePlayerInput input;

    auto res = input.shouldGoToNorth();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldGoToSouth)
{
    MousePlayerInput input;

    auto res = input.shouldGoToSouth();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldChangeToPrev)
{
    MousePlayerInput input;

    auto res = input.shouldChangeToPrev();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldChangeToNext)
{
    MousePlayerInput input;

    auto res = input.shouldChangeToNext();

    EXPECT_EQ(false,res);
}

TEST(MousePlayerTest, shouldSimulateAClick)
{
    MousePlayerInput input;

    auto res = input.shouldSimulateAClick();

    EXPECT_EQ(false,res);
}