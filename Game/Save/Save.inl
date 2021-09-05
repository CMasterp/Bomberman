/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

inline void Game::Save::writeSettings(std::ofstream &os) const
{
    os  << "settings timestamp " << _settings[TIMESTAMP] << std::endl
        << "settings set_nbr " << _settings[SET_NBR] << std::endl
        << "settings set_id " << _settings[SET_ID] << std::endl
        << "settings time_game " << _settings[TIME_GAME] << std::endl
        << "settings time_remaining " << _settings[TIME_REMAINING] << std::endl
        << "settings ai_nbr " << _settings[AI_NBR] << std::endl
        << "settings ai_lvl " << _settings[AI_LVL] << std::endl
        << "settings human_nbr " << _settings[HUMAN_NBR] << std::endl
        << "settings world " << _settings[WORLD] << std::endl;
}

inline void Game::Save::writePlayersInfos(std::ofstream &os) const
{
    int id = 0;

    for (const std::shared_ptr<Game::Player> &player : _players)
    {
        std::array powerups = player->getPowerUps();
        Raylib::Vector3 positions = player->getPositions();
        os  << "player " << id << " type " << player->getType() << std::endl
            << "player " << id << " name " << player->getName() << std::endl
            << "player " << id << " controls " << ((player->getType().compare("AI") == 0) ? "NONE" : _playerControls[id]) << std::endl
            << "player " << id << " scalable " << player->getScalable() << std::endl
            << "player " << id << " positions " << positions.x << "," << /* (_map.getMap().size() - positions.y) */ positions.y << "," << positions.z << std::endl
            << "player " << id << " powerups "
            << "skate:" << powerups[P_SKATE]
            << ",bomb:" << powerups[P_BOMB]
            << ",pass:" << powerups[P_PASS]
            << ",fire:" << powerups[P_FIRE]
            << ",life:" << powerups[P_LIFE]
            << std::endl
            << "player " << id << " broken_walls " << player->getBrokenWalls() << std::endl
            << "player " << id << " kills " << player->getKills() << std::endl;
        id++;
    }
}

inline void Game::Save::writeMap(std::ofstream &os) const
{
    os << "map dimensions " << _map.getWidth() << "," << _map.getHeight() << std::endl;
    for (const std::string &row : _map.getMap())
    {
        os << row << std::endl;
    }
}

inline std::string Game::Save::createBackupName(void) const
{
    std::string fileName(".backups/" + getCurrentDateTime() + ".backup");
    std::replace(fileName.begin(), fileName.end(), ' ', '-');
    return fileName;
}

inline std::array<std::size_t, 9> Game::Save::getSettings(void) const
{
    return _settings;
}

inline std::vector<std::shared_ptr<Game::Player>> Game::Save::getPlayers(void) const
{
    return _players;
}

inline Game::Map Game::Save::getMap(void) const
{
    return _map;
}

inline std::vector<std::string> Game::Save::getUserNames(void) const
{
    return _userNames;
}

inline std::vector<std::string> Game::Save::getPlayerControls(void) const
{
    return _playerControls;
}