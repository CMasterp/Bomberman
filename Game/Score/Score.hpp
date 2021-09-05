/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include "Player/Player.hpp"
#include "includes/Settings.hpp"

namespace Game
{
    class Score
    {
    public:
        /**
        * @brief Construct the Score object (Copy Constructor)
        *
        * @param settings A const reference to an array of 9 size_t
        * @param player A const reference to Class Player
        */
        Score(const std::array<std::size_t, 9> &settings, const Game::Player *player);

        /**
        * @brief Destroy the Score object
        */
        ~Score();

        /**
         * @brief Get the Score of the Player
         *
         * @return A size_t
         */
        size_t getScore() const;

        /**
         * @brief Set the Score of the Player
         *
         * @param score A const reference to a size_t
         */
        void setScore(size_t const &score);

    private:
        std::array<std::size_t, 9> _settings; // An array of 9 size_t
        size_t _score; // Player score (size_t)

        /**
         * @brief Get the mulitiplicator of Player's score
         *
         * @return A float
         */
        float getCoefficient(void) const;
    };

#include "Score.inl"
}
#endif /* !SCORE_HPP_ */
