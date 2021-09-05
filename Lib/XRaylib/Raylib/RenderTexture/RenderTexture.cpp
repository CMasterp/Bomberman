/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RenderTexture
*/

#include "RenderTexture.hpp"

Raylib::RenderTexture::RenderTexture()
{
}

Raylib::RenderTexture::~RenderTexture()
{
    unloadRenderTexture(*this);
}
