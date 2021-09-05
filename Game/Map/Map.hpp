/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include <iostream>
#include <time.h>

// Borders
#define BORDER 2
#define EDGE 'E'

// Walls
#define SOLID_WALL 'W'
#define BREAK_WALL 'M'
#define EMPTY_SPACE '*'

// Players
#define PLAYER_ONE '1'
#define PLAYER_TWO '2'
#define PLAYER_THREE '3'
#define PLAYER_FOUR '4'
#define HUMAN 'H'
#define ARTIFICIAL_INTELLIGENCE 'A'

// Power-ups
#define WALL_PASS 'P'
#define FIRE 'F'
#define SKATE 'S'
#define BOMB_UP 'B'

namespace Game
{
    class Map
    {
    public:
        /**
        * @brief Construct the Map object
        */
        Map();

        /**
        * @brief Construct the Map object (Copy Constructor)
        *
        * @param width Width of the map
        * @param height Height of the map
        * @param playersNumber Number of players in the map (first: human number, second: AI number)
        */
        Map(const size_t &width, const size_t &height, const std::pair<size_t, size_t> &playersNumber);

        /**
        * @brief Destroy the Map object
        */
        ~Map();

        /**
         * @brief Getter for map width
         *
         * @return Width of the map (size_t)
         */
        size_t getWidth(void) const;

        /**
         * @brief Getter for map height
         *
         * @return Height of the map (size_t)
         */
        size_t getHeight(void) const;

        /**
         * @brief Setter for map width
         *
         * @param width A const reference to an size_t
         */
        void setWidth(const size_t width);

        /**
         * @brief Setter for map height
         *
         * @param height A const reference to an size_t
         */
        void setHeight(const size_t height);

        /**
         * @brief Getter for map
         *
         * @return The map (a vector of vectors of chars)
         */
        std::vector<std::string> getMap(void) const;

        /**
         * @brief Setter for map
         *
         * @param map The new map (a vector of strings)
         */
        void setMap(const std::vector<std::string> &map);

        /**
         * @brief Dump the map
         */
        void dump(void) const;

        /**
         * @brief Set the Players Areas in the map
         *
         * @param areaSize A const reference to a size_t
         */
        void setPlayersAreas(const size_t &areaSize);

        /**
         * @brief Overwritting of assignment operator
         *
         * @param map The map to copy
         * @return Map& A new map instance
         */
        Map &operator=(const Map &map);

    private:
        size_t _width; // Width of the map
        size_t _height; // Height of the map
        std::pair<size_t, size_t> _playersNumber; // Number of players in the map (first: human number, second: AI number)
        std::vector<std::string> _map; // Map

        /**
         * @brief Create the map
         */
        void create(void);

        /**
         * @brief Fill the map with a specific character
         *
         * @param character A const reference to a character
         */
        void fill(const char &character);

        /**
         * @brief Maze the map
         */
        void maze(void);

        /**
         * @brief Place the borders of the map
         */
        void placeBorders(void);

        /**
         * @brief Place solid walls
         */
        void placeSolidWalls(void);

        /**
         * @brief Place the players in the map
         */
        void placePlayers(void);
    };

#include "Map.inl"
}

#endif /* !MAP_HPP_ */
