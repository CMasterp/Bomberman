/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera3D
*/

#include "Camera3D.hpp"

Raylib::Camera3D::Camera3D(const Vector3 &position, const Vector3 &target, const Vector3 &up, const float &fovy, const int &projection)
        : _camera3D({position.getCStruct(), target.getCStruct(), up.getCStruct(), fovy, projection})
{
}

Raylib::Camera3D::Camera3D(const ::Camera3D &camera3D)
{
    set(camera3D);
}

Raylib::Camera3D::~Camera3D()
{
}
