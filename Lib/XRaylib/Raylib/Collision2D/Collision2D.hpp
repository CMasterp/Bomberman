/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Collision2D
*/

#ifndef COLLISION2D_HPP_
#define COLLISION2D_HPP_

#include <string>
#include <iostream>
#include "Vector2/Vector2.hpp"
#include "Rectangle/Rectangle.hpp"
#include "raylib.h"

namespace Raylib
{
    class Collision2D {
    public:
        /**
         * @brief Construct a new Collision2D object
         */
        Collision2D();

        /**
         * @brief Destroy the Collision2D object
         */
        ~Collision2D();

        /**
         * @brief Check if two rectangles intersect
         *
         * @param rec1 the first rectangle
         * @param rec2 the second one
         * @return true when the rectangles intersects false otherwise
         */
        static bool checkCollision(const Rectangle &rec1, const Rectangle &rec2);

        /**
         * @brief Check if two circles intersect
         *
         * @param center1 the first circle's center position
         * @param radius1 the first circle's radius
         * @param center2 the second circle's center position
         * @param radius2 the second circle's radius
         * @return true when the rectangles intersect false otherwise
         */
        static bool checkCollision(const Vector2 &center1, const float &radius1, const Vector2 &center2, const float &radius2);

        /**
         * @brief Check if a Rectangle and a Circle intersect
         *
         * @param center the circle's center position
         * @param radius the circle's radius
         * @param rec the rectangle
         * @return true when the rectangle and the circle intersect false otherwise
         */
        static bool checkCollision(const Vector2 &center, const float &radius, const Rectangle &rec);

        /**
         * @brief Check if a Point and a Rectangle intersect
         *
         * @param point the point coordinates
         * @param rec the rectangle
         * @return true when the point is on the rectangle false otherwise
         */
        static bool checkCollision(Vector2 const &point, const Rectangle &rec);

        /**
         * @brief Check if a Point and a Cercle intersect
         *
         * @param point the point coordinates
         * @param center the circle's center position
         * @param radius the circle's radius
         * @return true when the point is on the circle false otherwise
         */
        static bool checkCollision(const Vector2 &point, const Vector2 &center, const float &radius);

        /**
         * @brief Check if a Point and Triangle
         *
         * @param point the point coordinates
         * @param p1 the first triangle's point
         * @param p2 the second trinagle's point
         * @param p3 the third triangle's point
         * @return true when the point is on the trinagle false otherwise
         */
        static bool checkCollision(const Vector2 &point, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3);

        /**
         * @brief Check if 2 lines intersects and return the collision point
         *
         * @param startPos1 the first lines's start position
         * @param endPos1 the first lines's end position
         * @param startPos2 the second lines's start position
         * @param endPos2 the second lines's end position
         * @param collisionPoint the collision point pointer
         * @return true when the two lines intersect false otherwise
         */
        static bool checkCollision(const Vector2 &startPos1, const Vector2 &endPos1, const Vector2 &startPos2, const Vector2 &endPos2, Vector2 &collisionPoint);

        /**
         * @brief Get the Collision Rec object
         *
         * @param rec1 the first rectangle
         * @param rec2 the second rectangle
         * @return Rectangle corresponding the instersection zone
         */
        static Rectangle getCollision(const Rectangle &rec1, const Rectangle &rec2);

    };

#include "Collision2D.inl"

}

#endif /* !COLLISION2D_HPP_ */
