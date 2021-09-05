/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** SaveTests
*/

#include <gtest/gtest.h>
#include "Save/Save.hpp"

Game::Save initSaveTests()
{
    std::array<std::size_t, 9> settings = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<Game::Player, 4> players;
    Game::Player player;
    player.setID(1);
    player.setName("Name");
    player.setBrokenWalls(200);
    player.setKills(2);
    player.setPositions({30, 40});
    player.setPowerUps({1, 0, 1, 1, 0});
    players[0] = player;
    Game::Map map(15, 15, 1);
    Game::Save save(settings, players, map);

    return save;
}

TEST(SaveTests, getSettings)
{
    Game::Save save = initSaveTests();

    EXPECT_EQ(save.getSettings()[0], 1);
    EXPECT_EQ(save.getSettings()[1], 2);
    EXPECT_EQ(save.getSettings()[2], 3);
    EXPECT_EQ(save.getSettings()[3], 4);
    EXPECT_EQ(save.getSettings()[4], 5);
    EXPECT_EQ(save.getSettings()[5], 6);
    EXPECT_EQ(save.getSettings()[6], 7);
    EXPECT_EQ(save.getSettings()[7], 8);
}

TEST(SaveTests, getPlayers)
{
    Game::Save save = initSaveTests();
    std::array<int, 5> powerups = save.getPlayers()[0].getPowerUps();

    EXPECT_EQ(save.getPlayers()[0].getID(), 1);
    EXPECT_EQ(save.getPlayers()[0].getName(), "Name");
    EXPECT_EQ(save.getPlayers()[0].getKills(), 2);
    EXPECT_EQ(save.getPlayers()[0].getBrokenWalls(), 200);
    EXPECT_EQ(save.getPlayers()[0].getPositions().first, 30);
    EXPECT_EQ(save.getPlayers()[0].getPositions().second, 40);
    EXPECT_EQ(powerups[P_SKATE], 1);
    EXPECT_EQ(powerups[P_BOMB], 0);
    EXPECT_EQ(powerups[P_PASS], 1);
    EXPECT_EQ(powerups[P_FIRE], 1);
    EXPECT_EQ(powerups[P_LIFE], 0);
}

TEST(SaveTests, getMap)
{
    Game::Save save = initSaveTests();
    Game::Map map = save.getMap();

    EXPECT_EQ(map.getHeight(), 15);
    EXPECT_EQ(map.getWidth(), 15);
    EXPECT_EQ(map.getMap().empty(), false);
}