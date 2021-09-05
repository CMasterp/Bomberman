/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Bomb
*/

#include "Bomb.hpp"

Game::Bomb::Bomb(const Raylib::Vector3 &positions, const int &fire, std::vector<std::shared_ptr<Game::Player>> &players, std::function<void (size_t)> function, Game::Player &player)
        : Animated(positions, "resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/texture.png", {"resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/bomb.glb"}),
          _fire(fire),
          _exploded(false),
          _explosing(false),
          _bZoneX({0, 0}),
          _bZoneY({0, 0}),
          _players{players},
          _pointerToSetPlayer(function),
          _reseter(player)
{

}

Game::Bomb::~Bomb()
{
}