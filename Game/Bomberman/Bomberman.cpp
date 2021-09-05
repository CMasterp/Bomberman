/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#include "Bomberman.hpp"

Game::Bomberman::Bomberman(void)
        : _gameName{"Bomberman"}, _gameOver{false}
{
    std::srand(static_cast<unsigned>(time(0)));
    for (size_t z = 0; z < 4; z++) {
        _playersStats.push_back({{"", "0"}, {"", "0"}, {"", "0"}, {"", "0"}});
        _scores.push_back({"", "0"});
    }
}

Game::Bomberman::~Bomberman(void)
{
}

void Game::Bomberman::initEntities()
{
    float x;
    float y = _map.size();
    float scale;
    int dic_index = 0;

    if (!_isALoad)
        _entities.clear();

    // Push back floor and borders
    _entities.push_back(std::shared_ptr<IEntity>(new Game::Floor(Raylib::Vector3((y-1)/2, (y+1)/2, -1), _mapType, y-2, y-1, 1.0f)));
    _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3(0, (y+1)/2, 0), _mapType, 1.0f, y, 1.0f)));
    _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3((y-1)/2, y, 0), _mapType, y-2, 1.0f, 1.0f)));
    _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3((y-1)/2, 1, 0), _mapType, y-2, 1.0f, 1.0f)));
    _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3(_map.at(0).size()-1, (y+1)/2, 0), _mapType, 1.0f, y, 1.0f)));

    for (const std::string &line : _map) {
        x = 0;
        for (const char &c : line) {
            if (!_isALoad && (c == 'H' || c == 'A') && dic_index < _players.size())
            {
                if (c == 'H')
                    _entities.push_back(std::shared_ptr<IEntity>(new Game::Human(_players[dic_index].name, dic_index, {x, y, 0}, _players[dic_index].obj, _players[dic_index].texture, _players[dic_index].animations, _players[dic_index].scalable, _players[dic_index].color)));
                else if (c == 'A')
                    _entities.push_back(std::shared_ptr<IEntity>(new Game::AI(_players[dic_index].name, dic_index, {x, y, 0}, _players[dic_index].obj, _players[dic_index].texture, _players[dic_index].animations, _players[dic_index].scalable, _players[dic_index].color)));
                dic_index++;
            }
            else if (c == 'W')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3(x, y, 0), _mapType)));
            else if (c == 'M')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::BreakableWall(Raylib::Vector3(x, y, 0), _mapType)));
            x++;
        }
        y--;
    }
}

std::vector<std::string> &Game::Bomberman::getMap()
{
    return _map;
}

std::vector<std::string> &Game::Bomberman::getMap(const size_t &size)
{
    if (_map.size() != size+2) {
        Game::Map newMap(size, size, std::make_pair(_settings[HUMAN_NBR], _settings[AI_NBR]));
        _map = newMap.getMap();
    }
    return _map;
}

void Game::Bomberman::initPlayersStats()
{
    _playersStats.clear();
    _scores.clear();
    for (size_t i = 0; i < _userNames.size(); i++) {
        _scores.push_back(std::make_pair(_userNames[i], "0"));
    }
}

bool Game::Bomberman::playerGotHit(const std::pair<int, int> &pos, const float &posX, const float &posY) const
{
    if (pos.first >= posX && pos.first <= posX + 1 && pos.second >= posY && pos.second <= posY + 1)
        return true;
    return false;
}

void Game::Bomberman::randomDropItem(const Raylib::Vector3 &pos)
{
    int r_value = CFunctions::generateRandomInteger(100);

    if (0 <= r_value && r_value <= 14)
        _entities.push_back(std::shared_ptr<IEntity>(new Game::BombUp(pos.getCStruct())));
    else if (15 <= r_value && r_value <= 29)
        _entities.push_back(std::shared_ptr<IEntity>(new Game::Fire(pos.getCStruct())));
    else if (30 <= r_value && r_value <= 39)
        _entities.push_back(std::shared_ptr<IEntity>(new Game::Speed(pos.getCStruct())));

}

void Game::Bomberman::eraseEntitiesOnBomb(const std::pair<int, int> &pos)
{
    size_t index = 0;
    Raylib::Vector3 banned(1, 1, 0);
    Game::Player *res = nullptr;

    for (const auto &entity : _entities)
    {
        if (entity->getType() == "BreakableWall" && entity->getPositions().x == pos.first && _map.size() - entity->getPositions().y == pos.second)
        {
            randomDropItem(entity->getPositions());
            _entities.erase(_entities.begin() + index);
            break;
        }
        index++;
    }
}

