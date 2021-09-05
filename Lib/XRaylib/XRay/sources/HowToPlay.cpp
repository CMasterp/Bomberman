/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** HowToPlay
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displayHowToPlayScene(void)
{
    // Set scene
    _scene = HELP;

    static int cardId = 1;
    static Raylib::Texture card(Raylib::Image("resources/howToCards/card" + std::to_string(cardId) + ".png"));

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox<size_t>(20, 1000, 280, 1065)) ? true : false;
    bool onPrev = mouseIsInBox(createBox<size_t>(50, 500, 166, 620)) ? true : false;
    bool onNext = mouseIsInBox(createBox<size_t>(1754, 500, 1870, 620)) ? true : false;

    // Draw scene
    (!_transitionManager[MENU].second) ? beginDrawing() : beginDrawing(false);
    fadeThisScene(MENU);

    if (!_transitionManager[MENU].second) {
        //Background
        _resources.at(HOWTO_BG)->drawTexture(0, 0, Raylib::Color::White());

        // Help Cards
        card.drawTexture(220, 140);

        _resources.at(PREVIOUS)->drawTexture(50, 500);
        _resources.at(NEXT)->drawTexture(1754, 500);

        (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
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
        _scenesBack[HELP] = _scenesBackBackup[HELP];
    }
    if (onPrev && Raylib::Mouse::isButtonPressed(0)) {
        if (cardId > 1)
            cardId -= 1;
        else
            cardId = countFilesDirectory("resources/howToCards/");
        card.loadTexture("resources/howToCards/card" + std::to_string(cardId) + ".png");
        _sfx.at(SFX_KLICK)->play();
    }
    if (onNext && Raylib::Mouse::isButtonPressed(0)) {
        if (cardId < countFilesDirectory("resources/howToCards/"))
            cardId += 1;
        else
            cardId = 1;
        card.loadTexture("resources/howToCards/card" + std::to_string(cardId) + ".png");
        _sfx.at(SFX_KLICK)->play();
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayHowToPlayScene() {
    try
    {   XRay test;
        test.displayHowToPlayScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
