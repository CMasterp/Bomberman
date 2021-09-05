/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

inline float Game::ArtificialIntelligence::calculateDistance(const Point &start, const Point &end) const
{
    return std::sqrt(std::pow(end._x - start._x, 2) + std::pow(end._y - start._y, 2));
}

inline std::string Game::ArtificialIntelligence::convertPointIntoAction(const std::pair<int, int> &point) const
{
    std::map<std::pair<int, int>, std::string> actions = {
            {std::make_pair(0, 1), "goSouth"},
            {std::make_pair(0, -1), "goNorth"},
            {std::make_pair(-1, 0), "goEast"},
            {std::make_pair(1, 0), "goWest"},
            {std::make_pair(0, 0), "dropBomb"}
    };

    // Return the action as a string
    return actions.find(point)->second;
}