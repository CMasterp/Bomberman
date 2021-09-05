/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cursor
*/

#ifndef CURSOR_HPP_
#define CURSOR_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Cursor {

    public:
        /**
         * @brief Construct a new Cursor object
         */
        Cursor();

        /**
         * @brief Destroy the Cursor object
         */
        ~Cursor();

        /**
         * @brief Shows cursor
         */
        static void showCursor(void);

        /**
         * @brief Hides cursor
         */
        static void hideCursor(void);

        /**
         * @brief Check if cursor is not visible
         *
         * @return true or false
         */
        static bool isCursorHidden(void);

        /**
         * @brief Enables cursor (unlock cursor)
         */
        static void enableCursor(void);

        /**
         * @brief Disables cursor (lock cursor)
         */
        static void disableCursor(void);

        /**
         * @brief Check if cursor is on the current screen.
         *
         * @return true if cursor is on the current screen, false otherwise
         */
        static bool isCursorOnScreen(void);

    };

#include "Cursor.inl"
}

#endif /* !CURSOR_HPP_ */
