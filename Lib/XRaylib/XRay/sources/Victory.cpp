/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Victory
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::goToAnotherSceneFromVictory()
{
    // Check if mouse is on button spot
    bool home = mouseIsInBox(createBox<float>(380, 330, 380+375, 330+65)) ? true : false;
    bool restart = mouseIsInBox(createBox<float>(380, 440, 380+375, 440+65)) ? true : false;
    bool save = (_humanPlayers + _aiPlayers < 2) && mouseIsInBox(createBox<float>(380, 550, 380+375, 550+65)) ? true : false;
    bool nextlevel = (_humanPlayers + _aiPlayers < 2) && mouseIsInBox(createBox<float>(380, 660, 380+375, 660+65)) ? true : false;

    // Call function that check click on button
    if ((home || restart || save || nextlevel) && Raylib::Mouse::isButtonPressed(0)) {
        if (_sfx.at(SFX_WEEE)->isPlaying())
            _sfx.at(SFX_WEEE)->stop();
    }
    if (nextlevel && Raylib::Mouse::isButtonPressed(0)) {
        // Do here all manipulations to increase level
        _sfx.at(SFX_KLICK)->play();
        displayCinematic("loading", 0, 0);
        _gameSettings = _gameSettingsBackup;
        _scene = IN_GAME;
    }
    if (restart && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        _gameSettings = _gameSettingsBackup;
        displayCinematic("loading", 0, 0);
        _scene = IN_GAME;
    }
    if (save && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        beginDrawing(false);
        _resources.at(SAVED)->drawTexture(650, 20);
        endDrawing();
        _pointerToSaveFunc(_gameSettings, getPlayerControls());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (home && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        resetAll();
        displayMenuScene();
    }
}

void XRay::displayVictoryScene()
{
    // Set scene
    _scene = VICTORY;

    if (_musics.at(MSC_GAME)->isPlaying())
        _musics.at(MSC_GAME)->stop();
    //play wee sound
    if (!_sfx.at(SFX_WEEE)->isPlaying())
        _sfx.at(SFX_WEEE)->play();
    // Draw scene
    beginDrawing();
    _resources.at(VICTORYBG)->drawTexture(0, 0);
    (mouseIsInBox(createBox<float>(380, 330, 380+375, 330+65)) ? _resources.at(HOMEHOVER) : _resources.at(HOME))->drawTexture(380, 330);
    (mouseIsInBox(createBox<float>(380, 440, 380+375, 440+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(380, 440);
    if (_gameSettings[7] + _gameSettings[5] < 2) {
        (mouseIsInBox(createBox<float>(380, 550, 380+375, 550+65)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(380, 550);
        (mouseIsInBox(createBox<float>(380, 660, 380+375, 660+65)) ? _resources.at(NEXTLEVELHOVER) : _resources.at(Resources::NEXTLEVEL))->drawTexture(380, 660);
    }
    _resources.at(RANKING)->drawTexture(1030, 350);
    displayEndScores();
    displayMouse();
    endDrawing();

    // Call function that check click on button
    goToAnotherSceneFromVictory();
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrygoToAnotherSceneFromVictory() {
    try
    {   XRay test;
        test.goToAnotherSceneFromVictory();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayVictoryScene() {
    try
    {   XRay test;
        test.displayVictoryScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}