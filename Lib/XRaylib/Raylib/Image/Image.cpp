/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Image
*/

#include "Image.hpp"

Raylib::Image::Image()
{
}

Raylib::Image::Image(const Image &image)
{
    set(image);
}

Raylib::Image::Image(const std::string &fileName)
{
    _image = ::LoadImage(fileName.c_str());
}

Raylib::Image::Image(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize)
{
    _image = ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

Raylib::Image::~Image()
{
    ::UnloadImage(_image);
}