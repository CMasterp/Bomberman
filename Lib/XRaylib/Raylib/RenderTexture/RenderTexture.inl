/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** RenderTexture
*/

#include "RenderTexture.hpp"

inline Raylib::RenderTexture &Raylib::RenderTexture::operator=(const RenderTexture &rendertexture)
{
    set(rendertexture);
    return *this;
}

inline ::RenderTexture Raylib::RenderTexture::getCStruct(void) const
{
    return _rendertexture;
}

inline void Raylib::RenderTexture::set(const ::RenderTexture &rendertexture)
{
    _rendertexture = rendertexture;
}

inline void Raylib::RenderTexture::set(const RenderTexture &rendertexture)
{
    _rendertexture = rendertexture._rendertexture;
}

inline void Raylib::RenderTexture::BeginTextureMode(RenderTexture target) const
{
    ::BeginTextureMode(target.getCStruct());
}

inline void Raylib::RenderTexture::EndTextureMode(void) const
{
    ::EndTextureMode();
}

inline Raylib::RenderTexture Raylib::RenderTexture::loadRenderTexture(int const &width, int const &height)
{
    _rendertexture = ::LoadRenderTexture(width, height);
    return *this;
}

inline void Raylib::RenderTexture::unloadRenderTexture(RenderTexture const &target) const
{
    ::UnloadRenderTexture(target.getCStruct());
}
