/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#include "Player.hpp"

Game::Player::Player()
        : Animated({0, 0, 0}, "resources/players/3D/Bombermans/white_tpose.glb", "resources/players/3D/Bombermans/texture.png"),
          _kills{0},
          _brokenWalls{0},
          _powerUps{0},
          _bomb_droped(0)
{
}

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps)
        : Animated(positions, "resources/players/3D/Bombermans/white_tpose.glb", "resources/players/3D/Bombermans/texture.png"),
          _kills{kills},
          _brokenWalls{brokenWalls},
          _powerUps{powerUps},
          _ID(0),
          _bomb_droped(0)
{
}

Game::Player::Player(const std::string &name, const int &id, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
        : Animated(positions, obj_path, texture_path, animation_path, scalable, color),
          _name{name},
          _kills{0},
          _brokenWalls{0},
          _powerUps{0},
          _ID(id),
          _bomb_droped(0)
{
}

Game::AI::AI(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
        : Player(name, ID, positions, obj_path, texture_path, animation_path, scalable, color)
{
}

Game::Human::Human(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
        : Player(name, ID, positions, obj_path, texture_path, animation_path, scalable, color)
{
}

std::ostream& operator<<(std::ostream& os, const Game::Player *obj)
{
    os << "--------------------------------------" << std::endl;
    os << "Type : " << obj->getType() << std::endl;
    os << "Name : " << obj->getName() << std::endl;
    os << "ID : " << obj->getID() << std::endl;
    os << "Positions : (" << obj->getPositions().x << ", " << obj->getPositions().x << ", " << obj->getPositions().z << ")" << std::endl;
    os << "Power-ups :" << std::endl;
    os << '\t' << "Speed : " << obj->getPowerUps()[0] << std::endl;
    os << '\t' << "Bombup : " << obj->getPowerUps()[1] << std::endl;
    os << '\t' << "Pass : " << obj->getPowerUps()[2] << std::endl;
    os << '\t' << "Fire : " << obj->getPowerUps()[3] << std::endl;
    os << '\t' << "Life : " << obj->getPowerUps()[4] << std::endl;

    return os;

}

std::ostream& operator<<(std::ostream& os, const std::vector<Game::Player *>& objs)
{
    for (const Game::Player *player : objs)
        os << player;
    return os;
}