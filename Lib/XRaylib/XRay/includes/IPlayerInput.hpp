/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IPlayerInput
*/

#ifndef IPLAYERINPUT_HPP_
#define IPLAYERINPUT_HPP_

class IPlayerInput {

public:

    /**
     * @brief Destroy the IPlayerInput object
     */
    virtual ~IPlayerInput(void) = default;

    /**
     * @brief Check if the player should go to east
     *
     * @return bool which indicate that
     */
    virtual bool shouldGoToEast(void) const = 0;

    /**
     * @brief Check if the player should go to west
     *
     * @return bool which indicate that
     */
    virtual bool shouldGoToWest(void) const = 0;

    /**
     * @brief Check if the player should go to north
     *
     * @return bool which indicate that
     */
    virtual bool shouldGoToNorth(void) const = 0;

    /**
     * @brief Check if the player should go to south
     *
     * @return bool which indicate that
     */
    virtual bool shouldGoToSouth(void) const = 0;

    /**
     * @brief Check if should change to prev
     *
     * @return bool which indicate that
     */
    virtual bool shouldChangeToPrev(void) const = 0;

    /**
     * @brief Check if should change to next
     *
     * @return bool which indicate that
     */
    virtual bool shouldChangeToNext(void) const = 0;

    /**
     * @brief Check if should simulate a click for actions like drop, choose ...
     *
     * @return bool which indicate that
     */
    virtual bool shouldSimulateAClick(void) const = 0;
};

#endif /* !IPLAYERINPUT_HPP_ */