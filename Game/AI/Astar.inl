/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

inline float Game::Astar::calculateHValue(const Point &currentCell) const
{
    // For diagonals (Euclidean Distance)
    // return std::sqrt(std::pow(_target._x - currentCell._x, 2) + std::pow(_target._y - currentCell._y, 2));
    // Without diagonals (Manhattan Distance)
    return std::abs(currentCell._x - _target._x) + std::abs(currentCell._y - _target._y);
}

inline bool Game::Astar::isInMap(const Point &currentCell) const
{
    return currentCell._x >= 0 && currentCell._x < _mapDimensions.first
           && currentCell._y >= 0 && currentCell._y < _mapDimensions.second;
}

inline bool Game::Astar::isUnBlocked(const Point &currentCell) const
{
    return _map[currentCell._y][currentCell._x] == '*';
}

inline bool Game::Astar::isDestination(Point &currentCell) const
{
    return currentCell == _target;
}