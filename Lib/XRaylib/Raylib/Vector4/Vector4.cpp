/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.cpp
*/

#include "Vector4.hpp"

Raylib::Vector4::Vector4(float x, float y, float z, float w)
        : x{x}, y{y}, z{z}, w{w}
{
}

Raylib::Vector4::Vector4(const ::Vector4 &copyVector)
        : x{copyVector.x}, y{copyVector.y}, z{copyVector.z}, w{copyVector.w}
{
}

Raylib::Vector4::~Vector4()
{
}