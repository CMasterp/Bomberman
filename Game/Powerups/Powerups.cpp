/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Powerups.cpp
*/

#include "Powerups.hpp"

Game::Powerups::Powerups(const Raylib::Vector3 &position, const std::string &type)
        : Animated(position, "resources/assets/3D/Items/item.glb", "resources/assets/3D/Items/" + type + ".png", {"resources/assets/3D/Items/item.glb", "resources/assets/3D/Items/item.glb", "resources/assets/3D/Items/item.glb"}, 0.8)
{
    Animated::setRotation(270.f);
}

Game::Powerups::~Powerups()
{

}

Game::BombUp::BombUp(const Raylib::Vector3 &position)
        : Powerups(position, "bomb")
{

}

Game::BombUp::~BombUp()
{

}

Game::Life::Life(const Raylib::Vector3 &position)
        : Powerups(position, "life")
{

}

Game::Life::~Life()
{

}

Game::Pass::Pass(const Raylib::Vector3 &position)
        : Powerups(position, "pass")
{

}

Game::Pass::~Pass()
{

}

Game::Speed::Speed(const Raylib::Vector3 &position)
        : Powerups(position, "skate")
{

}

Game::Speed::~Speed()
{

}

Game::Fire::Fire(const Raylib::Vector3 &position)
        : Powerups(position, "fire")
{

}

Game::Fire::~Fire()
{

}