/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GamepadPlayerInput
*/

#ifndef GAMEPADINPUT_HPP_
#define GAMEPADINPUT_HPP_

#include "IPlayerInput.hpp"
#include "Gamepad/Gamepad.hpp"

class GamepadPlayerInput : public IPlayerInput {

public:

    /**
     * @brief Construct a new Gamepad Player Input object
     *
     * @param pos Number of gamepad
     */
    GamepadPlayerInput(size_t pos = 0);

    /**
     * @brief Destroy the GamepadPlayerInput object
     */
    ~GamepadPlayerInput() override;

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

private:
    int _pos = 0;           // Position
};

#endif /* !GAMEPADINPUT_HPP_ */