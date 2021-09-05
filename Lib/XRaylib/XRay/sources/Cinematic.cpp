/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cinematic
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displayCinematic(const Cinematic &cinematic)
{
    size_t a = CFunctions::generatePairOfRandomIntegers(2, 1).first;
    switch (cinematic) {
        case INTRO:
            displayCinematic(a ? "intro1" : "intro2", 300, 1, true, a ? 0 : 240);
            if (_sfx.at(SFX_OPENNING)->isPlaying())
                _sfx.at(SFX_OPENNING)->stop();
            break;
        default:
            break;
    }
}

void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip, const size_t &gap, const bool &clearOrNot, const int &posX)
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);
    Clock clock;

    // Launch cinematic
    size_t i = 0;

    if (!_sfx.at(SFX_OPENNING)->isPlaying() && cinematicPathDirectory == "intro1")
        _sfx.at(SFX_OPENNING)->play();
    if (!_musics.at(MSC_BOMBERMAN)->isPlaying() && cinematicPathDirectory == "intro2")
        playMusic(MSC_BOMBERMAN);
    if (!_sfx.at(SFX_COUNTDOWN)->isPlaying() && cinematicPathDirectory == "readygo") {
        if (_musics.at(MSC_BOMBERMAN)->isPlaying())
            _musics.at(MSC_BOMBERMAN)->stop();
        _sfx.at(SFX_COUNTDOWN)->play();
    }

    while (i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox<size_t>(1760, 950, 1883, 1005)))) {

        if (clock.doesTimeElapsed(0.001)) {
            // Set Textures
            Raylib::Texture frame(Raylib::Image("resources/cinematic/" + cinematicPathDirectory + "/frame" + std::to_string(i) + ".png"));

            // Draw cinematic
            beginDrawing(clearOrNot);
            frame.drawTexture(posX, 0);
            if (i < hideSkip) {
                (mouseIsInBox(createBox<size_t>(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP))->drawTexture(1760, 950);
                displayMouse();
            }
            if (gap > 0)
                std::this_thread::sleep_for(std::chrono::milliseconds(gap));
            endDrawing();
            i++;
        }
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayCinematic() {
    try {
        XRay test;
        Cinematic cinematic;
        test.displayCinematic(cinematic);
    }
    catch (Engine::Exception &ex) {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}