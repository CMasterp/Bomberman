/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Mouse {

    public:
        /**
         * @brief Construct a new Mouse object
         */
        Mouse();

        /**
         * @brief Destroy the Mouse object
         */
        ~Mouse();

        /**
         * @brief Detect if a mouse button has been pressed once
         *
         * @param button A size_t
         * @return true if $button has been pressed once, false otherwise
         */
        static bool isButtonPressed(const size_t &button);

        /**
         * @brief Detect if a mouse button is being pressed
         *
         * @param button A size_t
         * @return true if $button is being pressed, false otherwise
         */
        static bool isButtonDown(const size_t &button);

        /**
         * @brief Detect if a mouse button has been released once
         *
         * @param button A size_t
         * @return true if $button has been released once, false otherwise
         */
        static bool isButtonReleased(const size_t &button);

        /**
         * @brief Detect if a mouse button is NOT being pressed
         *
         * @param button A size_t
         * @return true if $button is NOT being pressed, false otherwise
         */
        static bool isButtonUp(const size_t &button);

        /**
         * @brief Returns mouse position X
         *
         * @return A size_t that represents position of mouse on x-axis
         */
        static size_t getMouseX(void);

        /**
         * @brief Returns mouse position Y
         *
         * @return A size_t that represents position of mouse on y-axis
         */
        static size_t getMouseY(void);

        /**
         * @brief Set the Mouse Position XY
         *
         * @param x Position of Mouse on x-axis
         * @param y Position of Mouse on y-axis
         */
        static void setMousePosition(const size_t &x, const size_t &y);

        /**
         * @brief Set the Mouse Offset
         *
         * @param offsetX A size_t
         * @param offsetY A size_t
         */
        static void setMouseOffset(const size_t &offsetX, const size_t &offsetY);

        /**
         * @brief Set the Mouse Scale
         *
         * @param scaleX A size_t
         * @param scaleY A size_t
         */
        static void setMouseScale(const float &scaleX, const float &scaleY);

        /**
         * @brief Get the Mouse Wheel Move
         *
         * @return float, that represents mouse wheel move
         */
        static float getMouseWheelMove(void);

        /**
         * @brief Set the Mouse Cursor
         *
         * @param cursor A size_t
         */
        static void setMouseCursor(const size_t &cursor);

        /**
         * @brief Returns touch position X for touch point 0 (relative to screen size)
         *
         * @return A size_t
         */
        static size_t getTouchX(void);

        /**
         * @brief Returns touch position Y for touch point 0 (relative to screen size)
         *
         * @return A size_t
         */
        static size_t getTouchY(void);
    };

#include "Mouse.inl"
}

#endif /* !MOUSE_HPP_ */
