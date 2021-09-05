/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Clock.cpp
*/

#include "Clock.hpp"
#include "Exception/Exception.hpp"

Clock::Clock()
        :_start(clock())
{

}

Clock::~Clock()
{

}

bool Clock::doesTimeElapsed(const float &time, const bool &reset)
{
    bool res = false;

    if (static_cast<float>(clock() - _start) / CLOCKS_PER_SEC >= time)
    {
        res = true;
        if (reset)
            _start = clock();
    }
    return res;
}

float Clock::getElapsedTime()
{
    return static_cast<float>(clock() - _start / CLOCKS_PER_SEC);
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydoesTimeElapsed() {
    try
    {   Clock test;
        float time;
        bool reset;
        test.doesTimeElapsed(time,reset);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetElapsedTime() {
    try
    {   Clock test;
        test.getElapsedTime();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}