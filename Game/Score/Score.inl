/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

inline size_t Game::Score::getScore(void) const
{
    return _score;
}

inline void Game::Score::setScore(size_t const &score)
{
    _score = score;
}

inline float Game::Score::getCoefficient(void) const
{
    size_t percentage = (_settings[Settings::TIME_REMAINING] * 100) / _settings[TIME_GAME];

    if (50 < percentage && percentage <= 100) {
        return 1.5;
    } else if (30 < percentage && percentage <= 50) {
        return 1.3;
    } else {
        return 1;
    }
}