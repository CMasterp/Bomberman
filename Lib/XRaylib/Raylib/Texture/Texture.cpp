/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

#include "Texture.hpp"
#include "Exception/Exception.hpp"

Raylib::Texture::Texture(const std::string &fileName)
{
    _texture = ::LoadTexture(fileName.c_str());
}

Raylib::Texture::Texture(const Raylib::Image &image)
{
    _texture = ::LoadTextureFromImage(image.getCStruct());
}

Raylib::Texture::~Texture()
{
    //TODO: try it
//    unloadTexture(*this);
}


// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try
