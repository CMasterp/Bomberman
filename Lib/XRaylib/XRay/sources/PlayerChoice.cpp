/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerChoice
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::detectPlayerInput(void)
{
    Resources tmp;
    size_t t = 0;

    for (; t < _allIntegers[2]-1 && _playerTab[t]; t++);
    tmp = _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(0) && Raylib::Gamepad::isGamepadButtonPressed(0, 15)) ? PLAYSTATIONYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(1) && Raylib::Gamepad::isGamepadButtonPressed(1, 15)) ? XBOXYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Keyboard::getKeyPressed()) ? KEYBOARDYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Mouse::isButtonPressed(1) || (Raylib::Mouse::isButtonPressed(0) && t == 0)) ? MOUSEYELLOW : _controlsTab[t];
    for (size_t k = 0; k < t; k++)
        _controlsTab[t] = (_controlsTab[t] == _controlsTab[k]) ? tmp : _controlsTab[t];
    _playerTab[t] = (tmp != _controlsTab[t]) ? true : _playerTab[t];
    if (tmp != _controlsTab[t]) {
        if (_playersInput.size() > t)
            _playersInput.pop_back();
        if (_controlsTab[t] == PLAYSTATIONYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(0)));
        if (_controlsTab[t] == XBOXYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(1)));
        if (_controlsTab[t] == KEYBOARDYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new KeyboardPlayerInput()));
        if (_controlsTab[t] == MOUSEYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new MousePlayerInput()));
    }
}

void XRay::removePlayer(const std::vector<std::pair<int, int>> &removeButtons)
{
    for (size_t u = 0; u < removeButtons.size(); u++) {
        if (mouseIsInBox(createBox<float>(removeButtons[u].first, removeButtons[u].second, removeButtons[u].first+64, removeButtons[u].second+63)) && Raylib::Mouse::isButtonPressed(0)) {
            _allIntegers[2] -= 1;
            if (_playerTab[u+1]) {
                _controlsTab[u + 1] = UNKNOWN;
                _playersInput.erase(_playersInput.begin() + u + 1);
            }
            _playerTab.erase(_playerTab.begin() + u + 1);
            _pSelector.unload(u + 1);
            _sfx.at(SFX_JIG1)->play();
        }
    }
}

void XRay::addPlayer(void)
{
    float a = 100 + (_allIntegers[2]*450);
    if (_allIntegers[2] != 4 && mouseIsInBox(createBox<float>(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && Raylib::Mouse::isButtonPressed(0)) {
        _allIntegers[2] += 1;
        _playerTab.push_back(false);
        _pSelector.load();
        _sfx.at(SFX_JIG)->play();
    }
}

void XRay::manageNextOrPrev(void)
{
    auto glambda = [](size_t a) { return a == 40 ? 36 : 40; };

    _nextOrNot = 0;
    for (size_t u = 0; u < _allIntegers[2] && u < _playersInput.size(); u++) {
        if (_playerTab[u] && _playersInput[u]->shouldSimulateAClick()) {
            _card[u] = glambda(_card[u]);
            _sfx.at(SFX_BING)->play();
        }
        if (_playerTab[u] && _playersInput[u]->shouldChangeToPrev() && _card[u] != 40) {
            _sfx.at(SFX_KLICK)->play();
            _pSelector.prev(u);
        }
        if (_playerTab[u] && _playersInput[u]->shouldChangeToNext() && _card[u] != 40) {
            _sfx.at(SFX_KLICK)->play();
            _pSelector.next(u);
        }
        _nextOrNot += _playerTab[u] ? _card[u] : 0;
    }
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removeButtons, int *x)
{
    int i, b;
    for (i = 0, (*x) = 100, b = 200; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*x) += 450) {
        (_playerTab[i]) ? _resources.at((Resources)(_card[i]+i))->drawTexture((*x), b) : _resources.at(AI)->drawTexture((*x), b);
        if (_playerTab[i])
            _resources.at((Resources)static_cast<size_t>((_controlsTab[i])+_card[i]-36))->drawTexture((*x)+109, b+9);
        if (i != 0)
            removeButtons.push_back(std::make_pair((*x)+307, b+9));
        if (_card[i] == 36) {
            Raylib::Text::drawText(_pSelector[i].getName(), 200 + 450 * i + ((180 - Raylib::Text::measureText(_pSelector[i].getName(), 50)) / 2), 595, 50, Raylib::Color::Black());
        }
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*x), _allIntegers[1]);
}

