/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

#ifndef ASTAR_HPP_
#define ASTAR_HPP_

#include <utility>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <list>
#include <algorithm>

namespace Game
{
    class Point
    {
    public:
        /**
         * @brief Construct a new Point object
         *
         * @param x The abscissa coordinate
         * @param y The ordinate coordinate
         */
        Point(const int &x = 0, const int &y = 0);

        /**
         * @brief Equal operator
         *
         * @param point Point to compare
         * @return true if the points are the same, false otherwise
         */
        bool operator==(const Point &point) {
            return (point._x == _x && point._y == _y);
        }

        /**
         * @brief Unequal operator
         *
         * @param point Point to compare
         * @return true if the points are the different, false otherwise
         */
        bool operator!=(const Point &point) {
            return (point._x != _x || point._y != _y);
        }

        /**
         * @brief Add operator
         *
         * @param point Point to add
         * @return A new point with addition positions
         */
        Point operator+(const Point &point) {
            return Point(point._x + _x, point._y + _y);
        }

        /**
         * @brief Assign operator
         *
         * @param point Point to assign
         * @return A reference to the assign point Object
         */
        Point &operator=(const Point &point) {
            _x = point._x;
            _y = point._y;
            return *this;
        }

        int _x; // The abscissa coordinate
        int _y; // The ordinate coordinate
    };

    class Node
    {
    public:
        /**
         * @brief Construct a new Node object
         *
         * @param positions The Node positions
         * @param parentPositions The node's parent positions
         * @param g The movement cost
         * @param h The movement heuristic
         */
        Node(const Point &positions, const Point &parentPositions, const int &g, const int &h);

        /**
         * @brief Equal operator
         *
         * @param point Point to compare
         * @return true if the points are the same, false otherwise
         */
        bool operator==(const Point point) {
            return _positions == point;
        }

        Point _positions; // Square positions
        Point _parentPositions; // Parent square positions
        int _g; // The movement cost to move from the starting point to a given square on the grid, following the path generated to get there
        int _h; // The estimated movement cost to move from that given square/node on the grid to the final destination
    };

    class Astar
    {
    public:
        /**
         * @brief Construct a new Astar object
         *
         * @param map The map
         * @param start The start point
         * @param target The end map
         */
        Astar(const std::vector<std::string> &map, const Point &start, const Point &target);

        /**
         * @brief Find a path to the target
         *
         * @return true if the destination has been found, false otherwise
         */
        bool targetIsFound(void);

        /**
         * @brief Fill the path finding
         *
         * @param path A reference to the path (list of Points)
         * @return int - The final heuristic cost
         */
        int fillPath(std::list<Point> &path);

    private:
        std::vector<std::string> _map; // The map
        std::pair<int, int> _mapDimensions; // The map dimensions (first: width, second: height)
        Point _start; // The start point
        Point _target; // The start point
        std::list<Node> _open; // Open list of nodes
        std::list<Node> _close; // Closed list of nodes
        std::array<Point, 8> _neighbors; // An array of 8 points representing the 8 neighbors of the current node
        // #######
        // #0#4#1#
        // #######
        // #5#C#7#  THE NEIGHBORS[8]
        // #######
        // #2#6#3#
        // #######

        /**
         * @brief Check if current cell is valid (not out map ranges)
         *
         * @param currentCell Current node
         * @return true if current cell is in map ranges, false otherwise
         */
        bool isInMap(const Point &currentCell) const;

        /**
         * @brief Check if current cell is blocked or not
         *
         * @param currentCell Current node
         * @return true if current cell is unblocked, false otherwise
         */
        bool isUnBlocked(const Point &currentCell) const;

        /**
         * @brief Check if the current cell is the destination cell
         *
         * @param currentCell Current node
         * @return true if current cell is the destination, false otherwise
         */
        bool isDestination(Point &currentCell) const;

        /**
         * @brief Reach the target
         *
         * @param openHead The open list head
         * @return true if the destination has been reached, false otherwise
         */
        bool targetIsReached(Node &openHead);

        /**
         * @brief Check if a cell has a best quality cost than the current cost
         *
         * @param currentCell Current node
         * @param currentCost The current heuristic cost (addition of g and h variables)
         * @return true if current cell has a best cost quality than the current cost
         */
        bool isQualityNode(const Point &currentCell, const int &currentCost);

        /**
         * @brief Calcul the heuristic distance between a cell and the target (Euclidean Distance)
         *
         * @param currentCell Current node
         * @return float - The heuristic distance between a cell and the target
         */
        float calculateHValue(const Point &currentCell) const;
    };

#include "Astar.inl"
}

#endif /* !ASTAR_HPP_ */
