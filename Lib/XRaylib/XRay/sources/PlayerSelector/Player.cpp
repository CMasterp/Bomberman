/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.cpp
*/

#include "PlayerSelector/Player.hpp"

PlayerSelector::Player::Player(const std::string &obj, const std::string &texture, const float &scalable, const int &idCharacter, const std::string &name, const Raylib::Color &color, const std::vector<std::string> &animations)
        : counter(0),
          _persoModel(LoadModel(obj.c_str())),
          _persoTexture(Raylib::Texture(texture)),
          _idCharacter(idCharacter),
          _scalable(scalable),
          _name(name),
          _color(color),
          _perso_path(obj),
          _texture_path(texture),
          _animations_path(animations)
{
    if (animations.size() == 3)
    {
        _animations.push_back(LoadModelAnimations(animations[0].c_str(), &counter)[0]);
        _animations.push_back(LoadModelAnimations(animations[1].c_str(), &counter)[0]);
        _animations.push_back(LoadModelAnimations(animations[2].c_str(), &counter)[0]);
    }

    SetMaterialTexture(&_persoModel.materials[0], MAP_DIFFUSE, _persoTexture.getCStruct());
    counter = 0;
}

PlayerSelector::Player::~Player()
{
}

void PlayerSelector::Player::draw(const float &rotation, const Raylib::Vector3 &pos)
{
    if (_animations.size() == 3)
    {
        if (clock.doesTimeElapsed(0.03))
            counter++;
        UpdateModelAnimation(_persoModel, _animations[2], counter);
        if (counter >= _animations[2].frameCount)
            counter = 0;
        DrawModelEx(_persoModel, pos.getCStruct(), {0, 0, 0}, 0, {_scalable, _scalable, _scalable}, _color.getCStruct());
    }
    else
    {
        DrawModelEx(_persoModel, pos.getCStruct(), {0, 1, 0}, rotation, {_scalable, _scalable, _scalable}, _color.getCStruct());
    }

}

void PlayerSelector::Player::drawForMaps(const float &rotation, const Raylib::Vector3 &pos)
{
    float scale_value = _scalable * 0.3;
    float rad_rotation = (0 * PI) / 180;

    _persoModel.transform = {
            0, 0, 1, 0,
            cosf(rad_rotation), sinf(rad_rotation), 0, 0,
            -sinf(rad_rotation), cosf(rad_rotation), 0, 0,
            0, 0, 0, 1
    };
    if (_animations.size() == 3)
    {
        if (clock.doesTimeElapsed(0.01))
            counter++;
        UpdateModelAnimation(_persoModel, _animations[0], counter);
        if (counter >= _animations[0].frameCount)
            counter = 0;
        DrawModelEx(_persoModel, {pos.x * 0.3f - static_cast<float>(2.4), pos.y * 0.3f - static_cast<float>(0.5), 0}, {0, 0, 1}, rotation, {scale_value, scale_value, scale_value}, _color.getCStruct());
    }
    else
    {
        DrawModelEx(_persoModel, {pos.x * 0.3f - static_cast<float>(2.4), pos.y * 0.3f - static_cast<float>(0.5), 0}, {0, 0, 1}, rotation, {scale_value, scale_value, scale_value}, _color.getCStruct());
    }

}

int PlayerSelector::Player::getId(void) const
{
    return _idCharacter;
}

const std::string PlayerSelector::Player::getName(void) const
{
    return _name;
}

const CharDictionary PlayerSelector::Player::getCharDictionary() const
{
    return {
            _perso_path,
            _texture_path,
            _scalable,
            _name,
            _color,
            _animations_path
    };
}

std::pair<Model, float> PlayerSelector::Player::getModel() const
{
    return {_persoModel, _scalable};
}