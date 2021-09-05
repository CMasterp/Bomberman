/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

Engine::Exception::Exception(const std::string &msg, const std::string &file, const size_t &line, const std::string &function, const std::string &info)
    : std::exception(),
    _file(file),
    _line(line),
    _function(function),
    _info(info)
{
}