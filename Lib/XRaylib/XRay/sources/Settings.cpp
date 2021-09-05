/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Settings
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displaySettingsScene(void)
{
    // Set scene
    _scene = SETTINGS;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox<float>(20, 1000, 280, 1065)) ? true : false;
    bool onFullscreen = mouseIsInBox(createBox<float>(1150, 400, 1510, 509)) ? true : false;
    bool onMasterVolumeDown = mouseIsInBox(createBox<float>(560, 395, 624, 459)) ? true : false;
    bool onMasterVolumeUp = mouseIsInBox(createBox<float>(765, 395, 829, 459)) ? true : false;
    bool onMusicVolumeDown = mouseIsInBox(createBox<float>(560, 480, 624, 544)) ? true : false;
    bool onMusicVolumeUp = mouseIsInBox(createBox<float>(765, 480, 829, 544)) ? true : false;
    bool onSfxVolumeDown = mouseIsInBox(createBox<float>(560, 565, 624, 629)) ? true : false;
    bool onSfxVolumeUp = mouseIsInBox(createBox<float>(765, 565, 829, 629)) ? true : false;
    bool onMods = mouseIsInBox(createBox<float>(1150, 620, 1510, 729)) ? true : false;

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);
    std::shared_ptr<Raylib::Texture> modsButton = _resources.at(_pSelector.isModsAvailable() ? ON : OFF);

    /// Draw scene
    (!_transitionManager[MENU].second) ? beginDrawing() : beginDrawing(false);
    fadeThisScene(MENU);

    if (!_transitionManager[MENU].second) {
        // Background
        _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());

        // Fullscreen
        _resources.at(TEXT_FULLSCREEN)->drawTexture(1100, 310, Raylib::Color::White());
        fullscreenButton->drawTexture(1150, 400, Raylib::Color::White());

        // VOLUME
        _resources.at(TEXT_VOLUME)->drawTexture(440, 310, Raylib::Color::White());
        _resources.at(TEXT_GENERAL)->drawTexture(200, 400, Raylib::Color::White());
        _resources.at(TEXT_MUSIC)->drawTexture(285, 490, Raylib::Color::White());
        _resources.at(TEXT_SFX)->drawTexture(375, 575, Raylib::Color::White());

        // Master Volume
        _resources.at(VOLUME_DOWN)->drawTexture(560, 395, Raylib::Color::White());
        Raylib::Text::drawText(std::to_string(static_cast<int>(masterVolume)), 670, 405, 48, Raylib::Color::White());
        _resources.at(VOLUME_UP)->drawTexture(765, 395, Raylib::Color::White());

        // Music volume
        _resources.at(VOLUME_DOWN)->drawTexture(560, 480, Raylib::Color::White());
        Raylib::Text::drawText(std::to_string(static_cast<int>(musicVolume)), 670, 490, 48, Raylib::Color::White());
        _resources.at(VOLUME_UP)->drawTexture(765, 480, Raylib::Color::White());

        // Sfx volume
        _resources.at(VOLUME_DOWN)->drawTexture(560, 565, Raylib::Color::White());
        Raylib::Text::drawText(std::to_string(static_cast<int>(sfxVolume)), 670, 575, 48, Raylib::Color::White());
        _resources.at(VOLUME_UP)->drawTexture(765, 565, Raylib::Color::White());

        // Mods
        _resources.at(TEXT_MODS)->drawTexture(1215, 550, Raylib::Color::White());
        modsButton->drawTexture(1150, 620, Raylib::Color::White());

        // Back button
        (mouseIsInBox(createBox<float>(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000, Raylib::Color::White());
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
        _scenesBack[SETTINGS] = _scenesBackBackup[SETTINGS];
    }
    // Fullscreen bouton handling
    if (onFullscreen && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_TURN_OFF)->play();
        Raylib::Window::toggleFullscreen();
    }

    // Master volume click action
    if (onMasterVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        masterVolume -= 10;
        if (masterVolume < 0)
            masterVolume = 0;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }
    if (onMasterVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        masterVolume += 10;
        if (masterVolume > 100)
            masterVolume = 100;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }

    // Music volume click action
    if (onMusicVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        musicVolume -= 10;
        if (musicVolume < 0)
            musicVolume = 0;
        changeMusicVolume();
    }
    if (onMusicVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        musicVolume += 10;
        if (musicVolume > 100)
            musicVolume = 100;
        changeMusicVolume();
    }

    // Sfx volume click action
    if (onSfxVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        sfxVolume -= 10;
        if (sfxVolume < 0)
            sfxVolume = 0;
        changeSfxVolume();
    }
    if (onSfxVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        sfxVolume += 10;
        if (sfxVolume > 100)
            sfxVolume = 100;
        changeSfxVolume();
    }
    // Mods bouton handling
    if (onMods && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_TURN_OFF)->play();
        _pSelector.toggleModsAvailable();
    }
}

void XRay::changeMusicVolume() {
    for (auto &i : _musics) {
        i.second->setVolume(musicVolume / 100);
    }
};

void XRay::changeSfxVolume() {
    for (auto &i : _sfx) {
        i.second->setVolume(sfxVolume / 100);
    }
};

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try


int catchThrowTrydisplaySettingsScene() {
    try
    {   XRay test;
        test.displaySettingsScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrychangeMusicVolume() {
    try
    {   XRay test;
        test.changeMusicVolume();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrychangeSfxVolume() {
    try
    {   XRay test;
        test.changeSfxVolume();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

