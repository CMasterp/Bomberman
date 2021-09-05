/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.hpp
*/

#ifndef MODELER_HPP_
#define MODELER_HPP_

#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"
#include "Clock.hpp"

#define FRAMETIME 0.03f

struct Animator
{
    std::string WALK = "null";
    std::string BOMB = "null";
    std::string EMOTE = "null";
};

enum AnimSequence {
    WALK,
    BOMB,
    EMOTE
};

class Modeler
{
public:
    /**
     * @brief Construct a new Modeler object
     */
    Modeler();
    /**
     * @brief Construct a new Modeler object
     *
     * @param obj_path
     * @param texture_path
     * @param animation_path
     */
    Modeler(const std::string &obj_path, const std::string &texture_path, const Animator &animation_path);

    /**
     *
     * @param model
     * @return
     */
    Modeler& operator=(Modeler model);

    /**
     * @brief Destructor of Modeler object
     */
    ~Modeler();

    /**
     * @brief Make a walk
     */
    void makeWalk();
    /**
     * @brief Make a bomb
     */
    void makeBomb();
    /**
     * @brief Make an Emote
     */
    void makeEmote();

    /**
     * @brief Get the Model
     *
     * @return Model
     */
    Model &getModel();

    /**
     * @brief Update
     */
    void update();

    /**
     * @brief Get the path to the object
     *
     * @return std::string Path to the object
     */
    std::string getObjPath();
    /**
     * @brief Get the path to the texture
     *
     * @return std::string Path to the texture
     */
    std::string getTexturePath();
    /**
     * @brief Get the path to the animation
     *
     * @return std::string Path to the animation
     */
    Animator getAnimationPath();


private:

    /**
     * @brief Check if there's animation in a folder
     *
     * @param animation_path
     * @return bool true if animation are found otherwise false
     */
    bool isThereAnimationsPath(const Animator &animation_path) const;

    Model _model;                                                               // The model
    std::string _model_path;                                                    // The path to the model
    std::string _texture_path;                                                  // The path to the texture
    std::vector<ModelAnimation> _animations;                                    // The animations of the model
    Animator _animator;                                                         // Animator

    bool _isAnimated;                                                           // Check if the model is animated
    int _frame;                                                                 // Frame of the animation

    Clock clock;                                                                // Clock of the model
    int _currentAnimation;                                                      // Animation playing id
};

#endif