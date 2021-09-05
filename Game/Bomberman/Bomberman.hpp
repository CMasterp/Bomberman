/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include <map>
#include "Interfaces/IGame.hpp"
#include "Powerups/Powerups.hpp"
#include "Map/Map.hpp"
#include "Save/Save.hpp"
#include "MotionlessEntity/MotionlessEntity.hpp"
#include "Bomb/Bomb.hpp"
#include "AI/ArtificialIntelligence.hpp"
#include "AI/Astar.hpp"
#include "CFunctions.hpp"
#include "Score/Score.hpp"

namespace Game
{
    class Bomberman : public IGame {

    public:

        /**
         * @brief Construct a new Bomberman object
         */
        Bomberman();

        /**
         * @brief Destroy the Bomberman object
         */
        ~Bomberman() override;

        /**
         * @brief Call this function to restart the entire game. The game must reset himself.
         */
        void restart(void) override;

        /**
         * @brief Call this function to save the game.
         *
         * @param settings Backup Container containing the settings
         * @param playerControls Backup Container containing the player controls
         */
        void saveGame(std::array<std::size_t, 9> settings, std::vector<std::string> playerControls) override;

        /**
         * @brief Call this function to load a game.
         *
         * @param backupFilePath Backup File Path
         */
        void loadGame(const std::string &backupFilePath) override;

        /**
         * @brief Set the User Names
         *
         * @param userNames A vector of all the users names as a const std::vector<std::string>&
         */
        void setUserNames(const std::vector<std::string> &userNames) override;

        /**
         * @brief Set the game settings
         *
         * @param settings An array of 9 size_t
         */
        void setSettings(const std::array<std::size_t, 9> &settings) override;

        /**
         * @brief Get the game settings
         *
         * @return An array of 9 size_t
         */
        std::array<std::size_t, 9> getSettings(void) const override;

        /**
         * @brief Getter for the score
         *
         * @return A array of pair (Player, Score) of the current game
         */
        const std::vector<std::pair<std::string, std::string>> &getScores(void) override;

        /**
         * @brief Get the Entities
         *
         * @return Return all the game's entities to display in a const std::vector<std::shared_ptr<Thing>>&
         */
        const std::vector<std::shared_ptr<IEntity>> &getEntities(void) const override;

        /**
         * @brief Get the Players Stats
         *
         * @return All the stats [PlayerName -- (NameOfStat, Value)] in a vector of vector
         */
        const std::vector<std::vector<std::pair<std::string, std::string>>> &getPlayersStats(void) override;

        /**
         * @brief Operates randomly a drop of an item when a block is break
         *
         * @param pos position where to display the item
         */
        void randomDropItem(const Raylib::Vector3 &pos);

        /**
         * @brief Erase all entities on the scope of a bomb explosion
         *
         */
        void eraseEntitiesOnBomb(const std::pair<int, int> &pos);

        /**
         * @brief Check if a player is hit by a bomb
         *
         * @param pos position of the bomb
         * @param posX x position of the player
         * @param posY y position of the player
         * @return true if the player is hit
         * @return false otherwise
         */
        bool playerGotHit(const std::pair<int, int> &pos, const float &posX, const float &posY) const;

        /**
         * @brief
         *
         * @param c character to set
         * @param rad reach of fire
         * @param pos position of the bomb
         */
        void setCharOnRadius(const char &c, const int &rad, std::pair<int, int> pos, Game::Bomb &bomb);

        /**
         * @brief Manage the bomb explosion
         *
         */
        void bombExplosion(Game::Bomb &bomb, const size_t &index);

        /**
         * @brief updateGame function should be called in a loop. It's used to advance the game and update all logic.
         * The game must manage time on it's own.
         */
        void updateGame(void) override;

        /**
         * @brief Check if the game is over
         * @return bool which indicate if the game is over
         */
        bool isGameOver(void) const override;

        /**
         * @brief Get the name of the game
         * @return Name of the game
         */
        const std::string &getGameName(void) const override;

        /**
         * @brief This function is to init all entities (_entites)
         */
        void initEntities();

        /**
         * @brief This function is to init all player(s) stats
         */
        void initPlayersStats();

        /**
         * @brief This function is to update state of all entities (_entites)
         */
        void updateEntities();

        /**
         * @brief This function is to update score(s) of player(s)
         */
        void updateScores();

        /**
         * @brief This function is to update player(s) stats
         */
        void updatePlayersStats();

        /**
         * @brief Get the Map
         */
        std::vector<std::string> &getMap(const size_t &size) override;

