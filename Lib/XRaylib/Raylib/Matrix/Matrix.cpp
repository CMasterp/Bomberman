/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Matrix.cpp
*/

#include "Matrix/Matrix.hpp"

Raylib::Matrix::Matrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
        : _matrix({m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15})
{

}

Raylib::Matrix::Matrix(::Matrix matrix)
        : _matrix(matrix)
{
}

Raylib::Matrix::Matrix(const Camera3D &cam)
        : _matrix(::GetCameraMatrix(cam.getCStruct()))
{

}

Raylib::Matrix::Matrix(const ::Camera3D &cam)
        : _matrix(::GetCameraMatrix(cam))
{
}

Raylib::Matrix::Matrix(const Camera2D &cam)
        : _matrix(::GetCameraMatrix2D(cam.getCStruct()))
{
}

Raylib::Matrix::Matrix(const ::Camera2D &cam)
        : _matrix(::GetCameraMatrix2D(cam))
{
}

Raylib::Matrix::~Matrix()
{

}