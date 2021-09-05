/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.hpp
*/

#ifndef VECTOR4D_HPP_
#define VECTOR4D_HPP_

#include "raylib.h"

namespace Raylib {
    class Vector4 {
    public:

        /**
         * @brief Construct a new Vector 4 object
         *
         * @param x x coordinate
         * @param y y coordinate
         * @param z z coordinate
         * @param w w coordinate
         */
        Vector4(float x = 0, float y = 0, float z = 0, float w = 0);

        /**
         * @brief Construct a new Vector 4 object
         *
         * @param copy Vector4 class instance
         */
        Vector4(const Vector4 &copy) = default;

        /**
         * @brief Construct a new Vector 4 object
         *
         * @param vector Vector4 C Raylib strutcture instance
         */
        Vector4(const ::Vector4 &vector);

        /**
         * @brief Destroy the Vector 4 object
         */
        ~Vector4(void);

        /**
         * @brief Assign to a Vector4 from a Vector4 class instance
         *
         * @param copy Vector4 class instance
         * @return Vector4
         */
        Vector4 operator=(const Vector4 &copy);

        /**
         * @brief Assign to a Vector4 from a Vector4 C Raylib structure instance
         *
         * @param cvec Vector4 C Raylib structure instance
         * @return Vector4
         */
        Vector4 operator=(const ::Vector4 &cvec);

        /**
         * @brief Get the Vector4 C Raylib structure instance
         *
         * @return Vector4 C Raylib structure instance
         */
        ::Vector4 getCStruct(void) const;

        // The x position
        float x;

        // The y position
        float y;

        // The z position
        float z;

        // The w position
        float w;

    };

#include "Vector4.inl"

}

#endif /* !VECTOR4D_HPP_ */