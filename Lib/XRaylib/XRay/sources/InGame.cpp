/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** InGame
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

std::string XRay::getTimeInFormat(void)
{
    int min = _gameSettings[4] / 60;
    int secs = _gameSettings[4] % 60;
    std::string time(std::string("0")+std::to_string(min)+std::string(":")
                     +((secs >= 10) ? std::string("") : std::string("0"))+std::to_string(secs));

    return time;
}

void XRay::drawPlayersHead(size_t i, size_t x, size_t y)
{
    _resources.at(CLOCKBAR)->drawTexture(_panelPos[i].first + 100, _panelPos[i].second + 70);
    if (_userNames[i] == "Yellow") {
        _resources.at(YELLOWBOMBERMAN)->drawTexture(x, y);
        Raylib::Text::drawText(_scores[i].second, _panelPos[i].first + 150, _panelPos[i].second + 76, 50, Raylib::Color::Yellow());
        if (_playersStats.at(i).at(3).second == "0")
            Raylib::Rectangle::drawRectangle(_panelPos[i].first - 5, _panelPos[i].second - 230, 360, 400, Raylib::Color::fade(Raylib::Color::Yellow(), 0.4f));
    }
    if (_userNames[i] == "Red") {
        _resources.at(REDBOMBERMAN)->drawTexture(x, y);
        Raylib::Text::drawText(_scores[i].second, _panelPos[i].first + 150, _panelPos[i].second + 76, 50, Raylib::Color::Red());
        if (_playersStats.at(i).at(3).second == "0")
            Raylib::Rectangle::drawRectangle(_panelPos[i].first - 5, _panelPos[i].second - 230, 360, 400, Raylib::Color::fade(Raylib::Color::Red(), 0.4f));
    }
    if (_userNames[i] == "Blue") {
        _resources.at(BLUEBOMBERMAN)->drawTexture(x, y);
        Raylib::Text::drawText(_scores[i].second, _panelPos[i].first + 150, _panelPos[i].second + 76, 50, Raylib::Color::Blue());
        if (_playersStats.at(i).at(3).second == "0")
            Raylib::Rectangle::drawRectangle(_panelPos[i].first - 5, _panelPos[i].second - 230, 360, 400, Raylib::Color::fade(Raylib::Color::Blue(), 0.4f));
    }
    if (_userNames[i] == "Green") {
        _resources.at(GREENBOMBERMAN)->drawTexture(x, y);
        Raylib::Text::drawText(_scores[i].second, _panelPos[i].first + 150, _panelPos[i].second + 76, 50, Raylib::Color::Green());
        if (_playersStats.at(i).at(3).second == "0")
            Raylib::Rectangle::drawRectangle(_panelPos[i].first - 5, _panelPos[i].second - 230, 360, 400, Raylib::Color::fade(Raylib::Color::Green(), 0.4f));
    }
}

void XRay::displayPlayersPanels(std::vector<std::pair<size_t, size_t>> &_panelPos)
{
    for (size_t u = 0; u < (_gameSettings[7] + _gameSettings[5]); u++) {
        if (_controlsTab.at(u) == Resources::PLAYSTATIONYELLOW)
            _resources.at(PLAYSTATIONPANEL)->drawTexture(_panelPos.at(u).first, _panelPos.at(u).second);
        else if (_controlsTab.at(u) == Resources::XBOXYELLOW)
            _resources.at(XBOXPANEL)->drawTexture(_panelPos.at(u).first, _panelPos.at(u).second);
        else if (_controlsTab.at(u) == Resources::MOUSEYELLOW) {
            _resources.at(MOUSEPANEL)->drawTexture(_panelPos.at(u).first, _panelPos.at(u).second);
            _resources.at(MOUSERADAR)->drawTexture(1600, 40);
        } else if (_controlsTab.at(u) == Resources::KEYBOARDYELLOW)
            _resources.at(KEYBOARDPANEL)->drawTexture(_panelPos.at(u).first, _panelPos.at(u).second);
        else
            _resources.at(AIPANEL)->drawTexture(_panelPos.at(u).first, _panelPos.at(u).second);
        _resources.at(SKATE)->drawTexture(_panelPos.at(u).first + 200, _panelPos.at(u).second - 15 - 64);
        Raylib::Text::drawText("x", _panelPos.at(u).first + 285, _panelPos.at(u).second - 15 - 64, 60, Raylib::Color::White());
        Raylib::Text::drawText(_playersStats.at(u).at(0).second, _panelPos.at(u).first + 325, _panelPos.at(u).second - 15 - 64, 60, Raylib::Color::White());
        _resources.at(FIRE)->drawTexture(_panelPos.at(u).first + 200, _panelPos.at(u).second - 15 - 128 - 10);
        Raylib::Text::drawText("x", _panelPos.at(u).first + 285, _panelPos.at(u).second - 15 - 128 - 10, 60, Raylib::Color::White());
        Raylib::Text::drawText(_playersStats.at(u).at(1).second, _panelPos.at(u).first + 325, _panelPos.at(u).second - 15 - 128 - 10, 60, Raylib::Color::White());
        _resources.at(IBOMB)->drawTexture(_panelPos.at(u).first + 200, _panelPos.at(u).second - 15 - 128 - 64 - 20);
        Raylib::Text::drawText("x", _panelPos.at(u).first + 285, _panelPos.at(u).second - 15 - 128 - 64 - 20, 60, Raylib::Color::White());
        Raylib::Text::drawText(_playersStats.at(u).at(2).second, _panelPos.at(u).first + 325, _panelPos.at(u).second - 15 - 128 - 64 - 20, 60, Raylib::Color::White());
        drawPlayersHead(u, _panelPos.at(u).first-10, _panelPos.at(u).second-180);
    }
    _resources.at(CLOCKBAR)->drawTexture(600, 0);
    _resources.at(CLOCKBAR)->drawTexture(1200, 0, ((_gameSettings[4] <= 10 && _gameSettings[4] % 2 == 0) ? Raylib::Color::Red() : Raylib::Color::White()));
    Raylib::Text::drawText(std::to_string(_gameSettings[2]), 720, 15, 60, Raylib::Color::White());
    Raylib::Text::drawText(getTimeInFormat(), 1245, 15, 60, Raylib::Color::White());
}

