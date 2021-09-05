/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

#include "Window.hpp"
#include "Exception/Exception.hpp"


Raylib::Window::Window(const int &width, const int &height, const std::string &title, const bool &lateInit)
{
    if (!lateInit) {
        ::InitWindow(width, height, title.c_str());
    }
}

Raylib::Window::~Window()
{
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrywindowShouldClose() {
    try
    {   Raylib::Window test;
        test.windowShouldClose();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrycloseWindow() {
    try
    {   Raylib::Window test;
        test.closeWindow();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrysetWindowIcon() {
    try
    {   Raylib::Window test;
        Raylib::Image image;
        test.setWindowIcon(image);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisWindowFullscreen() {
    try
    {   Raylib::Window test;
        test.isWindowFullscreen();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrytoggleFullscreen() {
    try
    {   Raylib::Window test;
        test.toggleFullscreen();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}