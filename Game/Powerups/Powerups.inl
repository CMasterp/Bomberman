/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Powerups.inl
*/

inline std::string Game::Powerups::getType() const
{
    return "Item";
}

inline void Game::Life::applyPowerupTo(Game::Player &player)
{
    player.increasePowerUps(P_LIFE);
}

inline void Game::Speed::applyPowerupTo(Game::Player &player)
{
    player.increasePowerUps(P_SKATE);
}

inline void Game::BombUp::applyPowerupTo(Game::Player &player)
{
    player.increasePowerUps(P_BOMB);
}

inline void Game::Fire::applyPowerupTo(Game::Player &player)
{
    player.increasePowerUps(P_FIRE);
}

inline void Game::Pass::applyPowerupTo(Game::Player &player)
{
    player.increasePowerUps(P_PASS);
}