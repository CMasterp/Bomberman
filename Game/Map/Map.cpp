/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#include "Map.hpp"

Game::Map::Map()
{
}

Game::Map::Map(const size_t &width, const size_t &height, const std::pair<size_t, size_t> &playersNumber)
        : _width{width + BORDER}, _height{height + BORDER}, _playersNumber{playersNumber}
{
    if (width % 2 == 0 || width <= 3 || height < 3)
    {
        throw std::length_error("ERROR: Invalid map dimensions");
    }
    srand(time(NULL));
    create();
    fill(BREAK_WALL);
    maze();
    placeBorders();
    placeSolidWalls();
    placePlayers();
    setPlayersAreas(1);
}

Game::Map::~Map()
{
}
