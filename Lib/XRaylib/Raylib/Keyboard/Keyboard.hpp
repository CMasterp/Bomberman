/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <string>
#include <iostream>
#include "Exception/Exception.hpp"
#include "raylib.h"

namespace Raylib
{
    class Keyboard {

    public:
        /**
         * @brief Construct a new Keyboard object
         */
        Keyboard();

        /**
         * @brief Destroy the Keyboard object
         */
        ~Keyboard();

        /**
         * @brief Detect if a key has been pressed once
         *
         * @param key A size_t
         * @return true if key has been pressed once, false otherwise
         */
        static bool isKeyPressed(const size_t &key);

        /**
         * @brief Detect if a key is being pressed
         *
         * @param key A size_t
         * @return true if key is being pressed, false otherwise
         */
        static bool isKeyDown(const size_t &key);

        /**
         * @brief Detect if a key has been released once
         *
         * @param key A size_t
         * @return true if key has been released once, false otherwise
         */
        static bool isKeyReleased(const size_t &key);

        /**
         * @brief Detect if a key is NOT being pressed
         *
         * @param key A size_t
         * @return true if key is NOT being pressed, false otherwise
         */
        static bool isKeyUp(const size_t &key);

        /**
         * @brief Set a custom key to exit program (default is ESC)
         *
         * @param key A size_t
         */
        static void setExitKey(const size_t &key);

        /**
         * @brief Get key pressed (keycode), call it multiple times for keys queued
         *
         * @return A size_t
         */
        static size_t getKeyPressed(void);

        /**
         * @brief Get char pressed (unicode), call it multiple times for chars queued
         *
         * @return A size_t
         */
        static size_t getCharPressed(void);
    };

#include "Keyboard.inl"
}

#endif /* !KEYBOARD_HPP_ */
