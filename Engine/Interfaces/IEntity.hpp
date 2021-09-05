/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <iostream>
#include "Texture/Texture.hpp"
#include "Vector3/Vector3.hpp"

class IEntity {

public:
    /**
     * @brief Destroy the IEntity object
     *
     */
    virtual ~IEntity() {};

    /**
    * @brief Get the Type object
    *
    * @return A std::string
    */
    virtual std::string getType() const = 0;

    /**
     * @brief Get the Positions object
     *
     * @return A Raylib::Vector3
     */
    virtual Raylib::Vector3 getPositions() const = 0;

    /**
     * @brief Set the Positions
     *
     * @param vector A vector3
     */
    virtual void setPositions(Raylib::Vector3 &vector) = 0;

    /**
     * @brief Draw Entity
     *
     */
    virtual void drawEntity() = 0;

    /**
     * @brief Set a boolean to know if this entity should be displayed
     *
     * @param shouldDisplay A boolean to know if this entity should be displayed
     */
    virtual void setShouldDisplay(const bool &shouldDisplay) = 0;

    /**
     * @brief Get a boolean to know if this entity should be displayed
     *
     * @return true or false
     */
    virtual bool getShouldDisplay() const = 0;
};

#endif /* !IENTITY_HPP_ */