void Game::Bomberman::setCharOnRadius(const char &c, const int &rad, std::pair<int, int> pos, Game::Bomb &bomb)
{
    char current = _map[pos.second][pos.first];

    std::cout << "C ==>" << current << std::endl;
    if (current == 'H' || current == 'A')
        eraseEntitiesOnBomb({pos.first, pos.second});
    _map[pos.second][pos.first] = c;

    for (int i = 1; i <= rad; i++)
    {
        current = _map[pos.second][pos.first + i];
        if (current == 'W' || current == 'X' || current == 'E')
            break;
        if (current == 'M')
        {
            _map[pos.second][pos.first + i] = c;
            bomb.increasePlayerWall();
            eraseEntitiesOnBomb({pos.first + i, pos.second});
            break;
        }
        _map[pos.second][pos.first + i] = c;
    }
    for (int i = 1; i <= rad; i++)
    {
        current = _map[pos.second][pos.first - i];
        if (current == 'W' || current == 'X' || current == 'E')
            break;
        if (current == 'M')
        {
            _map[pos.second][pos.first - i] = c;
            bomb.increasePlayerWall();
            eraseEntitiesOnBomb({pos.first - i, pos.second});
            break;
        }
        _map[pos.second][pos.first - i] = c;
    }
    for (int i = 1; i <= rad; i++)
    {
        current = _map[pos.second + i][pos.first];
        if (current == 'W' || current == 'X' || current == 'E')
            break;
        if (current == 'M')
        {
            _map[pos.second + i][pos.first] = c;
            bomb.increasePlayerWall();
            eraseEntitiesOnBomb({pos.first, pos.second + i});
            break;
        }
        _map[pos.second + i][pos.first] = c;
    }
    for (int i = 1; i <= rad; i++)
    {
        current = _map[pos.second - i][pos.first];
        if (current == 'W' || current == 'X' || current == 'E')
            break;
        if (current == 'M') {
            _map[pos.second - i][pos.first] = c;
            bomb.increasePlayerWall();
            eraseEntitiesOnBomb({pos.first, pos.second - i});
            break;
        }
        _map[pos.second - i][pos.first] = c;
    }
}

void Game::Bomberman::bombExplosion(Game::Bomb &bomb, const size_t &index)
{
    int rad = 0;
    std::pair<int, int> pos = bomb.getPositions2D();
    pos.second = _map.size() - pos.second;

    if (bomb.hasExplode())
    {
        _entities.erase(_entities.begin() + index);
        _isCameraShaking = false;
    }
    else if (bomb.isExploding())
    {
        _isCameraShaking = true;
        rad = bomb.makeExplode();
        setCharOnRadius('X', rad, pos, bomb);
        bomb.setBombzone(_map);
        for (int y = 0;  y < _map.size(); y++)
        {
            for (int x = 0; x < _map[0].size(); x++)
            {
                std::cout << _map[y][x];
                if (_map[y][x] == 'X')
                    _map[y][x] = '*';
            }
            std::cout << std::endl;
        }
    }
}

void Game::Bomberman::handleIfPlayerIsNearAnItem(Player &player)
{
    size_t index = 0;
    static Raylib::Sound sound ("resources/Sound/tudum.wav");

    for (auto &entity : _entities)
    {
        if (dynamic_cast<Game::Powerups *>(entity.get()) != nullptr && CheckCollisionSpheres(player.getPositions().getCStruct(), 0.3, entity->getPositions().getCStruct(), 0.3))
        {
            dynamic_cast<Game::Powerups *>(entity.get())->applyPowerupTo(player);
            sound.play();
            std::cout << "<<<< Got the..." << std::endl;
            _entities.erase(_entities.begin() + index);
            std::cout << "<<<< Item" << std::endl;
        }
        index++;
    }
}

template <typename T>
std::vector<std::pair<int, int>> Game::Bomberman::getEntitiesPositions(void) const
{
    std::vector<std::pair<int, int>> entitiesPos;
    int x = 0, y = 0;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if (dynamic_cast<T*>(entity.get()))
        {
            Raylib::Vector3 entityPos = entity->getPositions();
            x = static_cast<int>(entityPos.x);
            y = static_cast<int>(_map.size() - entityPos.y);
            entitiesPos.push_back(std::make_pair(x, y));
        }
    }
    return entitiesPos;
}

template<typename T>
std::vector<T*> Game::Bomberman::getEntitiesData(void) const
{
    std::vector<T*> entities;
    size_t i = 0;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if (dynamic_cast<T*>(entity.get()))
        {
            entities.push_back(dynamic_cast<T*>(entity.get()));
            i++;
        }
    }
    std::cout << "Found " << i << " Players";
    return entities;
}

std::vector<std::string> Game::Bomberman::placeEntitiesOnMap(const std::vector<std::pair<int, int>> &entitiesPos, const char &c) const
{
    std::vector<std::string> map = _map;

    for (int y = 0; y < map.size(); y++)
    {
        for (int x = 0; x < map[0].size(); x++)
        {
            if (std::find(entitiesPos.begin(), entitiesPos.end(), std::make_pair(x, y)) != entitiesPos.end())
            {
                map[y][x] = c;
            }
        }
    }
    return map;
}

