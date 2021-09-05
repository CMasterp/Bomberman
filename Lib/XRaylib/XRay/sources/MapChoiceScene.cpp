/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map Choice Scene
** ///// Credit
** @by PrinceIsGod aka CMasterp
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::displayGameSettings(void)
{
    _resources.at(PREVIOUS)->drawTexture(10, 400);
    _resources.at(NEXT)->drawTexture(910, 400);

    (mouseIsInBox(createBox<size_t>(1160, 245, 1160+755, 245+83)) ? _resources.at(SIZE_HOVER) : _resources.at(SIZE))->drawTexture(1160, 245);
    (mouseIsInBox(createBox<size_t>(1160, 455, 1160+755, 455+83)) ? _resources.at(SETS_HOVER) : _resources.at(Resources::SETS))->drawTexture(1160, 455);
    (mouseIsInBox(createBox<size_t>(1160, 665, 1160+755, 665+83)) ? _resources.at(DURATION_HOVER) : _resources.at(Resources::DURATION))->drawTexture(1160, 665);
    _resources.at((Resources)(static_cast<int>(S7X7S) + ((_sizeMap > 6 && _sizeMap < 20) ? (_sizeMap-7) / 2 : 0)))->drawTexture(1645, 260);
    _resources.at((Resources)(static_cast<int>(SET1SET) + ((_gameSettings[1] > 0 && _gameSettings[1] < 6) ? _gameSettings[1]-1 : 0)))->drawTexture(1730, 465);
    _resources.at((Resources)(static_cast<int>(MIN1MIN) + ((_gameSettings[3] > 0 && _gameSettings[3] < 6) ? _gameSettings[3]-1 : 0)))->drawTexture(1665, 675);
    if (_gameSettings[5] > 0) {
        (mouseIsInBox(createBox<size_t>(1160, 875, 1160+755, 875+83)) ? _resources.at(AI_HOVER) : _resources.at(Resources::IA))->drawTexture(1160, 875);
        _resources.at((Resources)(static_cast<int>(EASY) + ((_gameSettings[6] > 0 && _gameSettings[6] < 4) ? _gameSettings[6]-1 : 0)))->drawTexture(1660, 898);
    }
}

void XRay::checkClickOnMapChoiceScene(void)
{
    // Click on Next and Prev buttons
    for (size_t y = 245; y <= 875; y += 210) {
        if (mouseIsInBox(createBox<size_t>(1610, y+7, 1650, y+7+70))) {
            _sizeMap = (y == 245) ? ((_sizeMap > 7) ? _sizeMap-2 : 19) : _sizeMap;
            _gameSettings[1] = (y == 455) ? ((_gameSettings[1] > 1) ? _gameSettings[1]-1 : 5) : _gameSettings[1];
            _gameSettings[3] = (y == 665) ? ((_gameSettings[3] > 1) ? _gameSettings[3]-1 : 5) : _gameSettings[3];
            _gameSettings[6] = (y == 875) ? ((_gameSettings[6] > 1) ? _gameSettings[6]-1 : 3) : _gameSettings[6];
            _sfx.at(SFX_KLICK)->play();
        } else if (mouseIsInBox(createBox<size_t>(1880, y+7, 1920, y+7+70))) {
            _sizeMap = (y == 245) ? ((_sizeMap < 19) ? _sizeMap+2 : 7) : _sizeMap;
            _gameSettings[1] = (y == 455) ? ((_gameSettings[1] < 5) ? _gameSettings[1]+1 : 1) : _gameSettings[1];
            _gameSettings[3] = (y == 665) ? ((_gameSettings[3] < 5) ? _gameSettings[3]+1 : 1) : _gameSettings[3];
            _gameSettings[6] = (y == 875) ? ((_gameSettings[6] < 3) ? _gameSettings[6]+1 : 1) : _gameSettings[6];
            _sfx.at(SFX_KLICK)->play();
        }
    }
}

void XRay::displayMapChoiceScene(void)
{
    // Set scene
    _scene = MAP_CHOICE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox<size_t>(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox<size_t>(1700, 1000, 1918, 1061)) ? true : false;

    // Play music
    playMusic(MSC_BOMBERMAN);

    // Draw scene
    beginDrawing();
    displayBack();
    displayGameSettings();
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    (goNext ? _resources.at(NEXT_HOVER) : _resources.at(NEXTSCENE))->drawTexture(1700, 1000);
    _pSelector.drawMaps();
    displayMouse();
    endDrawing();

    if (Raylib::Mouse::isButtonPressed(0)) {
        if (mouseIsInBox(createBox<size_t>(10, 400, 160, 550))) {
            _pSelector.prevMap();
            _sfx.at(SFX_KLICK)->play();
        }
        if (mouseIsInBox(createBox<size_t>(900, 400, 1050, 550))) {
            _pSelector.nextMap();
            _sfx.at(SFX_KLICK)->play();
        }
    }
    if (Raylib::Mouse::isButtonPressed(0))
        checkClickOnMapChoiceScene();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        _pSelector.endMaps();
        (this->*_scenesBack[_scene])();
        _scenesBack[MAP_CHOICE] = _scenesBackBackup[MAP_CHOICE];
    }
    if (goNext && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        _gameSettings[8] = _pSelector.getMapType();
        _scene = IN_GAME;
        beginDrawing(false);
        _resources.at(LOADINGFRAMEO)->drawTexture(0, 0);
        endDrawing();
        _pSelector.endMaps();
        _sizeMap = (_sizeMap == 5) ? 7 : _sizeMap;
        _gameSettings[3] *= (_gameSettings[3] < 6) ? 60 : 1;
        _gameSettingsBackup = _gameSettings;
        _pointerToSettingsFunc(_gameSettings);
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayGameSettings() {
    try
    {   XRay test;
        test.displayGameSettings();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrycheckClickOnMapChoiceScene() {
    try
    {   XRay test;
        test.checkClickOnMapChoiceScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayMapChoiceScene() {
    XRay test;
    try
    {
        test.displayMapChoiceScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}