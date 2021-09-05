/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** main
*/

#include <iostream>
#include "Core/Core.hpp"

int main(void) {
    try {
        Engine::Core core;
        core.run();
    } catch (const std::exception &exc) {
        std::cerr << exc.what();
        std::cerr << "Error !! I catch something !" << ": " << exc.what() << " :" << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}