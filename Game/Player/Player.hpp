/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <array>
#include <utility>
#include "Animated/Animated.hpp"

typedef enum {
    P_SKATE,
    P_BOMB,
    P_PASS,
    P_FIRE,
    P_LIFE
} Powerups;

namespace Game
{

    class Player : public Animated
    {
    public:
        /**
         * @brief Construct the Player object
         */
        Player();

        /**
        * @brief Construct the Player object (Copy Constructor)
        *
        * @param name A const reference to a std::string
        * @param position A const reference to a std::pair of float
        * @param brokenWalls A const reference to a size_t
        * @param kills A const reference to a size_t
        * @param powerUps A const reference to a std::array of 5 int
        */
        Player(const std::string &name, const Raylib::Vector3 &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps);

        /**
         * @brief Construct a new Player object
         *
         * @param name the name of the character
         * @param positions the 3D positions of the character
         * @param obj_path the model path
         * @param texture_path the texture path
         * @param animation_path the animations paths
         */
        Player(const std::string &name, const int &id, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path = {}, const float &scalable = 0.6, const Raylib::Color color = Raylib::Color::White());

        /**
         * @brief Get the Name of the Player
         *
         * @return A string
         */
        std::string getName(void) const;

        /**
         * @brief Get Broken Walls by the Player
         *
         * @return A size_t
         */
        size_t getBrokenWalls(void) const;

        /**
         * @brief Get Kills by the Player
         *
         * @return A size_t
         */
        size_t getKills(void) const;

        /**
         * @brief Get PowerUps gotten by the Player
         *
         * @return An Array of 5 static_cast<int>
         */
        std::array<int, 5> getPowerUps(void) const;

        /**
         * @brief Get the player ID
         *
         * @return An int which represents the ID of the player
         */
        int getID(void) const;

        /**
         * @brief Get if the player is dead or alive
         *
         * @return bool value, true if the player is alive, false if he's is dead
         */
        bool getAlive(void) const;

        /**
         * @brief Set the name of the player
         *
         * @param name A const reference to a string
         */
        void setName(const std::string &name);

        /**
         * @brief Set the broken walls number
         *
         * @param brokenWalls A const reference to a size_t
         */
        void setBrokenWalls(const size_t &brokenWalls);

        /**
         * @brief Set the kills number
         *
         * @param kills A const reference to a size_t
         */
        void setKills(const size_t &kills);

        /**
         * @brief Set the powerUps of the player
         *
         * @param powerUps A const reference to an array of 5 int
         */
        void setPowerUps(const std::array<int, 5> &powerUps);

        /**
         * @brief Set the powerUps of the player
         *
         * @param powerUps A const reference to an array of 5 int
         */
        void increasePowerUps(const int &id_power);

        /**
         * @brief Set the powerUps of the player
         *
         * @param powerUps A const reference to an array of 5 int
         */
        void decreasePowerUps(const int &id_power);

        /**
         * @brief Set the ID of the player
         */
        void setID(const int &ID);

        /**
         * @brief Set the player dead or alive
         *
         * @param alive a const reference to a bool value
         */
        void setAlive(const bool &alive);

        /**
         * @brief Destroy the Player Entity object
         */
        virtual ~Player(void) {};

        /**
         * @brief Drop a bomb
         *
         * @return true if the player successfully drops a bomb, false otherwise
         */
        bool dropBomb(void);

        /**
         * @brief Reset a bomb
         *
         */
        void resetABomb();

    private:

        std::string _name = "Name"; // Name of the player entitiy
        size_t _brokenWalls = 0; // Amount of broken walls
        size_t _kills = 0; // Amount of kills
        int _bomb_droped;
        std::array<int, 5> _powerUps{0, 0, 0, 0, 0}; // Amount of powerUps
        int _ID; // ID of the player
        bool _alive = true; //Is alive ?
        Clock clock;
    };

    class Human : public virtual Player {

    public:

        /**
         * @brief Construct a new Player object
         *
         * @param name the name of the character
         * @param ID A const reference to a int
         * @param positions the 3D positions of the character
         * @param obj_path the model path
         * @param texture_path the texture path
         * @param animation_path the animations paths
         */
        Human(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path = "resources/players/3D/Bombermans/white_tpose.glb", const std::string &texture_path = "resources/players/3D/Bombermans/texture.png", const std::vector<std::string> &animation_path = {}, const float &scalable = 0.6, const Raylib::Color color = Raylib::Color::White());

        /**
         * @brief Get the Type object
         *
         * @return std::string
         */
        std::string getType() const override;

    };

    class AI : public virtual Player {

    public:

        /**
         * @brief Construct a new Player object
         *
         * @param name the name of the character
         * @param ID A const reference to a int
         * @param positions the 3D positions of the character
         * @param obj_path the model path
         * @param texture_path the texture path
         * @param animation_path the animations paths
         */
        AI(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path = "resources/players/3D/Bombermans/white_tpose.glb", const std::string &texture_path = "resources/players/3D/Bombermans/texture.png", const std::vector<std::string> &animation_path = {}, const float &scalable = 0.6, const Raylib::Color color = Raylib::Color::White());

        /**
         * @brief Get the Type object
         *
         * @return std::string
         */
        std::string getType() const override;

    };

#include "Player.inl"
}

/**
 * @brief Display Player content
 *
 * @param os ostream (std::cout)
 * @param obj the player
 * @return std::ostream& (std::cout)
 */
std::ostream& operator<<(std::ostream& os, const Game::Player* obj);

/**
 * @brief
 *
 * @param os ostream (std::cout)
 * @param objs the players
 * @return std::ostream& (std::cout)
 */
std::ostream& operator<<(std::ostream& os, const std::vector<Game::Player *>& objs);

#endif /* !PLAYER_HPP_ */