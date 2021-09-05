/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "Map/Map.hpp"

TEST(MapTest, pass)
{
    try {
        std::pair<size_t, size_t> players;
        Game::Map map(15, 15, players);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_width_dimension)
{
    try {
        std::pair<size_t, size_t> players;
        Game::Map map(0, 15, players);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_height_dimension)
{
    try {
        std::pair<size_t, size_t> players;
        Game::Map map(15, 0, players);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_player)
{
    try {
        std::pair<size_t, size_t> players = {0, 0};
        Game::Map map(15, 15, players);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid number of players", ex.what());
    }
}

TEST(MapTest, getWidth)
{
    std::pair<size_t, size_t> players = {2, 2};
    Game::Map map(15, 15, players);

    EXPECT_EQ(15, map.getWidth());
}

TEST(MapTest, getHeight)
{
    std::pair<size_t, size_t> players = {2, 2};
    Game::Map map(15, 15, players);

    EXPECT_EQ(15, map.getHeight());
}

TEST(MapTest, setWidth)
{
    std::pair<size_t, size_t> players = {2, 2};
    Game::Map map(15, 15, players);

    map.setWidth(21);
    EXPECT_EQ(21, map.getWidth());
}

TEST(MapTest, setHeight)
{
    std::pair<size_t, size_t> players = {2, 2};
    Game::Map map(15, 15, players);

    map.setHeight(21);
    EXPECT_EQ(21, map.getHeight());
}

TEST(MapTest, isMapEmpty)
{
    std::pair<size_t, size_t> players = {2, 2};
    Game::Map map(15, 15, players);

    EXPECT_EQ(map.getMap().empty(), false);
}