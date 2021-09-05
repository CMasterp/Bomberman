/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

#ifndef MOTIONLESSENTITY_HPP_
#define MOTIONLESSENTITY_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include <map>
#include "Interfaces/IEntity.hpp"
#include "Drawing/Drawing.hpp"
#include "Color/Color.hpp"
#include <filesystem>

namespace Game
{
    class MotionlessEntity : public IEntity {

    public:
        /**
         * @brief Destroy the Motionless Entity object
         */
        virtual ~MotionlessEntity(void) {};

        /**
         * @brief Get the Type object
         *
         * @return A std::string
         */
        virtual std::string getType(void) const = 0;

        /**
         * @brief Get the Positions object
         *
         * @return A Raylib::Vector3
         */
        Raylib::Vector3 getPositions(void) const;

        /**
         * @brief Set the Positions
         *
         * @param vector A vector3
         */
        void setPositions(Raylib::Vector3 &vector);

        /**
         * @brief Draw Entity
         *
         */
        virtual void drawEntity(void) = 0;

        /**
         * @brief Set a boolean to know if this entity should be displayed
         *
         * @param shouldDisplay A boolean to know if this entity should be displayed
         */
        void setShouldDisplay(const bool &shouldDisplay);

        /**
         * @brief Get a boolean to know if this entity should be displayed
         *
         * @return true or false
         */
        bool getShouldDisplay(void) const;

        /**
         * @brief Update the available textures paths
         *
         */
        void updateAvailablePaths(void);

    protected:

        MotionlessEntity(void) = default;

        // TODO: USE ENCAPSULATION
        Model _model;
        Raylib::Vector3 _positions{0, 0, 0};     // A vector3 that represents positions
        std::vector<Raylib::Texture> _textures;     // A vector of texture
        bool _shouldDisplay = true;            // A boolean to know if this entity should be displayed
        std::vector<std::string> _available_paths; // All available paths to textures
        float _width;               // A float
        float _height;              // A float
        float _length;              // A float
    };

    class SolidWall : public virtual MotionlessEntity {

    public:

        /**
         * @brief Construct a new Solid Wall
         *
         * @param positions A vector3, {0, 0, 0} as default value
         * @param mapType A size_t, 0 as default value
         * @param width A float, 1.0f as default value
         * @param height A float, 1.0f as default value
         * @param length A float, 1.0f as default value
         */
        SolidWall(Raylib::Vector3 positions = {0, 0, 0}, size_t mapType = 0, float width = 1.0f, float height = 1.0f, float length = 1.0f);

        /**
         * @brief Get the Type of the object
         *
         * @return A std::string
         */
        std::string getType(void) const override;

        /**
         * @brief Draw Entity
         */
        void drawEntity(void) override;

    private:
        size_t _mapType;        // A size_t
    };

    class BreakableWall : public virtual MotionlessEntity {

    public:

        /**
         * @brief Construct a new Breakable Wall
         *
         * @param positions A vector3, {0, 0, 0} as default value
         * @param mapType A size_t, 0 as default value
         * @param width A float, 1.0f as default value
         * @param height A float, 1.0f as default value
         * @param length A float, 1.0f as default value
         */
        BreakableWall(Raylib::Vector3 positions = {0, 0, 0}, size_t mapType = 0, float width = 1.0f, float height = 1.0f, float length = 1.0f);

        /**
         * @brief Get the Type of the object
         *
         * @return A std::string
         */
        std::string getType(void) const override;

        /**
         * @brief Draw Entity
         */
        void drawEntity(void) override;

    private:
        size_t _mapType;        // A size_t
    };

    class Floor : public virtual MotionlessEntity {

    public:

        /**
         * @brief Construct a new Floor
         *
         * @param positions A vector3, {0, 0, 0} as default value
         * @param mapType A size_t, 0 as default value
         * @param width A float, 1.0f as default value
         * @param height A float, 1.0f as default value
         * @param length A float, 1.0f as default value
         */
        Floor(Raylib::Vector3 positions = {0, 0, 0}, size_t mapType = 0, float width = 1.0f, float height = 1.0f, float length = 1.0f);

        /**
         * @brief Get the Type of the object
         *
         * @return A std::string
         */
        std::string getType(void) const override;

        /**
         * @brief Draw Entity
         */
        void drawEntity(void) override;

    private:
        size_t _mapType;        // A size_t
    };

#include "MotionlessEntity.inl"
}

#endif /* !MOTIONLESSENTITY_HPP_ */