/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.cpp
*/

#include "Vector2.hpp"

Raylib::Vector2::Vector2(float x, float y)
        : x{x}, y{y}
{
}

Raylib::Vector2::Vector2(const ::Vector2 &cVec)
        : x{cVec.x}, y{cVec.y}
{
}

Raylib::Vector2::~Vector2()
{
}