/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera2D
*/

#ifndef CAMERA2D_HPP_
#define CAMERA2D_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Camera2D {
    public:
        /**
         * @brief Construct a new Camera2D object
         */
        Camera2D();

        /**
         * @brief Destroy the Camera2D object
         */
        ~Camera2D();

        /**
         * @brief Construct a new Camera2D object (Copy Constructor)
         *
         * @param Camera2D A Camera2D C Structure
         */
        Camera2D(::Camera2D const &camera);

        /**
         * @brief Get C Structure for Camera2D Class
         * @return A Camera2D C Structure
         */
        ::Camera2D getCStruct(void) const;

        /**
         * @brief Initialize 2D mode with custom camera (2D)
         *
         * @param Camera2D A Camera2D structure
         */
        void beginMode2D(Raylib::Camera2D const &camera) const;

        /**
         * @brief Ends 2D mode with custom camera
         */
        void EndMode2D(void) const;

        /**
         * @brief Returns camera 2d transform matrix
         *
         * @param Camera2D A Camera2D structure
         * @return A Matrix
         */
        ::Matrix getCameraMatrix2D(Raylib::Camera2D const &camera) const;

        /**
         * @brief Returns the screen space position for a 2d camera world space position
         *
         * @param Position A Vector2 structure
         * @param Camera2D A Camera2D structure
         * @return A Vector2
         */
        ::Vector2 getWorldToScreen2D(::Vector2 const &position, Raylib::Camera2D const &camera) const;

        /**
         * @brief Returns the world space position for a 2d camera screen space position
         *
         * @param Position A Vector2 structure
         * @param Camera2D A Camera2D structure
         * @return A Vector2
         */
        ::Vector2 getScreenToWorld2D(::Vector2 const &position, Raylib::Camera2D const &camera) const;

        /**
          * @brief Overload of '=' operator
          *
          * @param camera A const reference to a Camera2D
          * @return A reference to Camera2D (Camera2D &)
          */
        Camera2D &operator=(const Camera2D &camera);

    private:
        /**
         * @brief Set Camera2D
         *
         * @param Rectangle A Camera2D C Structure
         */
        void set(const ::Camera2D &camera);

        /**
         * @brief Set Rectangle
         *
         * @param Camera2D A const reference to a Camera2D object
         */
        void set(const Camera2D &camera);

        /**
         * @brief C Camera2D Structure instance
         *
         */
        ::Camera2D _camera2D;
    };

#include "Camera2D.inl"

}

#endif /* !CAMERA2D_HPP_ */