void XRay::displayPauseScene(void)
{
    if (_isPaused) {
        _resources.at(DEPAUSE)->drawTexture(10, 5);
        _resources.at(PAUSEBACK)->drawTexture(0, 0);
        (mouseIsInBox(createBox<size_t>(460, 445, 460+375, 445+65)) ? _resources.at(RESUMEHOVER) : _resources.at(RESUME))->drawTexture(460, 445);
        (mouseIsInBox(createBox<size_t>(460, 555, 460+375, 555+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(460, 555);
        (mouseIsInBox(createBox<size_t>(460, 665, 460+375, 665+65)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(460, 665);
        (mouseIsInBox(createBox<size_t>(460, 775, 460+375, 775+65)) ? _resources.at(SETTINGSHOVER) : _resources.at(Resources::SETTING))->drawTexture(460, 775);
        (mouseIsInBox(createBox<size_t>(460, 885, 460+375, 885+65)) ? _resources.at(HOMEHOVER) : _resources.at(Resources::HOME))->drawTexture(460, 885);
    } else
        _resources.at(PAUSE)->drawTexture(10, 5);
}

void XRay::goToAnotherScene()
{
    // Check if mouse is on button spot
    bool pauseButton = mouseIsInBox(createBox<size_t>(10, 5, 122, 127)) ? true : false;
    bool resume = mouseIsInBox(createBox<size_t>(460, 445, 460+375, 445+65)) ? true : false;
    bool restart = mouseIsInBox(createBox<size_t>(460, 555, 460+375, 555+65)) ? true : false;
    bool save = mouseIsInBox(createBox<size_t>(460, 665, 460+375, 665+65)) ? true : false;
    bool settings = mouseIsInBox(createBox<size_t>(460, 775, 460+375, 775+65)) ? true : false;
    bool home = mouseIsInBox(createBox<size_t>(460, 885, 460+375, 885+65)) ? true : false;

    // Go to another scene according to mouse position
    if (pauseButton && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = true;
        _sfx.at(SFX_KLICK)->play();
        _lastFrameTime = Raylib::Timing::getTime();
    }
    if (_isPaused && resume && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        _sfx.at(SFX_KLICK)->play();
        _startingTime += Raylib::Timing::getTime() - _lastFrameTime;
    }
    if (_isPaused && restart && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (_isPaused && save && Raylib::Mouse::isButtonPressed(0)) {
        beginDrawing(false);
        _sfx.at(SFX_KLICK)->play();
        _resources.at(SAVED)->drawTexture(650, 20);
        endDrawing();
        _pointerToSaveFunc(_gameSettings, getPlayerControls());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (_isPaused && settings && Raylib::Mouse::isButtonPressed(0)) {
        _scenesBack[Scene::SETTINGS] = &XRay::displayInGameScene;
        _sfx.at(SFX_SETTING)->play();
        displaySettingsScene();
    }
    if (_isPaused && home && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        _sfx.at(SFX_HOME)->play();
        m_isPaused = 2;
        resetAll();
        _pointerToRestartFunc();
        displayMenuScene();
    }
}

void XRay::managePlayersActions(void)
{
    for (size_t u = 0; u < _playersInput.size(); u++) {
        if (_playersInput.at(u)->shouldGoToEast())
            _playerActionsFunc(u, "goEast");
        if (_playersInput.at(u)->shouldGoToNorth())
            _playerActionsFunc(u, "goNorth");
        if (_playersInput.at(u)->shouldGoToSouth())
            _playerActionsFunc(u, "goSouth");
        if (_playersInput.at(u)->shouldGoToWest())
            _playerActionsFunc(u, "goWest");
        if (_playersInput.at(u)->shouldSimulateAClick())
            _playerActionsFunc(u, "dropBomb");
    }
}

void XRay::checkEndScenario(void)
{
    size_t i = 0;

    while (i < _gameInfos.size() && _gameInfos[i]->getType().compare("Human") != 0)
        i++;
    if (_humanPlayers == 1) {
        if (_gameInfos[i]->getShouldDisplay())
            displayVictoryScene();
        else
            displayDefeatScene();
    } else {
        if (_deadPlayers == _humanPlayers)
            displayDefeatScene();
        else
            displayVictoryScene();
    }
}

void XRay::cameraShake(void)
{
    if (_cameraShakeClock.doesTimeElapsed(0.05f))
        _cameraShakeFrame -= 0.55f;
    if (_cameraShakeFrame < 0)
        _cameraShakeFrame = 11;
    _camera.setPosition(Raylib::Vector3(_camera.getCStruct().position.x, _yCameraAxis + static_cast<float>((cos(_cameraShakeFrame) * 0.2)), _camera.getCStruct().position.z));
    //_camera.updateCamera();
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Declaration of two variables
    float size_m = (static_cast<float>(_sizeMap+1)) / 2;
    bool canCheckScenario = true;

    // Lambda for panel pos
    auto panelLambda = [](size_t a) { return (a <= 2) ? std::vector<std::pair<size_t, size_t>>{{20, 500}, {1550, 500}}
                                                      : std::vector<std::pair<size_t, size_t>>{{20, 500}, {1550, 500}, {20, 950}, {1550, 950}}; };

    // Set local variables at 0
    _deadPlayers = 0;
    _deadAi = 0;
    _humanPlayers = 0;
    _aiPlayers = 0;

    // Check dead players
    for (size_t i = 0; i < _gameInfos.size(); i++) {
        if (_gameInfos[i]->getType().compare("Human") == 0) {
            _deadPlayers += _gameInfos[i]->getShouldDisplay() ? 0 : 1;
            _humanPlayers++;
        }
        if (_gameInfos[i]->getType().compare("AI") == 0) {
            _deadAi += _gameInfos[i]->getShouldDisplay() ? 0 : 1;
            _aiPlayers++;
        }
    }

    // Display Cinematic ready, 3, 2, 1, go
    if (m_isPaused == 2) {
        _panelPos = panelLambda(_gameSettings[7] + _gameSettings[5]);
        _camera = Raylib::Camera3D(Vector3{size_m, size_m * -0.3f, size_m * 2.2f}, Vector3{size_m, size_m, 0}, Vector3{0, 1, 0}, 50, 0);
        _yCameraAxis = _camera.getCStruct().position.y;
        displayCinematic("loading", 0, 0);
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _gameSettings[4] = _gameSettings[3];
    }

    // Next Set
    // End Scenario
     if (((_deadAi == _aiPlayers && _humanPlayers - _deadPlayers == 1) || _deadPlayers == _humanPlayers || _gameSettings[4] == 0) && (_gameSettings[2] < _gameSettings[1])) {
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _pointerToRestartFunc();
        _gameSettings[2] += 1;
        _gameSettings[4] = _gameSettings[3];
        canCheckScenario = false;
    } else if ((_gameSettings[2] >= _gameSettings[1] && _gameSettings[3] != _gameSettings[4] && ((_deadAi == _aiPlayers && _humanPlayers - _deadPlayers == 1) || (_humanPlayers - _deadPlayers == 1 && (_aiPlayers - _deadAi + _humanPlayers - _deadPlayers) == 1) || _deadPlayers == _humanPlayers || _gameSettings[4] == 0)))
        checkEndScenario();

    // Stop bomberman music
    if (_musics.at(MSC_BOMBERMAN)->isPlaying())
        _musics.at(MSC_BOMBERMAN)->stop();
    // Play music
    playMusic(MSC_GAME);

    // Draw scene
    beginDrawing();
    Raylib::Drawing::clearBackground(Raylib::Color::Brown());
    _camera.beginMode3D();
    for (size_t o = 0; o < _gameInfos.size(); o++)
        if (_gameInfos[o]->getShouldDisplay())
            _gameInfos[o]->drawEntity();
    _camera.endMode3D();
    displayPlayersPanels(_panelPos);
    displayPauseScene();
    displayMouse();
    endDrawing();

    m_isPaused = _isPaused;
    _gameSettings[4] = !_isPaused && _gameSettings[4] > 0 ? _gameSettings[3] - (Raylib::Timing::getTime() - _startingTime) : _gameSettings[4];

    // Call function that check players input
    managePlayersActions();

    // Call function that check click on button
    goToAnotherScene();

}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrygetTimeInFormat() {
    try
    {   XRay test;
        test.getTimeInFormat();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydrawPlayersHead() {
    try
    {   XRay test;
        size_t i;
        size_t x;
        size_t y;
        test.drawPlayersHead(i,x,y);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayPlayersPanels() {
    try
    {   XRay test;
        std::vector<std::pair<size_t, size_t>> _panelPos;
        test.displayPlayersPanels(_panelPos);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayPauseScene() {
    try
    {   XRay test;
        test.displayPauseScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydgoToAnotherScene() {
    try
    {   XRay test;
        test.goToAnotherScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymanagePlayersActions() {
    try
    {   XRay test;
        test.managePlayersActions();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayInGameScene() {
    try
    {   XRay test;
        test.displayInGameScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
