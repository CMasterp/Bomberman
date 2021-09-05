/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** KeyboardPlayerInput
*/

#ifndef KEYBOARDINPUT_HPP_
#define KEYBOARDINPUT_HPP_

#include "Keyboard/Keyboard.hpp"
#include "IPlayerInput.hpp"

class KeyboardPlayerInput : public IPlayerInput {

public:

    /**
     * @brief Construct a new KeyboardPlayerInput object
     */
    KeyboardPlayerInput();

    /**
     * @brief Destroy the KeyboardPlayerInput object
     */
    ~KeyboardPlayerInput() override;

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

#endif /* !KEYBOARDINPUT_HPP_ */