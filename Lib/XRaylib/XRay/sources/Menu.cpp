/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Menu
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displayMenuScene(void)
{
    // Set scene
    _scene = MENU;
    Scene scene = MENU;

    // Check if mouse is on button spot
    bool goPlay = mouseIsInBox(createBox<size_t>(1160, 245, 1160+755, 245+132)) ? true : false;
    bool goHowToPlay = mouseIsInBox(createBox<size_t>(1160, 455, 1160+755, 455+132)) ? true : false;
    bool goSettings = mouseIsInBox(createBox<size_t>(1160, 665, 1160+755, 665+132)) ? true : false;
    bool quit = mouseIsInBox(createBox<size_t>(1160, 875, 1160+755, 875+132)) ? true : false;

    // Display INDIE STUDIO
    if (_intro.first == true)
        (this->*_intro.second[CFunctions::generatePairOfRandomIntegers(2, 1).first])();

    // Stop game music
    if (_musics.at(MSC_GAME)->isPlaying())
        _musics.at(MSC_GAME)->stop();
    // Play bomberma music
    playMusic(MSC_BOMBERMAN);

    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= -_resources.at(PARALLAX)->getCStruct().width/2) _scrollingBack = 0;

    // Draw scene
    while (!_transitionManager[scene].second && scene != SETTINGS)
        scene = static_cast<Scene>(static_cast<int>(scene) + 1);
    (!_transitionManager[scene].second) ? beginDrawing() : beginDrawing(false);
    fadeThisScene(scene);
    if (!_transitionManager[scene].second) {
        beginDrawing();
        _resources.at(PARALLAX)->drawTexture(_scrollingBack, 0, 0.0f, 1.0f);
        _resources.at(PARALLAX)->drawTexture(_resources.at(PARALLAX)->getCStruct().width + _scrollingBack, 0, 0.0f, 1.0f);

        (goPlay ? _resources.at(PLAY_HOVER) : _resources.at(PLAY))->drawTexture(1160, 245);
        (goHowToPlay ? _resources.at(HELP_HOVER) : _resources.at(Resources::HELP))->drawTexture(1160, 455);
        (goSettings ? _resources.at(SETTINGS_HOVER) : _resources.at(Resources::SETTINGS))->drawTexture(1160, 665);
        (quit ? _resources.at(QUIT_HOVER) : _resources.at(QUIT))->drawTexture(1160, 875);

        displayMouse();

        // Transition
        fadeThisScene(_scene);
    }
    endDrawing();

    // Go to another scene according to mouse position
    if (goPlay && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        updateTransitionManager(_scene, GAME_MODE);
        displayGameModeScene();
    } else if (goHowToPlay && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        updateTransitionManager(_scene, HELP);
        displayHowToPlayScene();
    } else if (goSettings && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_SETTING)->play();
        updateTransitionManager(_scene, SETTINGS);
        displaySettingsScene();
    } else if (quit && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        quitGame();
    }
}


// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayMenuScene() {
    try
    {   XRay test;
        test.displayMenuScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}