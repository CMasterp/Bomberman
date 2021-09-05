/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.cpp
*/

#include "Vector3.hpp"

Raylib::Vector3::Vector3(float x, float y, float z)
        : x {x}, y {y}, z {z}
{
}

Raylib::Vector3::Vector3(const ::Vector3 &copyVector)
        : x {copyVector.x}, y {copyVector.y}, z{copyVector.z}
{
}

Raylib::Vector3::~Vector3()
{
}