/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map.hpp
*/

#include <vector>
#include <string>
#include "Color/Color.hpp"
#include "Drawing/Drawing.hpp"
#include "Texture/Texture.hpp"
#include <filesystem>
#include "PlayerSelector/Player.hpp"

namespace PlayerSelector
{
    class Map
    {

    public:

        /**
         * @brief Construct a new Map object
         *
         * @param models pair of models with their scalable values
         * @param asciiMap the ascii map to print
         */
        Map(std::vector<Player> models, std::vector<std::string> &asciiMap);

        /**
         * @brief Destroy the Map object
         *
         */
        ~Map();

        /**
         * @brief Find dynamically all availables textures
         *
         * @param nb_textures a counter of all available textures
         * @return A map of all textures available
         */
        std::vector<std::vector<Texture>> findTexturesAvailable(int &nb_textures);

        /**
         * @brief Set the next map texture
         *
         */
        void next();

        /**
         * @brief Set the prev map texture
         *
         */
        void prev();

        /**
         * @brief Print the 3D Map
         *
         */
        void draw();

        /**
         * @brief Get the Map Type (Floor, Wall or Box)
         *
         * @return The map type
         */
        size_t getMapType() const;

        enum ModelMode {
            FLOOR,
            WALL,
            BOX
        };

        /**
         * @brief Get the Ascii Map
         *
         * @return The map as vector of strings
         */
        std::vector<std::string> getMap() const;

        /**
         * @brief Get the Textures object
         *
         * @return All the textures
         */
        std::vector<Texture2D> getTextures() const;

    private:
        void drawHandlingCharacters(const int &id);

        std::vector<std::vector<Texture2D>> _textures;                          // Texture
        std::vector<std::string> _charMap;                                      // The map
        std::vector<Player> _characters;                                        // Character

        Clock _clock;                                                           // The clock

        int _nbTextures;                                                        // Number of textures
        int current;                                                            // Curent texture
        float _COEF;                                                            // COEF
        float _direction;                                                       // Direction
        float _x = 0;                                                           // x position
        float _y = 0;                                                           // y position

    };
}
