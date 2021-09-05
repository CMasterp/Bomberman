/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Color/Color.hpp"

namespace Raylib
{
    class Text {

    public:
        /**
         * @brief Construct a new Text object
         */
        Text();

        /**
         * @brief Destroy the Text object
         */
        ~Text();

        /**
         * @brief Draw text (using default font)
         *
         * @param title A string
         * @param posX An int
         * @param posY An int
         * @param fontSize An int
         * @param color A Color
         */
        static void drawText(const std::string &title, const int &posX, const int &posY, const int &fontSize, const Color &color);

        /**
         * @brief Draw text using custom font
         *
         * @param font A string
         * @param text A string
         * @param position A pair of int
         * @param fontSize A float
         * @param spacing A float
         * @param color A Color
         */
        static void drawTextEx(const std::string &font, const std::string &text, const std::pair<int, int> &position, const float &fontSize, const float &spacing, const Color &tint);

        /**
         * @brief Measure string width for default font
         *
         * @param text A string
         * @param fontSize An int
         * @return An int
         */
        static int measureText(const std::string &text, const int &fontSize);

        /**
         * @brief Check if two text string are equal
         *
         * @param text1 A string
         * @param text2 A string
         * @return A boolean
         */
        static bool textIsEqual(const std::string &text1, const std::string &text2);

        /**
         * @brief Check if two text string are equal
         *
         * @param text A string
         * @return An int
         */
        static int textLength(const std::string &text);
    };

#include "Text.inl"
}

#endif /* !TEXT_HPP_ */
