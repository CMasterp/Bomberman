/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <iostream>
#include "Text/Text.hpp"
#include "Gamepad/Gamepad.hpp"
#include "Mouse/Mouse.hpp"

class Input {
public:

    enum GamePadTouch {
        UP,
        RIGHT,
        DOWN,
        LEFT,
        TRIANGLE,
        ROND,
        CROIX,
        CARRE,
        L1,
        L2,
        R1,
        R2,
        SHARE,
        UNKNOWN,
        OPTIONS,
        L3,
        R3
    };

    /**
     * @brief Construct a new Input object
     */
    Input();

    /**
     * @brief Destroy the Input object
     */
    ~Input();

    /**
     * @brief Get and Set Gamepad Input
     */
    static void updateGamepad();

private:
    std::map<GamePadTouch, int> _inputs;            // Inputs

};

#endif /* !XRAY_HPP_ */