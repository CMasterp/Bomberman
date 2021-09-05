/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera2D
*/

#include "Camera2D.hpp"

Raylib::Camera2D::Camera2D()
{
}

Raylib::Camera2D::Camera2D(const ::Camera2D &camera) {
    set(camera);
}

Raylib::Camera2D::~Camera2D()
{
}
