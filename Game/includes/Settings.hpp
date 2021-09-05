/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

typedef enum {
    // Iron template
    IRON,
    // Snow template
    SNOW,
    // Wood template
    WOOD
} Worlds;

typedef enum {
    // Timestamp of the Game
    TIMESTAMP,
    // Number of sets
    SET_NBR,
    // ID of the current set
    SET_ID,
    // Total time of the game
    TIME_GAME,
    // Remaining time of the current set
    TIME_REMAINING,
    // Number of AIs
    AI_NBR,
    // Level of AIs
    AI_LVL,
    // Number of players
    HUMAN_NBR,
    // World template
    WORLD
} Settings;

#endif /* !SETTINGS_HPP_ */
