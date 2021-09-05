/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map.cpp
*/

#include "PlayerSelector/Map.hpp"


PlayerSelector::Map::Map(std::vector<Player> models, std::vector<std::string> &asciiMap)
        : _textures(findTexturesAvailable(_nbTextures)),
          current(0),
          _COEF(0.3),
          _characters(models),
          _y(0),
          _x(0),
          _direction(0)
{
    if (models.size() >= 1)
        asciiMap[1][1] = '1';
    if (models.size() >= 2)
        asciiMap[5][1] = '2';
    if (models.size() >= 3)
        asciiMap[5][5] = '3';
    if (models.size() >= 4)
        asciiMap[1][5] = '4';

    std::cout << "------------ Generated Map ------------" << std::endl;
    for (auto &line : asciiMap)
    {
        std::cout << line << std::endl;
    }
    _charMap = asciiMap;

}

PlayerSelector::Map::~Map()
{
}

std::vector<std::vector<Texture>> PlayerSelector::Map::findTexturesAvailable(int &nb_textures)
{
    std::vector<std::vector<Texture>> res;
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
                res.push_back({
                                      Raylib::Texture(dir.path().string() + "/floor.png").getCStruct(),
                                      Raylib::Texture(dir.path().string() + "/wall.png").getCStruct(),
                                      Raylib::Texture(dir.path().string() + "/box.png").getCStruct()
                              });
            }
        } else
            throw "ERROR : Wrong directory (Ressources - Map)";
    }
    nb_textures = res.size();
    return res;
}

std::vector<std::string> PlayerSelector::Map::getMap() const
{
    return _charMap;
}

std::vector<Texture2D> PlayerSelector::Map::getTextures() const
{
    return _textures[current];
}

void PlayerSelector::Map::next()
{
    current = (current + 1 == _textures.size()) ? 0 : current + 1;
}

void PlayerSelector::Map::prev()
{
    current = (current == 0) ? _textures.size() - 1 : current - 1;
}

size_t PlayerSelector::Map::getMapType() const
{
    return current;
}

void PlayerSelector::Map::drawHandlingCharacters(const int &id)
{
    const float SPEED = 0.06;
    Raylib::Vector3 pos(0,0,0);
    bool canMove = _clock.doesTimeElapsed(0.01);
    int rotation = 0;

    if (canMove)
        _direction += SPEED;
    if (_direction >= 16.f)
        _direction = 0;
    if (canMove)
    {
        if (_direction < 4.f) {
            _x += SPEED;
            rotation = 0;
        } else if (_direction < 8.f) {
            _y += SPEED;
            rotation = 90;
        } else if (_direction < 12.f) {
            _x -= SPEED;
            rotation = 180;
        } else {
            _y -= SPEED;
            rotation = 270;
        }
    }
    if (id == 0)
    {
        _characters[0].drawForMaps(rotation, {_x + 1, _y + 1, 0});
    }
    if (id == 1)
    {
        _characters[1].drawForMaps((rotation + 90) % 360, {4 - _y + 1, _x + 1, 0});
    }
    if (id == 2)
    {
        _characters[2].drawForMaps((rotation + 180) % 360, {4 - _x + 1, 4 - _y + 1, 0});
    }
    if (id == 3)
    {
        _characters[3].drawForMaps((rotation + 270) % 360, {_y + 1, 4 - _x + 1, 0});
    }
}

void PlayerSelector::Map::draw()
{
    float x;
    float y = 0;
    float scale;

    for (const std::string &line : _charMap) {
        x = 0;
        for (const char &c : line) {
            if (c == '1' || c == '2' || c == '3' || c == '4')
                drawHandlingCharacters(c - '1');
            if (c == 'W' || c == 'E')
                Raylib::Drawing::drawCubeTexture(_textures[current][WALL], {x * _COEF - static_cast<float>(2.4), y * _COEF - static_cast<float>(0.5), 0}, _COEF, _COEF, _COEF, Raylib::Color::White());
            if (c == 'M')
                Raylib::Drawing::drawCubeTexture(_textures[current][BOX], {x * _COEF - static_cast<float>(2.4), y * _COEF - static_cast<float>(0.5), 0}, _COEF, _COEF, _COEF, Raylib::Color::White());
            Raylib::Drawing::drawCubeTexture(_textures[current][FLOOR], {x * _COEF - static_cast<float>(2.4), y * _COEF - static_cast<float>(0.5), -_COEF}, _COEF, _COEF, _COEF, Raylib::Color::Gray());
            x++;
        }
        y++;
    }
}