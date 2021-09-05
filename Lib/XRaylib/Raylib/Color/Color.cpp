/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Color
*/

#include "Color.hpp"

Raylib::Color::Color()
{
    _colorFactory["LIGHTGRAY"] = &Raylib::Color::LightGray;
    _colorFactory["GRAY"] = &Raylib::Color::Gray;
    _colorFactory["DARKGRAY"] = &Raylib::Color::DarkGray;
    _colorFactory["YELLOW"] = &Raylib::Color::Yellow;
    _colorFactory["GOLD"] = &Raylib::Color::Gold;
    _colorFactory["ORANGE"] = &Raylib::Color::Orange;
    _colorFactory["PINK"] = &Raylib::Color::Pink;
    _colorFactory["RED"] = &Raylib::Color::Red;
    _colorFactory["MAROON"] = &Raylib::Color::Maroon;
    _colorFactory["GREEN"] = &Raylib::Color::Green;
    _colorFactory["LIME"] = &Raylib::Color::Lime;
    _colorFactory["DARKGREEN"] = &Raylib::Color::DarkGreen;
    _colorFactory["SKYBLUE"] = &Raylib::Color::SkyBlue;
    _colorFactory["BLUE"] = &Raylib::Color::Blue;
    _colorFactory["DARKBLUE"] = &Raylib::Color::DarkBlue;
    _colorFactory["PURPLE"] = &Raylib::Color::Purple;
    _colorFactory["VIOLET"] = &Raylib::Color::Violet;
    _colorFactory["DARKPURPLE"] = &Raylib::Color::DarkPurple;
    _colorFactory["BEIGE"] = &Raylib::Color::Beige;
    _colorFactory["BROWN"] = &Raylib::Color::Brown;
    _colorFactory["DARKBROWN"] = &Raylib::Color::DarkBrown;
    _colorFactory["WHITE"] = &Raylib::Color::White;
    _colorFactory["BLACK"] = &Raylib::Color::Black;
    _colorFactory["BLANK"] = &Raylib::Color::Blank;
    _colorFactory["MAGENTA"] = &Raylib::Color::Magenta;
    _colorFactory["RAYWHITE"] = &Raylib::Color::RayWhite;
}

Raylib::Color::~Color()
{
}
