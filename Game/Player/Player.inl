/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

inline std::string Game::Player::getName(void) const
{
    return _name;
}

inline size_t Game::Player::getBrokenWalls(void) const
{
    return _brokenWalls;
}

inline size_t Game::Player::getKills(void) const
{
    return _kills;
}

inline std::array<int, 5> Game::Player::getPowerUps(void) const
{
    return _powerUps;
}

inline int Game::Player::getID(void) const
{
    return _ID;
}

inline void Game::Player::setName(const std::string &name)
{
    _name = name;
}

inline void Game::Player::setBrokenWalls(const size_t &brokenWalls)
{
    _brokenWalls = brokenWalls;
}

inline void Game::Player::setKills(const size_t &kills)
{
    _kills = kills;
}

inline void Game::Player::setPowerUps(const std::array<int, 5> &powerUps)
{
    _powerUps = powerUps;
}

inline void Game::Player::setID(const int &ID)
{
    _ID = ID;
}

inline std::string Game::Human::getType() const
{
    return ("Human");
}

inline std::string Game::AI::getType() const
{
    return ("AI");
}

inline bool Game::Player::dropBomb()
{
    if (_powerUps[P_BOMB] - _bomb_droped >= 0)
    {
        _bomb_droped++;
        return true;
    }
    return false;
}

inline void Game::Player::resetABomb()
{
    _bomb_droped--;
}

inline void Game::Player::increasePowerUps(const int &id_power)
{
    _powerUps[id_power]++;
}

inline void Game::Player::decreasePowerUps(const int &id_power)
{
    _powerUps[id_power]--;
}

inline void Game::Player::setAlive(const bool &alive)
{
    _alive = alive;
}

inline bool Game::Player::getAlive() const
{
    return _alive;
}