/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "IEntity.hpp"
#include <memory>
#include <vector>
#include "PlayerSelector/CharDictionary.hpp"

class IGame {

public:
    /**
     * @brief Destroy the IGame object
     */
    virtual ~IGame(void) = default;

    /**
     * @brief Call this function to restart the entire game. The game must reset himself.
     */
    virtual void restart(void) = 0;

    /**
     * @brief Call this function to save the game.
     *
     * @param settings Backup Container containing the settings
     * @param playerControls Backup Container containing the player controls
     */
    virtual void saveGame(std::array<std::size_t, 9> settings,
                          std::vector<std::string> playerControls) = 0;

    /**
     * @brief Call this function to load a game.
     *
     * @param backupFilePath Backup File Path
     */
    virtual void loadGame(const std::string &backupFilePath) = 0;

    /**
     * @brief Set the User Names
     *
     * @param userNames A vector of all the users names as a const std::vector<std::string>&
     */
    virtual void setUserNames(const std::vector<std::string> &userNames) = 0;

    /**
     * @brief Set the game settings
     *
     * @param settings An array of 9 size_t
     */
    virtual void setSettings(const std::array<std::size_t, 9> &settings) = 0;

    /**
     * @brief Get the game settings
     *
     * @return An array of 9 size_t
     */
    virtual std::array<std::size_t, 9> getSettings(void) const = 0;

    /**
     * @brief Getter for the score
     *
     * @return A array of pair (Player, Score) of the current game
     */
    virtual const std::vector<std::pair<std::string, std::string>> &
    getScores(void) = 0;

    /**
     * @brief Get the Entities
     *
     * @return Return all the game's entities to display in a const std::vector<std::shared_ptr<Thing>>&
     */
    virtual const std::vector<std::shared_ptr<IEntity>> &
    getEntities(void) const = 0;

    /**
     * @brief Get the Players Stats
     *
     * @return A vector of a vector all the stats by player [Player -- (NameOfStat, Value)]...
     */
    virtual const std::vector<std::vector<std::pair<std::string, std::string>>> &
    getPlayersStats(void) = 0;

    /**
     * @brief updateGame function should be called in a loop. It's used to advance the game and update all logic.
     * The game must manage time on it's own.
     */
    virtual void updateGame(void) = 0;

    /**
     * @brief Get the User Names
     *
     * @return A vector of all the users names as a const std::vector<std::string>&
     */
    virtual const std::vector<std::string> &getUserNames(void) const = 0;

    /**
     * @brief Check if the game is over
     * @return bool which indicate if the game is over
     */
    virtual bool isGameOver(void) const = 0;

    /**
     * @brief Get the name of the game
     * @return Name of the game
     */
    virtual const std::string &getGameName(void) const = 0;

    /**
     * @brief Get the Map
     */
    virtual std::vector<std::string> &getMap(const size_t &size) = 0;

    /**
     * @brief Get the Map
     */
    virtual std::vector<std::string> &getMap() = 0;

    /**
     * @brief Set the Map Type
     *
     * @param mapType A size_t
     */
    virtual void setMapType(const std::size_t &mapType) = 0;

    /**
     * @brief Do A player Action
     *
     * @param playerID ID of player
     * @param action Action in a string
     */
    virtual void
    doPlayerAction(const size_t playerID, const std::string action) = 0;

    /**
     * @brief Set the current Players data
     *
     * @param playersData Dictionary of the players' data
     */
    virtual void setPlayers(const std::vector<CharDictionary> &playersData) = 0;

    /**
     * @brief Get the player controls
     *
     * @return A vector containing the player controls as a string
     */
    virtual const std::vector<std::string> &getPlayerControls(void) const = 0;

    /**
     * @brief Run the AIs
     */
    virtual void runAI(void) = 0;

    /**
     * @brief Check if the camera should shake
     *
     * @return true if should
     * @return false otherwise
     */
    virtual bool isCameraShaking() = 0;
};

#endif /* !IGAME_HPP_ */
