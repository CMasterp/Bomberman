/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Font
*/

#include "Font.hpp"

//TODO: Remake

Raylib::Font::Font()
{
    set(::GetFontDefault());
}

Raylib::Font::~Font()
{
    ::UnloadFont(_font);
}

Raylib::Font::Font(const Font &font)
{
    set(font);
}

Raylib::Font::Font(const std::string &fileName)
{
    set(::LoadFont(fileName.c_str()));
}

Raylib::Font::Font(const std::string &fileName, const int &fontSize, int *fontChars, const int &charCount)
{
    set(::LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
}

Raylib::Font::Font(const std::string &fileType, const std::string &fileData, const int &dataSize, const int &fontSize, int *fontChars, const int &charsCount)
{
    set(::LoadFontFromMemory(fileType.c_str(), (const unsigned char *)fileData.c_str(), dataSize, fontSize, fontChars, charsCount));
}