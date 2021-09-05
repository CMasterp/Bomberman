
/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Bomb
*/

inline int Game::Bomb::makeExplode()
{
    _explosing = false;
    _reseter.resetABomb();
    return _fire;
}

inline void Game::Bomb::increasePlayerWall()
{
    _reseter.setBrokenWalls(_reseter.getBrokenWalls() + 1);
}

inline bool Game::Bomb::isExploding()
{
    return _explosing;
}

inline bool Game::Bomb::hasExplode()
{
    return _exploded;
}

inline std::string Game::Bomb::getType() const
{
    return "Bomb";
}

inline void Game::Bomb::setPlayers(std::vector<std::shared_ptr<Game::Player>> players)
{
    _players = players;
}

inline void Game::Bomb::update()
{
    if (clock.doesTimeElapsed(4, false)) {
        _explosing = false;
        _exploded = true;
    } else if (clock.doesTimeElapsed(3, false) && _bZoneX.first == 0 && _bZoneX.second == 0 && _bZoneY.first == 0 && _bZoneY.second == 0)
        _explosing = true;
}

inline void Game::Bomb::setBombzone(std::vector<std::string> map)
{
    Raylib::Vector3 pos = Animated::getPositions();

    pos.y = map.size() - pos.y;

    _bZoneX.first = static_cast<int>(pos.x);
    _bZoneX.second = 0;

    for (int i = 1; map[pos.y][pos.x - i] == 'X'; i++)
        _bZoneX.first--;
    for (int i = 0; map[pos.y][_bZoneX.first + i] == 'X'; i++)
        _bZoneX.second++;

    _bZoneY.first = static_cast<int>(pos.y);
    _bZoneY.second = 0;

    for (int i = 1; map[pos.y - i][pos.x] == 'X'; i++)
        _bZoneY.first--;
    for (int i = 0; map[_bZoneY.first + i][pos.x] == 'X'; i++)
        _bZoneY.second++;

    _bZoneY.first = map.size() - _bZoneY.first;
}

inline void Game::Bomb::drawEntity()
{
    Raylib::Vector3 pos = Animated::getPositions();
    static Raylib::Sound boom ("resources/Sound/boom.wav");
    static Raylib::Texture fire ("resources/assets/fire.png");
    std::vector<Raylib::Vector3> explosion;

    if (_bZoneX.first != 0 && _bZoneX.second != 0 && _bZoneY.first != 0 && _bZoneY.second != 0)
    {
        for (int i = 0; i < _bZoneX.second; i++) {
            Raylib::Drawing::drawCubeTexture(fire.getCStruct(), {static_cast<float>(_bZoneX.first) + i, pos.y, pos.z}, 1 , 1, 1, Raylib::Color::Red());
            explosion.push_back({static_cast<float>(_bZoneX.first) + i, pos.y, pos.z});
        }
        for (int i = 0; i < _bZoneY.second; i++) {
            Raylib::Drawing::drawCubeTexture(fire.getCStruct(), {pos.x, static_cast<float>(_bZoneY.first) - i, pos.z}, 1, 1, 1, Raylib::Color::Red());
            explosion.push_back({pos.x, static_cast<float>(_bZoneY.first) - i, pos.z});
        }
        Raylib::Drawing::drawSphere(Animated::getPositions(), 0.9, Raylib::Color::Red());
        explosion.push_back(Animated::getPositions());
        if (!boom.isPlaying())
            boom.play();
    }
    for (const Raylib::Vector3 &explosionCollision : explosion) {
        for (size_t t = 0; t < _players.size(); t++) {
            if (_players[t]->getPositions().x >= explosionCollision.x - 0.5
                && _players[t]->getPositions().y >= explosionCollision.y - 0.5
                && _players[t]->getPositions().x <= explosionCollision.x + 0.5
                && _players[t]->getPositions().y <= explosionCollision.y + 0.5)
            {
                _pointerToSetPlayer(_players[t]->getID());
                _reseter.setKills(_reseter.getKills() + 1);
            }
        }
    }
    Animated::drawEntity();
}
