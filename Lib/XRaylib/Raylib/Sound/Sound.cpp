/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Sound
*/

#include "Sound.hpp"

Raylib::Sound::Sound()
{
}

Raylib::Sound::~Sound()
{
    ::UnloadSound(_sound);
}

Raylib::Sound::Sound(const Sound &sound)
{
    set(sound);
}

Raylib::Sound::Sound(const std::string &fileName)
{
    _sound = ::LoadSound(fileName.c_str());
}