/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Shader
*/

#include "Shader.hpp"

inline ::Shader Raylib::Shader::getCStruct(void) const
{
    return _shader;
}

inline void Raylib::Shader::set(const ::Shader &shader)
{
    _shader = shader;
}

inline void Raylib::Shader::set(const Shader &shader)
{
    _shader = shader._shader;
}

inline Raylib::Shader &Raylib::Shader::operator=(const Shader &shader)
{
    set(shader);
    return *this;
}

inline void Raylib::Shader::beginShaderMode(Shader const &shader) const
{
    return ::BeginShaderMode(shader._shader);
}

inline void Raylib::Shader::endShaderMode(void) const
{
    return ::EndShaderMode();
}

inline Raylib::Shader Raylib::Shader::loadShader(const char *vsFileName, const char *fsFileName) const
{
    return ::LoadShader(vsFileName, fsFileName);
}

inline Raylib::Shader Raylib::Shader::loadShaderFromMemory(const char *vsCode, const char *fsCode) const
{
    return ::LoadShaderFromMemory(vsCode, fsCode);
}

inline int Raylib::Shader::getShaderLocation(Shader const &shader, const char *uniformName) const
{
    return ::GetShaderLocation(shader._shader, uniformName);
}

inline int Raylib::Shader::getShaderLocationAttrib(Shader const &shader, const char *attribName) const
{
    return ::GetShaderLocationAttrib(shader._shader, attribName);
}

inline void Raylib::Shader::setShaderValue(Shader const &shader, int const &locIndex, const void *value, int const &uniformType) const
{
    return ::SetShaderValue(shader._shader, locIndex, value, uniformType);
}

inline void Raylib::Shader::setShaderValueV(Shader const &shader, int const &locIndex, const void *value, int const &uniformType, int const &count) const
{
    return ::SetShaderValueV(shader._shader, locIndex, value, uniformType, count);
}

inline void Raylib::Shader::setShaderValueMatrix(Shader const &shader, int const &locIndex, Matrix const &mat) const
{
    return ::SetShaderValueMatrix(shader.getCStruct(), locIndex, mat);
}

inline void Raylib::Shader::setShaderValueTexture(Shader const &shader, int const &locIndex, Texture2D const &texture) const
{
    return SetShaderValueTexture(shader.getCStruct(), locIndex, texture);
}

inline void Raylib::Shader::unloadShader(Shader shader) const
{
    return ::UnloadShader(shader.getCStruct());
}