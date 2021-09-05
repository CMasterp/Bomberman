/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

#include "MotionlessEntity.hpp"

void Game::MotionlessEntity::updateAvailablePaths(void)
{
    std::vector<std::string> files;
    bool isThereThree; // FIXME: what is the use ???

    for (const auto & dir : std::filesystem::directory_iterator("resources/map"))
    {
        isThereThree = false;

        if (dir.is_directory()) {
            for (const auto &f : std::filesystem::directory_iterator(dir.path()))
                files.push_back(f.path().filename().string());
            if (files.end() != find(files.begin(), files.end(), "wall.png") &&
                files.end() != find(files.begin(), files.end(), "floor.png") &&
                files.end() != find(files.begin(), files.end(), "box.png")) {
                _available_paths.push_back(dir.path().filename().string());
            }
        } else
            throw "ERROR : Wrong directory (Ressources - Map)";
    }
}

Game::SolidWall::SolidWall(Raylib::Vector3 positions, size_t mapType, float width, float height, float length)
{
    _positions = positions;
    _mapType = mapType;
    _width = width;
    _length = length;
    _height = height;

    updateAvailablePaths();
    for (auto &path: _available_paths)
        _textures.push_back(*(new Raylib::Texture("resources/map/" + path + "/wall.png")));
}

Game::BreakableWall::BreakableWall(Raylib::Vector3 positions, size_t mapType, float width, float height, float length)
{
    _positions = positions;
    _mapType = mapType;
    _width = width;
    _length = length;
    _height = height;

    updateAvailablePaths();
    for (auto &path: _available_paths)
        _textures.push_back(*(new Raylib::Texture("resources/map/" + path + "/box.png")));
}

Game::Floor::Floor(Raylib::Vector3 positions, size_t mapType, float width, float height, float length)
{
    _positions = positions;
    _mapType = mapType;
    _width = width;
    _length = length;
    _height = height;

    updateAvailablePaths();
    for (auto &path: _available_paths)
        _textures.push_back(*(new Raylib::Texture("resources/map/" + path + "/floor.png")));
}