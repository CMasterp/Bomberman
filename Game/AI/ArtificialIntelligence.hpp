/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

#ifndef ARTIFICIALINTELLIGENCE_HPP_
#define ARTIFICIALINTELLIGENCE_HPP_

#include "Player/Player.hpp"
#include "Bomberman/Bomberman.hpp"
#include "Astar.hpp"

namespace Game
{
    class ArtificialIntelligence
    {
    public:
        /**
         * @brief Construct a new ArtificialIntelligence object
         *
         * @param playerActionsFunc A pointer to function that manage all players actions in the game (left, right...)
         * @param AIs A vector of AI objects
         * @param entities A vector of targets entities objects
         * @param map The game map
         * @param level The AI level
         */
        ArtificialIntelligence(std::function<void (const size_t pos, const std::string action)> playerActionsFunc, const std::vector<AI> &AIs, std::vector<std::shared_ptr<IEntity>> entities, const std::vector<std::string> &map, const size_t &level);

        /**
         * @brief Run the AI algorithm
         */
        void run(void) const;

    private:
        std::vector<AI> _AIs; // A vector of AI objects
        std::vector<std::shared_ptr<IEntity>> _entities; // A vector of entities targets objects
        std::vector<std::string> _map; // The game map
        size_t _level; // The AI level
        std::function<void (const size_t pos, const std::string action)> _playerActionsFunc; // Pointer to playerActionsFunc

        /**
         * @brief Calcul the heuristic distance between two points (Euclidean Distance)
         *
         * @param start Starting point
         * @param end Ending point
         * @return float - The Euclidean distance between the 2 points
         */
        float calculateDistance(const Point &start, const Point &end) const;

        /**
         * @brief Convert a point into an action ("goEast", "goNorth", "goSouth", "goWest", "dropBomb")
         *
         * @param point The point to convert
         * @return std::string - The action
         */
        std::string convertPointIntoAction(const std::pair<int, int> &point) const;
    };

#include "ArtificialIntelligence.inl"
}

#endif /* !ARTIFICIALINTELLIGENCE_HPP_ */
