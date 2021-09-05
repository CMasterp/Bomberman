/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** KeyboardPlayerInput
*/

#include "KeyboardPlayerInput.hpp"
#include "Exception/Exception.hpp"

KeyboardPlayerInput::KeyboardPlayerInput()
{
}

KeyboardPlayerInput::~KeyboardPlayerInput()
{
}

bool KeyboardPlayerInput::shouldGoToEast(void) const
{
    return Raylib::Keyboard::isKeyDown(263);
}

bool KeyboardPlayerInput::shouldGoToWest(void) const
{
    return Raylib::Keyboard::isKeyDown(262);
}

bool KeyboardPlayerInput::shouldGoToNorth(void) const
{
    return Raylib::Keyboard::isKeyDown(265);
}

bool KeyboardPlayerInput::shouldGoToSouth(void) const
{
    return Raylib::Keyboard::isKeyDown(264);
}

bool KeyboardPlayerInput::shouldChangeToPrev(void) const
{
    return Raylib::Keyboard::isKeyPressed(263);
}

bool KeyboardPlayerInput::shouldChangeToNext(void) const
{
    return Raylib::Keyboard::isKeyPressed(262);
}

bool KeyboardPlayerInput::shouldSimulateAClick(void) const
{
    return Raylib::Keyboard::isKeyPressed(32);
}


// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTryKeyboardException() {
    try
    {   KeyboardPlayerInput test;
        test.shouldGoToEast();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
        test.shouldGoToWest();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
        test.shouldGoToNorth();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
        test.shouldGoToSouth();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
        test.shouldChangeToPrev();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
        test.shouldChangeToNext();

    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   KeyboardPlayerInput test;
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