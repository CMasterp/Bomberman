/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** CharDictionary
*/

#ifndef CHARDICTIONARY_HPP_
#define CHARDICTIONARY_HPP_

#include <string>
#include <vector>
#include "Color/Color.hpp"

struct CharDictionary
{
    std::string obj;                                                            // The object
    std::string texture;                                                        // Texture of the object
    float scalable;                                                             // Scale of the object
    std::string name;                                                           // Name
    Raylib::Color color;                                                        // Color
    std::vector<std::string> animations;                                        // List of the animation of the object
};

#endif /* !CHARDICTIONARY_HPP_ */
