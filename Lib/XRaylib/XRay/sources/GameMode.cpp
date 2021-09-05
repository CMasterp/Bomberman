/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GameMode
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displayGameModeScene(void)
{
    // Set scene
    _scene = GAME_MODE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox<size_t>(20, 1000, 280, 1065)) ? true : false;
    bool goNewGame = mouseIsInBox(createBox<size_t>(0, 0, 960, 1080)) ? true : false;
    bool goLoadGame = mouseIsInBox(createBox<size_t>(960, 0, 1920, 1080)) ? true : false;

    // Draw scene
    (!_transitionManager[MENU].second) ? beginDrawing() : beginDrawing(false);
    fadeThisScene(MENU);
    if (!_transitionManager[MENU].second) {
        if (Raylib::Mouse::getMouseX() < 960)
            _resources.at(NEWGAME_BG)->drawTexture(0, 0);
        else
            _resources.at(LOADGAME_BG)->drawTexture(0, 0);
        (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
        _resources.at(NEWGAME)->drawTexture(180, 500);
        _resources.at(LOADGAME)->drawTexture(1140, 500);
        displayMouse();

        // Transition
        fadeThisScene(_scene);
    }
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        updateTransitionManager(_scene, MENU);
        (this->*_scenesBack[_scene])();
        _scenesBack[GAME_MODE] = _scenesBackBackup[GAME_MODE];
    }
    else if (goNewGame && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        _pSelector.firstLoad();
        displayPlayerChoiceScene();
    } else if (goLoadGame && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        displayCinematic("loadingbar", 0, 0);
        displayLoadGameScene();
    }
}