/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Game/Player/Player.hpp"

// TEST(PlayerTests, copy_const)
// {
//     Raylib::Vector3 positions(30, 40, 1);
//     Raylib::Color color = Raylib::Color::White();
//     Animator animations;
//     Game::Human player("PlayerName", positions, "../../resources/players/3D/Bombermans/white_tpose.glb", "../../resources/players/3D/Bombermans/texture.png", animations, color);
//     std::array<int, 5> powerups = player.getPowerUps();

//     EXPECT_EQ(player.getName(), "PlayerName");
//     EXPECT_EQ(player.getPositions().x, 30);
//     EXPECT_EQ(player.getPositions().y, 40);
//     EXPECT_EQ(player.getPositions().z, 40);
//     EXPECT_EQ(player.getKills(), 2);
//     EXPECT_EQ(player.getBrokenWalls(), 200);
//     EXPECT_EQ(powerups[P_SKATE], 0);
//     EXPECT_EQ(powerups[P_BOMB], 0);
//     EXPECT_EQ(powerups[P_PASS], 0);
//     EXPECT_EQ(powerups[P_FIRE], 0);
//     EXPECT_EQ(powerups[P_LIFE], 0);
// }

// TEST(PlayerTests, id)
// {
//     Game::Human player;

//     player.setID(1);
//     EXPECT_EQ(player.getID(), 1);
// }

// TEST(PlayerTests, name)
// {
//     Game::Human player;

//     player.setName("PlayerName");
//     EXPECT_EQ(player.getName(), "PlayerName");
// }

// TEST(PlayerTests, positions)
// {
//     Game::Player player;

//     player.setPositions({30, 40});
//     EXPECT_EQ(player.getPositions().first, 30);
//     EXPECT_EQ(player.getPositions().second, 40);
// }

// TEST(PlayerTests, kills)
// {
//     Game::Player player;

//     player.setKills(2);
//     EXPECT_EQ(player.getKills(), 2);
// }

// TEST(PlayerTests, brokenWall)
// {
//     Game::Player player;

//     player.setBrokenWalls(200);
//     EXPECT_EQ(player.getBrokenWalls(), 200);
// }

// TEST(PlayerTests, powerUps)
// {
//     Game::Player player;

//     player.setPowerUps({1, 0, 1, 1, 0});
//     std::array<int, 5> powerups = player.getPowerUps();

//     EXPECT_EQ(powerups[P_SKATE], 1);
//     EXPECT_EQ(powerups[P_BOMB], 0);
//     EXPECT_EQ(powerups[P_PASS], 1);
//     EXPECT_EQ(powerups[P_FIRE], 1);
//     EXPECT_EQ(powerups[P_LIFE], 0);
// }