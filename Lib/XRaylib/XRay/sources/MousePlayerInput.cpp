/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MousePlayerInput
*/

#include "MousePlayerInput.hpp"
#include "Exception/Exception.hpp"

/*
    MOUSE_BUTTON_LEFT    = 0,
    MOUSE_BUTTON_RIGHT   = 1,
    MOUSE_BUTTON_MIDDLE  = 2,
    MOUSE_BUTTON_SIDE    = 3,
    MOUSE_BUTTON_EXTRA   = 4,
    MOUSE_BUTTON_FORWARD = 5,
    MOUSE_BUTTON_BACK    = 6,

1600 40
250 250
        1725
          |
       _______
      |o     o|
165 - |   .   |
      |o_____o|
*/

MousePlayerInput::MousePlayerInput()
{
}

MousePlayerInput::~MousePlayerInput()
{
}

bool MousePlayerInput::shouldGoToEast(void) const
{
    bool mousePos;
    int x = static_cast<int>(Raylib::Mouse::getMouseX()) - 1725;
    int y = static_cast<int>(Raylib::Mouse::getMouseY()) - 165;

    if ((Raylib::Mouse::getMouseX() < 1600 || Raylib::Mouse::getMouseX() > 1850) || (Raylib::Mouse::getMouseY() < 40 || Raylib::Mouse::getMouseY() > 290))
        mousePos = false;
    else if (y >= 0)
        mousePos = -(x + y) >= 0 ? true : false;
    else
        mousePos = (y - x) >= 0 ? true : false;
    return Raylib::Mouse::isButtonDown(0) && mousePos;
}

bool MousePlayerInput::shouldGoToWest(void) const
{
    bool mousePos;
    int x = static_cast<int>(Raylib::Mouse::getMouseX()) - 1725;
    int y = static_cast<int>(Raylib::Mouse::getMouseY()) - 165;

    if ((Raylib::Mouse::getMouseX() < 1600 || Raylib::Mouse::getMouseX() > 1850) || (Raylib::Mouse::getMouseY() < 40 || Raylib::Mouse::getMouseY() > 290))
        mousePos = false;
    else if (y >= 0)
        mousePos = (x - y) >= 0 ? true : false;
    else
        mousePos = (x + y) >= 0 ? true : false;
    return Raylib::Mouse::isButtonDown(0) && mousePos;
}

bool MousePlayerInput::shouldGoToNorth(void) const
{
    bool mousePos;
    int x = static_cast<int>(Raylib::Mouse::getMouseX()) - 1725;
    int y = static_cast<int>(Raylib::Mouse::getMouseY()) - 165;

    if ((Raylib::Mouse::getMouseX() < 1600 || Raylib::Mouse::getMouseX() > 1850) || (Raylib::Mouse::getMouseY() < 40 || Raylib::Mouse::getMouseY() > 290))
        mousePos = false;
    else if (x >= 0)
        mousePos = -(x + y) >= 0 ? true : false;
    else
        mousePos = (x - y) >= 0 ? true : false;
    return Raylib::Mouse::isButtonDown(0) && mousePos;
}

bool MousePlayerInput::shouldGoToSouth(void) const
{
    bool mousePos;
    int x = static_cast<int>(Raylib::Mouse::getMouseX()) - 1725;
    int y = static_cast<int>(Raylib::Mouse::getMouseY()) - 165;

    if ((Raylib::Mouse::getMouseX() < 1600 || Raylib::Mouse::getMouseX() > 1850) || (Raylib::Mouse::getMouseY() < 40 || Raylib::Mouse::getMouseY() > 290))
        mousePos = false;
    else if (x >= 0)
        mousePos = (y - x) >= 0 ? true : false;
    else
        mousePos = (x + y) >= 0 ? true : false;
    return Raylib::Mouse::isButtonDown(0) && mousePos;
}

bool MousePlayerInput::shouldChangeToPrev(void) const
{
    return Raylib::Mouse::getMouseWheelMove() > 0;
}

bool MousePlayerInput::shouldChangeToNext(void) const
{
    return Raylib::Mouse::getMouseWheelMove() < 0;
}

bool MousePlayerInput::shouldSimulateAClick(void) const
{
    return Raylib::Mouse::isButtonPressed(1);
}


// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try



int catchThrowTryshouldGoToEast() {
    try
    {   MousePlayerInput test;
        test.shouldGoToEast();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldGoToWest() {
    try
    {   MousePlayerInput test;
        test.shouldGoToWest();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldGoToNorth() {
    try
    {   MousePlayerInput test;
        test.shouldGoToNorth();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldGoToSouth() {
    try
    {   MousePlayerInput test;
        test.shouldGoToSouth();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldChangeToPrev() {
    try
    {   MousePlayerInput test;
        test.shouldChangeToPrev();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldChangeToNext() {
    try
    {   MousePlayerInput test;
        test.shouldChangeToNext();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryshouldSimulateAClick() {
    try
    {   MousePlayerInput test;
        test.shouldSimulateAClick();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}