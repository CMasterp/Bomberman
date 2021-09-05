/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.hpp
*/

#ifndef PLAYERSELECTOR_PLAYER
#define PLAYERSELECTOR_PLAYER

#include "raylib.h"
#include "Texture/Texture.hpp"
#include "Vector3/Vector3.hpp"
#include "Clock.hpp"
#include <cmath>
#include "CharDictionary.hpp"

namespace PlayerSelector
{
    class Player
    {
    public:

        /**
         * @brief Construct a new Player object
         *
         * @param obj model path
         * @param texture texture path
         * @param scalable scalable value
         * @param idCharacter id of the character
         * @param name name of the character
         * @param color main color of the character
         * @param animations strings vector of animations'path
         */
        Player(const std::string &obj, const std::string &texture, const float &scalable, const int &idCharacter, const std::string &name, const Raylib::Color &color = Raylib::Color::White(), const std::vector<std::string> &animations = {});

        /**
         * @brief Destroy the Player object
         *
         */
        ~Player();

        /**
         * @brief Display the character
         *
         * @param rotation rotation value (if there's not animations)
         * @param pos position to display the character
         */
        void draw(const float &rotation, const Raylib::Vector3 &pos);

        /**
         * @brief Display the character on the map selector
         *
         * @param pos position to display the character
         */
        void drawForMaps(const float &rotation, const Raylib::Vector3 &pos);

        /**
         * @brief Get the character's Id
         *
         * @return the id
         */
        int getId(void) const;

        /**
         * @brief Get the Name
         *
         * @return the character's name
         */
        const std::string getName() const;

        /**
         * @brief Get the Char Dictionary object
         *
         * @return const CharDictionary
         */
        const CharDictionary getCharDictionary() const;

        /**
         * @brief Get the Model
         *
         * @return a pair of the Model and its scalable value
         */
        std::pair<Model, float> getModel() const;

    private:
        std::string _name;                                      // The player name
        int _idCharacter;                                       // Id of the skin
        float _scalable;                                        // Size of the scale
        Model _persoModel;                                      // Model of the player
        Raylib::Texture _persoTexture;                          // Texture for the model of the player
        Raylib::Color _color;                                   // Color of the player
        std::vector<ModelAnimation> _animations;                // All the animation of the player

        std::string _perso_path;                                // Path to the player model
        std::string _texture_path;                              // Path to the texture
        std::vector<std::string> _animations_path;              // List of path to the animations

        Clock clock;                                            // The player clock
        int counter;                                            // Counter
    };

} // namespace PlayerSelector

#endif