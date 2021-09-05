/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** ScoreTests
*/

#include <gtest/gtest.h>
#include "Score/Score.hpp"

Game::Score initScore()
{
    std::array<size_t, 9> settings = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Game::Player player;

    player.setName("Name");
    player.setBrokenWalls(200);
    player.setKills(2);
    player.setPositions({30, 40});
    player.setPowerUps({1, 0, 1, 1, 0});
    Game::Score score(settings, player);
    return score;
}

TEST(ScoreTests, initScore)
{
    Game::Score score = initScore();

    EXPECT_EQ(score.getScore(), 2550); //Player score + coef
}

TEST(ScoreTests, setScore)
{
    Game::Score score = initScore();

    score.setScore(800);
    EXPECT_EQ(score.getScore(), 800);
}

TEST(ScoreTests, initAndSetScore)
{
    Game::Score score = initScore();

    EXPECT_EQ(score.getScore(), 2550); //Player score + coef
    score.setScore(800);
    EXPECT_EQ(score.getScore(), 800);
}