/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include "IEntity.hpp"
#include "PlayerSelector/CharDictionary.hpp"

class IGraphical {

public:
    enum Scene {
        /// This scene is the main menu of our game
        MENU,
        /// This scene is the one used to choose the game mode
        GAME_MODE,
        /// This scene represents the HELP section, containing information such as how to play etc
        HELP,
        /// This scene represents the settings section
        SETTINGS,
        /// This scene is the one used to choose the players and the different game parameters
        PLAYER_CHOICE,
        /// This scene is the one used to choose map, sets and time
        MAP_CHOICE,
        /// This scene is the one used to load a game backup
        LOAD_GAME,
        /// This is the scene where the game is in progress
        IN_GAME,
        /// This is the scene where the display winner options
        VICTORY,
        /// This is the scene where the display loser options
        DEFEAT,
        /// This scene represents the end of the game
        END_GAME,
    };

    /**
     * @brief Destroy the IGraphical object
     */
    virtual ~IGraphical(void) = default;

    /**
     * @brief Check if the window should be close
     *
     * @return true if the window should close and false otherwise
     */
    virtual bool shouldCloseWindow(void) const = 0;

    /**
     * @brief This function sets the list of scores. First element of the pair is the username, the second is the score.
     *
     * @param scores A vector of pair (username, score)
     */
    virtual void setScores(const std::vector<std::pair<std::string, std::string>> &scores) = 0;

    /**
     * @brief This function sets the list of bests scores. First element of the pair is the username, the second is the score.
     *
     * @param scores A vector of pair (username, score)
     */
    virtual void setBestScores(const std::vector<std::pair<std::string, std::string>> &scores) = 0;

    /**
     * @brief This is called in a loop when the game is running. This vector contains entities that should be displayed in the game scene.
     *
     * @param gameInfos A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
     */
    virtual void updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos) = 0;

    /**
     * @brief This is called in a loop when the game is running. Sets the current informations about players and their stats. The first element of the pair
     *  is the category (e.g. Score), the second is the value (e.g. 200).
     *
     * @param info A vector of a vector all the stats by player [Player -- (NameOfStat, Value)]...
     */
    virtual void setPlayersStats(const std::vector<std::vector<std::pair<std::string, std::string>>> &info) = 0;

    /**
     * @brief Get the User Names
     *
     * @return A vector of all the users names as a const std::vector<std::string>&
     */
    virtual const std::vector<std::string> &getUserNames(void) const = 0;

    /**
     * @brief Set the User Names
     *
     * @param userNames A vector containing all the users names
     */
    virtual void setUserNames(const std::vector<std::string> &userNames) = 0;

    /**
     * @brief Get the paths to all backups files
     *
     * @return A vector of all the paths to backups files as a const std::vector<std::string>&
     */
    virtual const std::vector<std::string> &getBackups(void) const = 0;

    /**
     * @brief Get the paths to all backups files
     *
     * @param backups A vector of all the paths to backups files as a const std::vector<std::string>&
     */
    virtual void setBackups(const std::vector<std::string> &backups) = 0;

    /**
     * @brief Returns the current scene.
     *
     * @return The scene (MAIN_MENU, GAME, END_GAME...), the step where we are in the window
     */
    virtual Scene getScene(void) const = 0;

    /**
     * @brief Set the current scene.
     *
     * @param scene The scene (MAIN_MENU, GAME, END_GAME...), the step where we are in the window
     */
    virtual void setScene(const Scene &scene) = 0;

    /**
     * @brief Close window
     */
    virtual void closeWindow(void) const = 0;

    /**
     * @brief Set buffer to Draw textures
     */
    virtual void beginDrawing(void) const = 0;

    /**
     * @brief Unset buffer to Draw textures
     */
    virtual void endDrawing(void) const = 0;

    /**
     * @brief This function must display the current scene. It is used in the game loop
     */
    virtual void display(void) = 0;

    /**
     * @brief Set the Map
     *
     * @param map A const std::vector<std::string>&
     */
    virtual void setMap(std::vector<std::string> &map) = 0;

    /**
     * @brief Get the size and type of Map
     *
     * @return A pair of size_t
     */
    virtual std::pair<size_t, size_t> getMapSizeAndType() = 0;

    /**
     * @brief Set the size of Map
     *
     * @param size A size_t
     */
    virtual void setMapSize(size_t size) = 0;

    /**
     * @brief Set pointer to Load Function
     *
     * @param loadFunc A pointer to Load function in the core
     */
    virtual void setLoadFunc(std::function<void (std::string)>) = 0;

    /**
     * @brief Set pointer to Save Function
     *
     * @param saveFunc A pointer to Save function in the core
     */
    virtual void setSaveFunc(std::function<void (std::array<std::size_t, 9>, std::vector<std::string>)>) = 0;

    /**
     * @brief Set pointer to Settings Function
     *
     * @param settingsFunc A pointer to Settings function in the core
     */
    virtual void setSettingsFunc(std::function<void (std::array<std::size_t, 9>)>) = 0;

    /**
     * @brief Set the Restart Func
     *
     * @param restartFunc A pointer to Restart function in the core
     */
    virtual void setRestartFunc(std::function<void ()>) = 0;

    /**
     * @brief Get Game Settings
     *
     * @return An array of 9 size_t
     */
    virtual std::array<size_t, 9> getGameSettings() = 0;

    /**
     * @brief Set the Player Actions Func
     *
     * @param playerActionsFunc A pointer to function that manage all players actions in the game (left, right ...)
     */
    virtual void setPlayerActionsFunc(std::function<void (const size_t pos, const std::string action)>) = 0;

    /*
     * @brief Set Game Settings
     *
     * @param settings An array of 9 size_t
     */
    virtual void setGameSettings(const std::array<size_t, 9> &settings) = 0;

    /**
     * @brief Get the Players Data
     *
     * @return std::vector<CharDictionary> containing players data
     */
    virtual std::vector<CharDictionary> getPlayersData() = 0;

    /**
     * @brief Get the player controls
     *
     * @return A vector containing the player controls as a string
     */
    virtual std::vector<std::string> getPlayerControls(void) const = 0;

    /**
     * @brief Set the player controls
     *
     * @param playerControls A vector containing all the player controls as a string
     */
    virtual void setPlayerControls(const std::vector<std::string> &playerControls) = 0;

    /**
     * @brief Shake the camera
     *
     */
    virtual void cameraShake(void) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
