/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

inline bool XRay::shouldCloseWindow(void) const
{
    return _window.windowShouldClose();
}

inline void XRay::closeWindow(void) const
{
    _window.closeWindow();
}

inline std::array<size_t, 9> XRay::getGameSettings()
{
    return _gameSettings;
}

inline void XRay::resetAll(void)
{
    _gameSettings = {0, 1, 1, 1, 60, 0, 1, 1, 0};
    _sizeMap = 5;
    _userNames.clear();
    _playerTab = {true, false, false, false};
    _controlsTab = {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN};
    _allIntegers = {50, 400, 1};
    _card = {36, 36, 36, 36};
    _isPaused = false;
    m_isPaused = 2;
    _scrollingBack = 0.0f;
}

inline void XRay::setMapSize(size_t size)
{
    _sizeMap = size;
}

inline void XRay::setPlayerActionsFunc(std::function<void (const size_t pos, const std::string action)> playerActionsFunc)
{
    _playerActionsFunc = playerActionsFunc;
}

inline void XRay::setRestartFunc(std::function<void ()> pointerToFunc)
{
    _pointerToRestartFunc = pointerToFunc;
}

inline void XRay::setLoadFunc(std::function<void (std::string)> pointerToFunc)
{
    _pointerToLoadFunc = pointerToFunc;
}

inline void XRay::setSaveFunc(std::function<void (std::array<std::size_t, 9>, std::vector<std::string>)> pointerToFunc)
{
    _pointerToSaveFunc = pointerToFunc;
}

inline void XRay::setSettingsFunc(std::function<void (std::array<std::size_t, 9>)> pointerToFunc)
{
    _pointerToSettingsFunc = pointerToFunc;
}

inline void XRay::setMap(std::vector<std::string> &map)
{
    _map = map;
}

inline std::pair<size_t, size_t> XRay::getMapSizeAndType()
{
    return std::make_pair(_sizeMap, _gameSettings[8]);
}

inline void XRay::beginDrawing(void) const
{
    Raylib::Drawing::beginDrawing();
    Raylib::Drawing::clearBackground(Raylib::Color::White());
}

inline void XRay::beginDrawing(const bool &mustBeClear) const
{
    Raylib::Drawing::beginDrawing();
    if (mustBeClear)
        Raylib::Drawing::clearBackground(Raylib::Color::Black());
}

inline void XRay::endDrawing(void) const
{
    Raylib::Drawing::endDrawing();
}

inline void XRay::display(void)
{
    // Hide the cursor
    Raylib::Cursor::hideCursor();

    (this->*_scenesFunc[static_cast<int>(_scene)])();
}

inline void XRay::setPlayersStats(const std::vector<std::vector<std::pair<std::string, std::string>>> &info)
{
    _playersStats = info;
}

inline void XRay::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

inline void XRay::setBestScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _bestScores = scores;
}

inline void XRay::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    _gameInfos = gameInfos;
}

inline const std::vector<std::string> &XRay::getUserNames(void) const
{
    return _userNames;
}

inline void XRay::setUserNames(const std::vector<std::string> &userNames)
{
    _userNames = userNames;
}

inline IGraphical::Scene XRay::getScene(void) const
{
    return _scene;
}

inline void XRay::setScene(const Scene &scene)
{
    _scene = scene;
}

inline const std::vector<std::string> &XRay::getBackups(void) const
{
    return _backups;
}

inline void XRay::setBackups(const std::vector<std::string> &backups)
{
    _backups = backups;
}

template <typename T>
inline bool XRay::mouseIsInBox(const std::vector<T> &box) const
{
    std::pair<T, T> mousePosition = std::make_pair(Raylib::Mouse::getMouseX(), Raylib::Mouse::getMouseY());

    if (box[UPPER_LEFT] <= mousePosition.first && mousePosition.first <= box[LOW_RIGHT]
        && box[LOW_LEFT] <= mousePosition.second && mousePosition.second <= box[UPPER_RIGHT])
        return true;
    return false;
}

template <typename T>
inline std::vector<T> XRay::createBox(const T &upperLeftCorner, const T &upperRightCorner, const T &lowerLeftCorner, const T &lowerRightCorner) const
{
    std::vector<T> box;

    box.reserve(4);
    box.push_back(upperLeftCorner);
    box.push_back(upperRightCorner);
    box.push_back(lowerLeftCorner);
    box.push_back(lowerRightCorner);
    return box;
}

inline void XRay::displayMouse(void) const
{
    _resources.at(HEAD)->drawTexture(Raylib::Mouse::getMouseX() - 15, Raylib::Mouse::getMouseY() - 15, Raylib::Color::White());
}

inline size_t XRay::countFilesDirectory(const std::filesystem::path &path) const
{
    return (std::size_t)std::distance(std::filesystem::directory_iterator{path}, std::filesystem::directory_iterator{});
}

inline std::vector<CharDictionary> XRay::getPlayersData()
{
    return _pSelector.getPlayerData();
}

inline void XRay::setGameSettings(const std::array<size_t, 9> &settings)
{
    _gameSettings = settings;
}

inline std::vector<std::string> XRay::getPlayerControls(void) const
{
    std::vector<std::string> controls;

    for (size_t i = 0; i < _controlsTab.size(); i++) {
        if (_controlsTab[i] == Resources::PLAYSTATIONYELLOW)
            controls.push_back("PLAYSTATION");
        if (_controlsTab[i] == Resources::XBOXYELLOW)
            controls.push_back("XBOX");
        if (_controlsTab[i] == Resources::MOUSEYELLOW)
            controls.push_back("MOUSE");
        if (_controlsTab[i] == Resources::KEYBOARDYELLOW)
            controls.push_back("KEYBOARD");
    }
    return controls;
}

inline void XRay::setPlayerControls(const std::vector<std::string> &playerControls)
{
    // TODO: Prince
    _playersInput.pop_back();
    for (size_t y = 0; y < playerControls.size(); y++) {
        if (!playerControls[y].compare("NONE"))
            _controlsTab[y] = Resources::UNKNOWN;
        else if (!playerControls[y].compare("XBOX")) {
            _controlsTab[y] = Resources::XBOXYELLOW;
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(1)));
        } else if (!playerControls[y].compare("PLAYSTATION")) {
            _controlsTab[y] = Resources::PLAYSTATIONYELLOW;
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(0)));
        } else if (!playerControls[y].compare("MOUSE")) {
            _controlsTab[y] = Resources::MOUSEYELLOW;
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new MousePlayerInput()));
        } else if (!playerControls[y].compare("KEYBOARD")) {
            _controlsTab[y] = Resources::KEYBOARDYELLOW;
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new KeyboardPlayerInput()));
        }
    }
}

inline void XRay::displayEndScores()
{
    size_t i = 0;

    std::sort(_scores.begin(), _scores.end(), [] (std::pair<std::string, std::string> a, std::pair<std::string, std::string> b){return std::stoi(a.second) > std::stoi(b.second);});
    for (const auto &score : _scores) {
        Raylib::Text::drawText("PLAYER " + score.first + " - SCORE " + score.second, 1150, 520 + i, 30, Raylib::Color::Black());
        i+=120;
    }

}