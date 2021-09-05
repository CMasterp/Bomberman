/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.hpp
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include "raylib.h"

namespace Raylib
{
    class Vector3 {
    public:

        /**
         * @brief Construct a new Vector 3 object
         *
         * @param x x coordinate
         * @param y y coordinate
         * @param z z coordinate
         */
        Vector3(float x = 0, float y = 0, float z = 0);

        /**
         * @brief Construct a new Vector 3 object
         *
         * @param copy Vector3 class instance
         */
        Vector3(const Vector3 &copy) = default;

        /**
         * @brief Construct a new Vector 3 object
         *
         * @param vector Vector3 C Raylib strutcture instance
         */
        Vector3(const ::Vector3 &vector);

        /**
         * @brief Destroy the Vector 3 object
         *
         */
        ~Vector3();

        /**
         * @brief Assign to a Vector3 from a Vector3 class instance
         *
         * @param copy Vector3 class instance
         * @return Vector3
         */
        Vector3 operator=(const Vector3 &copy);

        /**
         * @brief Assign to a Vector3 from a Vector3 C Raylib structure instance
         *
         * @param cvec Vector3 C Raylib structure instance
         * @return Vector3
         */
        Vector3 operator=(const ::Vector3 &cvec);

        /**
         * @brief Get the Vector3 C Raylib structure instance
         *
         * @return Vector3 C Raylib structure instance
         */
        ::Vector3 getCStruct(void) const;

        /**
        * @brief The x position
        *
        */
        float x;
        /**
        * @brief The y position
        *
        */
        float y;
        /**
        * @brief The z position
        *
        */
        float z;

    };

#include "Vector3.inl"

}

#endif /* !VECTOR3D_HPP_ */