/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Engine::Core::Core()
        : _graphical{std::make_shared<XRay>()}, _game{std::make_shared<Game::Bomberman>()}, _userNames{{""}}
{
    _graphical->setLoadFunc([this] (std::string filepath) {this->loadGame(filepath);});
    _graphical->setSaveFunc([this] (std::array<std::size_t, 9> settings, std::vector<std::string> playerControls) {this->saveGame(settings, playerControls);});
    _graphical->setRestartFunc([this] () {_refreshFlag = 0; this->restartGame();});
    _graphical->setSettingsFunc([this] (std::array<std::size_t, 9> settings) {_game->setSettings(settings);});
    _graphical->setPlayerActionsFunc([this] (const size_t playerID, const std::string action) {_game->doPlayerAction(playerID, action);});
}

Engine::Core::~Core()
{
}

void Engine::Core::saveGame(std::array<std::size_t, 9> settings, std::vector<std::string> playerControls)
{
    _game->saveGame(settings, playerControls);
}

void Engine::Core::loadGame(std::string filepath)
{
    _refreshFlag = 0;
    _game->loadGame(filepath);
    _graphical->setGameSettings(_game->getSettings());
    _graphical->setMapSize(_game->getMap().size()-2);
    _graphical->setUserNames(_game->getUserNames());
    _graphical->setPlayerControls(_game->getPlayerControls());
}

void Engine::Core::restartGame()
{
    _game->restart();
}

void Engine::Core::run(void)
{
    while (_scene != IGraphical::END_GAME && !_graphical->shouldCloseWindow()) {
        getBackupFiles();
        if (_graphical->getBackups() != _backups)
            _graphical->setBackups(_backups);
        _graphical->display();
        _scene = _graphical->getScene();
        if (_scene == IGraphical::IN_GAME && _game) {
            if (_refreshFlag == 0 || _userNames != _graphical->getUserNames()) {
                _userNames = _graphical->getUserNames();
                _game->setMapType(_graphical->getMapSizeAndType().second);
                _game->setUserNames(_graphical->getUserNames());
                _graphical->setMap(_game->getMap(_graphical->getMapSizeAndType().first));
                _game->setPlayers(_graphical->getPlayersData());
            }
            if (_game->isCameraShaking())
                _graphical->cameraShake();
            if (!_isPaused)
            {
                _game->updateGame();
            }
            if (!_game->isGameOver() && !endGame()) {
                _graphical->setScores(_game->getScores());
                _graphical->updateGameInfos(_game->getEntities());
                _graphical->setPlayersStats(_game->getPlayersStats());
            }
            _refreshFlag++;
        } else
            _refreshFlag = 0;
    }
    _graphical->closeWindow();
}

void Engine::Core::getBackupFiles(void)
{
    std::string dirBackups(".backups/");
    std::filesystem::directory_iterator itBackups(dirBackups);

    _backups.clear();
    for (const auto &file: itBackups)
        if (file.path().filename().extension() == ".backup")
            _backups.push_back(file.path().filename().string());
}

void Engine::Core::saveBestScores(void)
{
    // Get all scores and sort them in ascending order
    std::vector<std::pair<std::string, std::string>> _scores =  _game->getScores();

    for(auto& s: _scores)
        _gameHighScores.emplace_back(s);
    std::sort(_gameHighScores.begin(), _gameHighScores.end(), [](const auto &a, const auto &b){
        return std::stoi(a.second.c_str()) >= std::stoi(b.second.c_str());
    });

    // Keep only the top 10 scores
    if (_gameHighScores.size() > 10)
        _gameHighScores.erase(_gameHighScores.begin() + 10, _gameHighScores.end());

    // Write in file
    std::string dirBestScores(".scores/");
    std::string path(dirBestScores + _currentGame);
    std::ofstream fileScores(path);

    if (!fileScores.good())
        throw "ERROR: problem with score's file";
    for (const auto &score : _gameHighScores)
        fileScores << (score.first.empty() ? "Unknown" : score.first) << " " << score.second << std::endl;
    fileScores.close();
}

bool Engine::Core::endGame(void)
{
    if (_graphical->getScene() != IGraphical::IN_GAME || !_game->isGameOver())
        return false;
    _graphical->setScene(IGraphical::END_GAME);
    saveBestScores();
    _graphical->setBestScores(_gameHighScores);
    _graphical->setPlayersStats(_game->getPlayersStats());
    return true;
}