void Game::Bomberman::runAI(void)
{
    // Get AIs and targets entities
    std::vector<std::shared_ptr<IEntity>> targets;
    std::vector<AI> AIs;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if (dynamic_cast<Game::Human*>(entity.get()))
        {
            targets.push_back(std::make_shared<Game::Human>(*dynamic_cast<Game::Human *>(entity.get())));
        }
        else if (dynamic_cast<Game::Fire*>(entity.get()) && _settings[AI_LVL] == 3)
        {
            targets.push_back(std::make_shared<Game::Fire>(*dynamic_cast<Game::Fire*>(entity.get())));
        }
        else if (dynamic_cast<Game::Speed*>(entity.get()) && _settings[AI_LVL] == 3)
        {
            targets.push_back(std::make_shared<Game::Speed>(*dynamic_cast<Game::Speed*>(entity.get())));
        }
        else if (dynamic_cast<Game::BombUp*>(entity.get()) && _settings[AI_LVL] == 3)
        {
            targets.push_back(std::make_shared<Game::BombUp>(*dynamic_cast<Game::BombUp*>(entity.get())));
        }
        else if (dynamic_cast<Game::AI*>(entity.get()))
        {
            AIs.push_back(*dynamic_cast<Game::AI *>(entity.get()));
        }
    }

    // Run AI algorithm
    try
    {
        ArtificialIntelligence AI(
                [this] (const size_t playerID, const std::string action) {doPlayerAction(playerID, action);},
                AIs,
                targets,
                placeEntitiesOnMap(getEntitiesPositions<Game::Bomb>(), 'B'),
                _settings[AI_LVL]
        );
        AI.run();
    }
    catch(const std::invalid_argument &error)
    {
        std::cerr << error.what() << std::endl;
    }
}

void Game::Bomberman::updateEntities()
{
    size_t index = 0;
    Game::Bomb *bomb = nullptr;

    for (auto &entity : _entities)
    {
        if (dynamic_cast<Game::Player *>(entity.get()) != nullptr)
            handleIfPlayerIsNearAnItem(*dynamic_cast<Game::Player *>(entity.get()));
        if ((bomb = dynamic_cast<Game::Bomb *>(entity.get())) != nullptr)
        {
            bomb->update();
            bombExplosion(*bomb, index);
        }
        index++;
    }

    // Run AI algorithm
    if (_aiClock.doesTimeElapsed(0.03f))
    {
        runAI(); //<-- on prend aucun risque chkl segfault aussi ici
    }
}

void Game::Bomberman::updateScores()
{
}

void Game::Bomberman::updatePlayersStats()
{
}

void Game::Bomberman::restart(void)
{
    size_t y = _map.size()-2;
    // Reset Scores
    // TODO: TO IMPLEMENT
    _reinit = 0;
    _isALoad = false;
    _map.clear();
    getMap(y);
    _scores.clear();
    _playersStats.clear();
    for (size_t z = 0; z < 4; z++) {
        _playersStats.push_back({{"", "0"}, {"", "0"}, {"", "0"}, {"", "0"}});
        _scores.push_back({"", "0"});
    }
    // Reset Entities
}

void Game::Bomberman::saveGame(std::array<std::size_t, 9> settings, std::vector<std::string> playerControls)
{
    // Get players entities
    std::vector<std::shared_ptr<Game::Player>> players;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if (entity->getType().compare("Human") == 0)
        {
            players.push_back(std::make_shared<Game::Human>(*dynamic_cast<Game::Human *>(entity.get())));
        }
        else if (entity->getType().compare("AI") == 0)
        {
            players.push_back(std::make_shared<Game::AI>(*dynamic_cast<Game::AI *>(entity.get())));
        }
    }

    // Get Map
    Game::Map map;
    map.setHeight(_map.size() - 2);
    map.setWidth(_map[0].size() - 2);
    map.setMap(_map);

    // Save it all
    settings[TIMESTAMP] = std::time(0);
    settings[WORLD] = _mapType;
    Game::Save save(settings, players, playerControls, map);
}

void Game::Bomberman::loadGame(const std::string &backupFilePath)
{
    // Parse data
    Game::Save load(".backups/" + backupFilePath);

    _isALoad = true;
    // Load players
    std::vector<std::shared_ptr<Game::Player>> players = load.getPlayers();
    for (const std::shared_ptr<Game::Player> &player : players)
    {
        _entities.push_back(player);
    }

    std::cout << getEntitiesData<Game::Player>() << std::endl;
    // Load the user names
    _userNames = load.getUserNames();

    // Load player controls
    _playerControls = load.getPlayerControls();

    // Load map
    _map = load.getMap().getMap();

    // Load the settings
    _settings = load.getSettings();
}

void Game::Bomberman::setPlayers(const std::vector<CharDictionary> &playersData)
{
    _players = playersData;
}

void Game::Bomberman::updateGame(void)
{
    if (_reinit == 0) {
        initEntities();
        initPlayersStats();
        _reinit++;
    }
    _sharedPlayers.clear();
    for (const std::shared_ptr<IEntity> &entity : _entities) {
        if (entity->getType().compare("Human") == 0)
            _sharedPlayers.push_back(std::make_shared<Game::Human>(*dynamic_cast<Game::Human *>(entity.get())));
        else if (entity->getType().compare("AI") == 0)
            _sharedPlayers.push_back(std::make_shared<Game::AI>(*dynamic_cast<Game::AI *>(entity.get())));
    }
    if (!_gameOver) {
        updateEntities();
        updateScores();
        updatePlayersStats();
    }
}