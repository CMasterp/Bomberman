/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Animated/Animated.hpp"
#include "Player/Player.hpp"

namespace Game
{
    class Bomb : public Animated
    {
    public:

        /**
         * @brief Construct a new Bomb object
         *
         * @param positions
         * @param fire
         * @param players
         * @param function
         */
        Bomb(const Raylib::Vector3 &positions, const int &fire, std::vector<std::shared_ptr<Game::Player>> &players, std::function<void (size_t)> function, Game::Player &player);

        /**
         * @brief Destroy the Bomb object
         *
         */
        ~Bomb();

        /**
         * @brief Get the Type object
         *
         * @return A std::string
         */
        std::string getType() const override;

        /**
         * @brief Make the bomb explose
         *
         */
        int makeExplode();

        /**
         * @brief check if bomb is exploding
         *
         * @return true
         * @return false
         */
        bool isExploding();

        /**
         * @brief check if bomb has exploded
         *
         * @return true
         * @return false
         */
        bool hasExplode();

        /**
         * @brief draw the bomb entity
         *
         */
        void drawEntity() override;

        /**
         * @brief update the bom status
         *
         */
        void update();

        /**
         * @brief Set the Bombzone object
         *
         * @param map
         */
        void setBombzone(std::vector<std::string> map);

        /**
         * @brief Set the Player object
         *
         * @param players A vector of shared_ptr of Players
         */
        void setPlayers(std::vector<std::shared_ptr<Game::Player>> players);

        /**
         * @brief Increase the walls breaked value to the player owner of the bomb
         *
         */
        void increasePlayerWall();

    private:
        Clock clock;
        bool _explosing;
        bool _exploded;
        int _fire;
        std::pair<int, int> _bZoneX;
        std::pair<int, int> _bZoneY;
        std::vector<std::shared_ptr<Game::Player>> &_players;
        std::function<void (size_t)> _pointerToSetPlayer; // pointer to function setPlayers
        Game::Player& _reseter; //pointer to reset bomb to the player who drops this bomb
    };

#include "Bomb.inl"
}

#endif /* !BOMB_HPP_ */
