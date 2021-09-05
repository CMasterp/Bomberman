/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Font {

    public:
        /**
         * @brief Construct a new Font object
         */
        Font();

        /**
         * @brief Destroy the Font object
         */
        ~Font();

        /**
         * @brief Construct a new Font object
         *
         * @param font A Font
         */
        Font(const Font &font);

        /**
         * @brief Construct a new Font object
         *
         * @param fileName Name of file
         */
        Font(const std::string &fileName);

        /**
         * @brief Construct a new Font object
         *
         * @param fileName Name of file
         * @param fontSize An int
         * @param fontChars An int *
         * @param charCount An int
         */
        Font(const std::string &fileName, const int &fontSize, int *fontChars, const int &charCount);

        /**
         * @brief Construct a new Font object
         *
         * @param fileType A string
         * @param fileData A string
         * @param dataSize An int
         * @param fontSize An int
         * @param fontChars An int *
         * @param charsCount An int
         */
        Font(const std::string &fileType, const std::string &fileData, const int &dataSize, const int &fontSize, int *fontChars, const int &charsCount);

        /**
         * @brief Getter of Font structure (private attribute)
         *
         * @return An Font C structure
         */
        ::Font getCStruct(void) const;

        /**
         * @brief Unload Font
         */
        void unload(void) const;

        /**
         * @brief Overload of '=' operator
         *
         * @param font A const reference to a Font
         * @return A reference to Font (Font &)
         */
        Font &operator=(const Font &font);

    private:
        /**
         * @brief Set Font
         *
         * @param font A Font C Structure
         */
        void set(const ::Font &font);

        /**
         * @brief Set Font
         *
         * @param font A Font Object
         */
        void set(const Font &font);

        ::Font _font; // Font C structure
    };

#include "Font.inl"
}

#endif /* !FONT_HPP_ */
