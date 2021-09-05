/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Clock.hpp
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

class Clock
{
public: //TODO: DOC
    Clock();
    ~Clock();

    float getElapsedTime();
    bool doesTimeElapsed(const float &time, const bool &reset = true);

private:
    float _start;
};

#endif