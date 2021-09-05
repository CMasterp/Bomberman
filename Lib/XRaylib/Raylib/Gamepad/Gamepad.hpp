/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Gamepad {

    public:
        /**
         * @brief Construct a new Gamepad object
         */
        Gamepad();

        /**
         * @brief Destroy the Gamepad object
         */
        ~Gamepad();

        /**
         * @brief Detect if a gamepad is available
         *
         * @param gamepad
         * @return true if a gamepad is available, otherwise false
         */
        static bool isGamepadAvailable(const int &gamepad);

        /**
         * @brief Check gamepad name (if available)
         *
         * @param gamepad An int
         * @param name A string
         * @return true or false
         */
        static bool isGamepadName(const int &gamepad, const std::string &name);

        /**
         * @brief Return gamepad internal name id
         *
         * @param gamepad An int
         * @return const std::string
         */
        static std::string getGamepadName(const int &gamepad);

        /**
         * @brief Detect if a gamepad button has been pressed once
         *
         * @param gamepad An int
         * @param button An int
         * @return true or false
         */
        static bool isGamepadButtonPressed(const int &gamepad, const int &button);

        /**
         * @brief Detect if a gamepad button is being pressed
         *
         * @param gamepad An int
         * @param button An int
         * @return true or false
         */
        static bool isGamepadButtonDown(const int &gamepad, const int &button);

        /**
         * @brief Detect if a gamepad button has been released once
         *
         * @param gamepad An int
         * @param button An int
         * @return true or false
         */
        static bool isGamepadButtonReleased(const int &gamepad, const int &button);

        /**
         * @brief Detect if a gamepad button is NOT being pressed
         *
         * @param gamepad An int
         * @param button An int
         * @return true or false
         */
        static bool isGamepadButtonUp(const int &gamepad, const int &button);

        /**
         * @brief Get the last gamepad button pressed
         *
         * @return An int
         */
        static int getGamepadButtonPressed(void);

        /**
         * @brief Return gamepad axis count for a gamepad
         *
         * @param gamepad An int
         * @return An int
         */
        static int getGamepadAxisCount(const int &gamepad);

        /**
         * @brief Return axis movement value for a gamepad axis
         *
         * @param gamepad An int
         * @param axis An int
         * @return A float
         */
        static float getGamepadAxisMovement(const int &gamepad, const int &axis);

        /**
         * @brief Set internal gamepad mappings (SDL_GameControllerDB)
         *
         * @param mappings A string
         * @return An int
         */
        static int setGamepadMappings(const std::string &mappings);
    };

#include "Gamepad.inl"
}

#endif /* !GAMEPAD_HPP_ */