void XRay::displayBack(void)
{
    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= (-_resources.at(BG)->getCStruct().width/3 * 2)) _scrollingBack = 0;

    _resources.at(BG)->drawTexture(_scrollingBack, 0, 0.0f, 1.0f);
    _resources.at(BG)->drawTexture(_resources.at(BG)->getCStruct().width + _scrollingBack, 0, 0.0f, 1.0f);
}

void XRay::displayPlayerChoiceScene(void)
{
    // Set scene
    _scene = PLAYER_CHOICE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox<float>(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox<float>(1700, 1000, 1918, 1061)) ? true : false;

    // Create containers
    std::vector<std::pair<int, int>> removeButtons;     // A vector of all remove buttons coordinates
    std::vector<bool> mouseOnText;                      // A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
    std::vector<Raylib::Rectangle> textBox;             // A vector of rectangle that represents the boxes of the pseudos

    // A int that represents the x coordinate of the last displayed card
    int x;

    // Detect Keyboard, Mouse, and Gamepad
    detectPlayerInput();

    // Play music
    playMusic(MSC_BOMBERMAN);

    // Draw scene
    beginDrawing();
    displayBack();

    displayCardsSettings(removeButtons, &x);
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    (goNext ? _resources.at(NEXT_HOVER) : _resources.at(NEXTSCENE))->drawTexture(1700, 1000);

    _pSelector.drawPlayers();

    displayMouse();
    endDrawing();

    manageNextOrPrev();

    // Check and Manage Click on buttons
    removePlayer(removeButtons);
    addPlayer();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[PLAYER_CHOICE] = _scenesBackBackup[PLAYER_CHOICE];
    }

    // Update Game Settings
    _gameSettings[5] = 0;
    for (size_t t = 0; t < _allIntegers[2] && t <_playerTab.size(); t++)
        _gameSettings[5] += (!_playerTab[t]) ? 1 : 0;
    _gameSettings[7] = _allIntegers[2] - _gameSettings[5];

    // Go to another scene according to mouse position
    if (goNext && Raylib::Mouse::isButtonPressed(0) && _nextOrNot == _gameSettings[7] * 40 && _allIntegers[2] > 1) {
        for (size_t o = 0; o < _allIntegers[2]; o++)
            _userNames.push_back(_pSelector[o].getName());
        _sfx.at(SFX_NOCK)->play();
        _pSelector.initMaps({
                                    {"WWWWWWW"},
                                    {"W*****W"},
                                    {"W*WMW*W"},
                                    {"W*MMM*W"},
                                    {"W*WMW*W"},
                                    {"W*****W"},
                                    {"WWWWWWW"},
                            });
        displayMapChoiceScene();
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydetectPlayerInput() {
    try
    {   XRay test;
        test.detectPlayerInput();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryremovePlayer() {
    try
    {   XRay test;
        std::vector<std::pair<int, int>> removeButtons;
        test.removePlayer(removeButtons);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryaddPlayer() {
    try
    {   XRay test;
        test.addPlayer();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymanageNextOrPrev() {
    try
    {   XRay test;
        test.manageNextOrPrev();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayCardsSettings() {
    try
    {   XRay test;
        int x;
        std::vector<std::pair<int, int>> removeButtons;
        test.displayCardsSettings(removeButtons,&x);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayBack() {
    try
    {   XRay test;
        test.displayBack();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayPlayerChoiceScene() {
    try
    {   XRay test;
        test.displayPlayerChoiceScene();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}