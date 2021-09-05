/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

#include "ArtificialIntelligence.hpp"

Game::ArtificialIntelligence::ArtificialIntelligence(std::function<void (const size_t pos, const std::string action)> playerActionsFunc, const std::vector<AI> &AIs, std::vector<std::shared_ptr<IEntity>> entities, const std::vector<std::string> &map, const size_t &level)
        : _playerActionsFunc(playerActionsFunc), _AIs(AIs), _entities(entities), _map(map), _level{level}
{
    if (AIs.empty())
    {
        throw std::invalid_argument("ERROR: No AIs");
    }
}

void Game::ArtificialIntelligence::run(void) const
{
    int smallestDistance = _map.size() * 2;
    Raylib::Vector3 targetPositions = {0, 0, 0};
    std::list<Point> path;
    std::pair<int, int> point;
    int xAI = 0, yAI = 0, xEntity = 0, yEntity = 0, xTarget = 0, yTarget = 0, currentDistance = 0;
    bool isPowerUp = false;

    for (const Game::AI &AI : _AIs)
    {
        // Get AI positions
        Raylib::Vector3 AIPositions = AI.getPositions();
        xAI = static_cast<int>(std::round(AIPositions.x));
        yAI = static_cast<int>(std::round(AIPositions.y));

        for (const std::shared_ptr<IEntity> &entity : _entities)
        {
            // Get entity positions
            Raylib::Vector3 entityPositions = entity->getPositions();
            xEntity = static_cast<int>(std::round(entityPositions.x));
            yEntity = static_cast<int>(std::round(entityPositions.y));

            // Calcul euclidean distance
            currentDistance = calculateDistance(Point(xAI, yAI), Point(xEntity, yEntity));

            // Set the smallest distance
            smallestDistance = (currentDistance < smallestDistance) ? currentDistance : smallestDistance;

            // Set the target positions
            if (smallestDistance == currentDistance)
            {
                isPowerUp = (dynamic_cast<Game::Powerups*>(entity.get())) ? true : false;
                targetPositions = entityPositions;
                xTarget = static_cast<int>(std::round(targetPositions.x));
                yTarget = static_cast<int>(std::round(targetPositions.y));
            }
        }

        // Display the target
        std::cout << "AI n°" << AI.getID() << " Target " << xTarget << "," << (_map.size() - yTarget) << std::endl;

        // Run Astar algorithm
        Astar astar(_map, Point(xAI, (_map.size() - yAI)), Point(xTarget, (_map.size() - yTarget)));

        // Set the AI action
        static std::string action = "NONE";

        if (astar.targetIsFound())
        {
            // Get the path finding
            astar.fillPath(path);
            std::cout << "AI n°" << AI.getID();
            for(const Point &point : path)
            {
                std::cout << " (" << point._x << "," << point._y << ")";
            }
            std::cout << std::endl;

            // Get the next destination
            std::cout << "AI n°" << AI.getID() << " Next destination " << path.front()._x << "," << path.front()._y << std::endl;
            std::cout << "AI n°" << AI.getID() << " Positions " << xAI << "," << (_map.size() - yAI) << std::endl;
            point = std::make_pair(path.front()._x - xAI, path.front()._y - (_map.size() - yAI));
            std::cout << "AI n°" << AI.getID() << " " << convertPointIntoAction(point) << std::endl;

            // Order the AI to do this action
            action = convertPointIntoAction(point);

            // Switch in relation to AI level
            switch (_level) {
                case 1:
                    if (action.compare("dropBomb"))
                    {
                        action = (CFunctions::generateRandomInteger(10) < 3) ? "dropBomb" : action;
                        _playerActionsFunc(AI.getID(), action);
                    }
                    break;
                case 2:
                case 3:
                    if (!(action.compare("dropBomb") == 0 && isPowerUp))
                    {
                        _playerActionsFunc(AI.getID(), action);
                    }
                    break;
                default:
                    break;
            }

            // Clear the path
            path.clear();
        }
        else
        {
            if (action.compare("dropBomb"))
            {
                _playerActionsFunc(AI.getID(), action);
            }
        }
    }
}