/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.hpp
*/

#ifndef PLAYERSELECTOR_SELECTOR
#define PLAYERSELECTOR_SELECTOR

#include "Camera3D/Camera3D.hpp"
#include "Texture/Texture.hpp"
#include "raylib.h"
#include "PlayerSelector/Player.hpp"
#include "PlayerSelector/Map.hpp"
#include "PlayerSelector/CharDictionary.hpp"
#include <filesystem>

#define POS_1 Raylib::Vector3(-3.25, -0.15, 0)
#define POS_2 Raylib::Vector3(-1.10, -0.15, 0)
#define POS_3 Raylib::Vector3(1.15, -0.15, 0)
#define POS_4 Raylib::Vector3(3.35, -0.15, 0)

namespace PlayerSelector
{

    class Selector
    {
    public:
        /**
         * @brief Construct a new Selector object
         *
         */
        Selector();

        /**
         * @brief Destroy the Selector object
         *
         */
        ~Selector();

        /**
         * @brief Toggle Mods Available
         *
         */
        void toggleModsAvailable();

        /**
         * @brief Check if mods are available
         *
         * @return true if mods are available
         * @return false otherwise
         */
        bool isModsAvailable();

        /**
         * @brief Load for the first time a character
         *
         */
        void firstLoad();

        /**
         * @brief Add a character
         *
         */
        void load();

        /**
         * @brief Remove a character
         *
         * @param id character's id to remove
         */
        void unload(const int &id);

        /**
         * @brief Get characters Models
         *
         * @return a vector of pairs of Model withe their scalable value
         */
        std::vector<std::pair<Model, float>> getModels() const;

        /**
         * @brief Get the Bloc Textures object
         *
         * @return a vector of textures
         */
        std::vector<Texture2D> getBlocTextures() const;

        /**
         * @brief Remove all characters
         *
         */
        void unloadAll();

        /**
         * @brief Display all the players
         *
         */
        void drawPlayers();

        /**
         * @brief Init the 3D maps from the Ascii one
         *
         * @param asciiMap the ascii map
         */
        void initMaps(std::vector<std::string> asciiMap);

        /**
         * @brief Display the 3D map
         *
         * @param asciiMap a new ascii map
         */
        void drawMaps();

        /**
         * @brief Get the Ascii Map
         *
         * @return the ascii map
         */
        std::vector<std::string> getMap() const;

        /**
         * @brief Unload map
         *
         */
        void endMaps();

        /**
         * @brief Select the next map textures
         *
         */
        void nextMap();

        /**
         * @brief Select the previous map textures
         *
         */
        void prevMap();

        /**
         * @brief Select the next character
         *
         * @param player id of player who want to change the character
         */
        void next(const int &player);

        /**
         * @brief Select the next character
         *
         * @param player id of player who want to change the character
         */
        void prev(const int &player);

        /**
         * @brief Get the Map Type
         *
         * @return map type (Floor, Wall, or Box)
         */
        size_t getMapType() const;

        /**
         *  //TODO: DOC
         * @return
         */
        std::vector<CharDictionary> getPlayerData() const;

        /**
         * //TODO: DOC
         */
        std::vector<Raylib::Vector3> POS;

        /**
         * //TODO: DOC
         * @param index
         * @return
         */
        PlayerSelector::Player &operator[](const int &index);
        /**
         * //TODO: DOC
         * @param index
         * @return
         */
        const PlayerSelector::Player &operator[](const int &index) const;

    private:

        /**
         * @brief Preload the 4 first characters
         *
         * @param dictionary the players available dictionary
         */
        void preloadBasicsCharacters();

        /**
         * @brief Find if some DLC characters are available and add them to the dictionary
         *
         * @param dictionary the players available dictionary
         */
        void findModsCharacters();

        /**
         * @brief update Characters z Rotation axis
         *
         */
        void updateRotationAxis();

        Raylib::Camera3D *camera;                                               // The camera
        std::vector<PlayerSelector::Player> _players;                           // Players
        int _nbCharacters;                                                      // Number of character
        std::vector<CharDictionary> _charaDictionary;                           // Character dictionnary
        Map *_map;                                                              // Map
        std::vector<std::string> _asciiMap = {""};                              // asciiMap

        bool _modAvailable;                                                     // Is mod available

        float _rotationAxis;                                                    // Degree of rotation
    };
}

#endif