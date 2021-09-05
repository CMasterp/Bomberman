/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Input
*/

#include "Input.hpp"
#include "Exception/Exception.hpp"
Input::Input()
{
    _inputs[UP] = 1;
    _inputs[RIGHT] = 2;
    _inputs[DOWN] = 3;
    _inputs[LEFT] = 4;
    _inputs[TRIANGLE] = 5;
    _inputs[ROND] = 6;
    _inputs[CROIX] = 7;
    _inputs[CARRE] = 8;
    _inputs[L1] = 9;
    _inputs[L2] = 10;
    _inputs[R1] = 11;
    _inputs[R2] = 12;
    _inputs[SHARE] = 13;
    _inputs[UNKNOWN] = 14;
    _inputs[OPTIONS] = 15;
    _inputs[L3] = 16;
    _inputs[R3] = 17;
}

Input::~Input()
{
}

void updateGamepad()
{
    Raylib::Mouse::setMousePosition(Raylib::Mouse::getMouseX() + Raylib::Gamepad::getGamepadAxisMovement(0, 0), Raylib::Mouse::getMouseY());
    Raylib::Mouse::setMousePosition(Raylib::Mouse::getMouseX(), Raylib::Mouse::getMouseY() + Raylib::Gamepad::getGamepadAxisMovement(0, 1));

/*    for (int i = 0; i < GetGamepadAxisCount(0); i++) {
        Raylib::Text::drawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);

    }

    if (GetGamepadButtonPressed() != -1) DrawText(TextFormat("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RED);
    else DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY);
        ;*/
}

int catchThrowTryupdateGamepad() {
    try
    {   Input test;
        test.updateGamepad();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}