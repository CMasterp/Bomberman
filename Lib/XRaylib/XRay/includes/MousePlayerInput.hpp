/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MousePlayerInput
*/

#ifndef MOUSEPLAYERINPUT_HPP_
#define MOUSEPLAYERINPUT_HPP_

#include "Mouse/Mouse.hpp"
#include "IPlayerInput.hpp"

class MousePlayerInput : public IPlayerInput {

public:

    /**
     * @brief Construct a new MousePlayerInput object
     */
    MousePlayerInput();

    /**
     * @brief Destroy the MousePlayerInput object
     */
    ~MousePlayerInput() override;

    /**
     * @brief Check if the player should go to east
     *
     * @return bool which indicate that
     */
    bool shouldGoToEast(void) const override;

    /**
     * @brief Check if the player should go to west
     *
     * @return bool which indicate that
     */
    bool shouldGoToWest(void) const override;

    /**
     * @brief Check if the player should go to north
     *
     * @return bool which indicate that
     */
    bool shouldGoToNorth(void) const override;

    /**
     * @brief Check if the player should go to south
     *
     * @return bool which indicate that
     */
    bool shouldGoToSouth(void) const override;

    /**
     * @brief Check if should change to prev
     *
     * @return bool which indicate that
     */
    bool shouldChangeToPrev(void) const override;

    /**
     * @brief Check if should change to next
     *
     * @return bool which indicate that
     */
    bool shouldChangeToNext(void) const override;

    /**
     * @brief Check if should simulate a click for actions like drop, choose ...
     *
     * @return bool which indicate that
     */
    bool shouldSimulateAClick(void) const override;
};

#endif /* !MOUSEPLAYERINPUT_HPP_ */