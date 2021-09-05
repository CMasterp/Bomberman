/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Matrix.hpp
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include "raylib.h"
#include "Camera3D/Camera3D.hpp"
#include "Camera2D/Camera2D.hpp"

namespace Raylib
{
    class Matrix
    {
    public:

        /**
         * @brief Construct a new Matrix object
         *
         * @param m0 A float
         * @param m1 A float
         * @param m2 A float
         * @param m3 A float
         * @param m4 A float
         * @param m5 A float
         * @param m6 A float
         * @param m7 A float
         * @param m8 A float
         * @param m9 A float
         * @param m10 A float
         * @param m11 A float
         * @param m12 A float
         * @param m13 A float
         * @param m14 A float
         * @param m15 A float
         */
        Matrix(float m0 = 0, float m1 = 0, float m2 = 0, float m3 = 0, float m4 = 0, float m5 = 0, float m6 = 0, float m7 = 0, float m8 = 0, float m9 = 0, float m10 = 0, float m11 = 0, float m12 = 0, float m13 = 0, float m14 = 0, float m15 = 0);

        /**
        * @brief Construct a new Matrix object
        *
        * @param matrix A Matrix Object
        */
        Matrix(::Matrix matrix);

        /**
        * @brief Construct the Matrix object
        *
        * @param matrix A Camera3D Object
        */
        Matrix(const Camera3D &cam);

        /**
        * @brief Construct the Matrix object
        *
        * @param matrix A Camera3D struct
        */
        Matrix(const ::Camera3D &cam);

        /**
        * @brief Construct a new Matrix object
        *
        * @param cam A Camera2D Object
        */
        Matrix(const Camera2D &cam);

        /**
        * @brief Construct a new Matrix objectt
        *
        * @param cam A Camera2D struct
        */
        Matrix(const ::Camera2D &cam);

        /**
        * @brief Destroy the Matrix object
        */
        ~Matrix();

        // Matrix type (OpenGL style 4x4 - right handed, column major)
        ::Matrix _matrix;

    };
}

#endif /* !MATRIX_HPP_ */