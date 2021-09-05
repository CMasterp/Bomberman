/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Image/Image.hpp"

namespace Raylib
{
    class Window {

    public:
        /**
         * @brief Construct a new Window object
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         * @param lateInit A boolean, True if window is already init, False otherwise
         */
        Window(const int &width = 1920, const int &height = 1080, const std::string &title = "Bomberman", const bool &lateInit = false);

        /**
         * @brief Destroy the Window object
         */
        ~Window();

        /**
         * @brief Initialize window and OpenGL context
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        static void initWindow(const int &width, const int &height, const std::string &title);

        /**
         * @brief Check if KEY_ESCAPE pressed or Close icon pressed
         *
         * @return A boolean (True OR False)
         */
        static bool windowShouldClose(void);

        /**
         * @brief Close window
         */
        static void closeWindow(void);

        /**
         * @brief Set the Window Icon
         *
         * @param image Image
         */
        static void setWindowIcon(Raylib::Image image);

        /**
         * @brief Check if window is currently fullscreen
         *
         * @return
         */
        static bool isWindowFullscreen(void);

        /**
         * @brief Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
         */
        static void toggleFullscreen();
    };

#include "Window.inl"

}

#endif /* !WINDOW_HPP_ */
