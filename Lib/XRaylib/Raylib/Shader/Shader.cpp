/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Shader
*/

#include "Shader.hpp"

Raylib::Shader::Shader()
{
}

Raylib::Shader::~Shader()
{
    Raylib::Shader::unloadShader(*this);
}

Raylib::Shader::Shader(::Shader const &shader)
{
    set(shader);
}

Raylib::Shader::Shader(const std::string& vsFileName, const std::string& fsFileName)
{
    set(::LoadShader(vsFileName.c_str(), fsFileName.c_str()));
}