        /**
         * @brief Get the Map
         */
        std::vector<std::string> &getMap() override;

        /**
         * @brief Get the User Names
         *
         * @return A vector of all the users names as a const std::vector<std::string>&
         */
        const std::vector<std::string> &getUserNames(void) const override;

        /**
         * @brief Set the Map Type
         *
         * @param mapType A size_t
         */
        void setMapType(const std::size_t &mapType) override;

        /**
         * @brief Get the player controls
         *
         * @return A vector containing the player controls as a string
         */
        const std::vector<std::string> &getPlayerControls(void) const override;

        /**
         * @brief Do A player Action
         *
         * @param playerID ID of the Player (Human or AI)
         * @param action Action in a string ["goEast", "goNorth", "goSouth", "goWest", "dropBomb"]
         */
        void doPlayerAction(const size_t playerID, const std::string action) override;

        /**
         * @brief Verify and update when a player is on an item
         *
         * @param player the player
         */
        void handleIfPlayerIsNearAnItem(Player &player);

        /**
         * @brief drop bombs on command
         *
         */
        void doDropBomb(const size_t &playerID, std::pair<int, int> position);

        /**
         * @brief find the player
         *
         */
        Game::Player &findPlayer(const size_t &id);

        /**
         * @brief check the current position of player
         *
         * @param action
         * @param player
         * @return true
         * @return false
         */
        bool checkPlayerPosition(const std::string action, Player &player);

        /**
         * @brief check if the current player position passes
         *
         * @param action
         * @param y
         * @param x
         * @return true
         * @return false
         */
        bool checkPlayerPositionPass(const std::string action, const int &y, const int &x);

        /**
         * @brief updates the map
         *
         * @param playerPos
         * @param y
         * @param x
         */
        void updateMap(const std::pair<int, int>  &playerPos, const int &y, const int &x);

        /**
         * @brief Set the current Players data
         *
         * @param playersData Dictionary of the players' data
         */
        void setPlayers(const std::vector<CharDictionary> &playersData) override;

        /**
         * @brief Set the display of the player
         *
         * @param position index
         */
        void setPlayerShouldDisplay(size_t position);

        /**
         * @brief Run the AIs
         */
        void runAI(void) override;

        /**
         * @brief Get positions of all the entities with a specific type
         *
         * @return std::vector<Game::Point> - A vector containing the required entities positions
         */
        template<typename T>
        std::vector<std::pair<int, int>> getEntitiesPositions(void) const;

        /**
         * @brief Get positions of all the entities with a specific type
         *
         * @return std::vector<Game::Point> - A vector containing the required entities positions
         */
        template<typename T>
        std::vector<T*> getEntitiesData(void) const;

        /**
         * @brief Place entities in the map
         *
         * @param entitiesPos A vector of the required entities positions
         * @param c The character to place at entities slots
         * @return std::vector<std::string> - The new map containing the entities representing by c
         */
        std::vector<std::string> placeEntitiesOnMap(const std::vector<std::pair<int, int>> &entitiesPos, const char &c) const;

        /**
         * @brief Check if the camera should shake
         *
         * @return true if should
         * @return false otherwise
         */
        bool isCameraShaking() override;

    private:
        std::array<std::size_t, 9> _settings; // Game settings
        std::vector<std::string> _map; // Game map
        std::size_t _mapType;                             // A size_t that represents map type
        std::vector<std::vector<std::pair<std::string, std::string>>> _playersStats; // A vector of vector all the stats [Player -- (NameOfStat, Value)]...
        std::vector<std::pair<std::string, std::string>> _scores;                 // A vector of pair (username, score)
        std::vector<std::shared_ptr<IEntity>> _entities;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
        std::vector<std::shared_ptr<Game::Player>> _sharedPlayers;                     // A vector of a shared pointer for Players

        bool _isALoad = false;                       // A load
        int _reinit = 0;                            // A int to know if we should reinit entities
        bool _gameOver = false;                             // A boolean to know if the game is over or not
        bool _isPaused;                             // A boolean to know if the game is in pause or not
        std::string _gameName;                      // A string that represents the game name
        std::vector<std::string> _userNames;        // A vector of all the users names
        std::vector<CharDictionary> _players;
        std::vector<std::string> _playerControls; // A vector of all the players control as a string
        Clock _aiClock; // AI clock to avoid too fast AIs (runtime...)
        bool _isCameraShaking = false;
        Clock _CamShakeClock;
    };
}

#include "Bomberman.inl"

#endif /* !BOMBERMAN_HPP_ */