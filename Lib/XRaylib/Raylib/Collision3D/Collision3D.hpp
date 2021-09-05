/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Collision3D
*/

#ifndef COLLISION3D_HPP_
#define COLLISION3D_HPP_

#include <string>
#include <iostream>
#include "Vector3/Vector3.hpp"
#include "Rectangle/Rectangle.hpp"
#include "raylib.h"

namespace Raylib
{
    class Collision3D {
    public:
        /**
         * @brief Construct a new Collision3D object
         */
        Collision3D();

        /**
         * @brief Destroy the Collision3D object
         */
        ~Collision3D();

        /**
         * @brief Check if 2 spheres intersect
         *
         * @param center1 the first circle's center position
         * @param radius1 the first circle's radius
         * @param center2 the second circle's center position
         * @param radius2 the second circle's radius
         * @return true when the rectangles intersect, false otherwise
         */
        static bool checkCollision(const Vector3 &center1, const float &radius1, const Vector3 &center2, const float &radius2);

        /**
         * @brief Check if 2 spheres intersect
         *
         * @param center the circle's center position
         * @param radius the circle's radius
         * @param rec the rectangle
         * @return true when the rectangle and the circle intersect false otherwise
         */
        static bool checkCollision(const ::BoundingBox &box1, const ::BoundingBox &box);

        /**
         * @brief
         *
         * @param point the point coordinates
         * @param rec the rectangle
         * @return true when the point is on the rectangle false otherwise
         */
        static bool checkCollision(const ::BoundingBox &box1, const Vector3 &center, const float &radius);

        /**
         * @brief
         *
         * @param point the point coordinates
         * @param center the circle's center position
         * @param radius the circle's radius
         * @return true when the rectangle and the circle intersect false otherwise
         */
        static bool checkCollision(const ::Ray &ray, const Vector3 &center, const float &radius);

        /**
         * @brief
         *
         * @param point the point coordinates
         * @param p1 the first triangle's point
         * @param p2 the second trinagle's point
         * @param p3 the third triangle's point
         * @return true when the rectangle and the circle intersect false otherwise
         */
        static bool checkCollision(const ::Ray &ray, const Vector3 &center, const float &radius, Vector3 &collisionPoint);

        /**
         * @brief
         *
         * @param startPos1 the first lines's start position
         * @param endPos1 the first lines's end position
         * @param startPos2 the second lines's start position
         * @param endPos2 the second lines's end position
         * @param collisionPoint the collision point pointer
         * @return true when the rectangle and the circle intersect false otherwise
         */
        static bool checkCollision(const ::Ray &ray, const ::BoundingBox &box);

        /**
         * @brief Get the Collision Ray object
         *
         * @param ray The ray
         * @param mesh The mesh
         * @param transform The matrix transformation
         * @return RayHitInfo informations about the collision ray
         */
        static ::RayHitInfo getCollisionRay(const ::Ray &ray, const ::Mesh &mesh, const ::Matrix &transform);

        /**
         * @brief Get the Collision Ray object
         *
         * @param ray The ray
         * @param model The 3D model
         * @return RayHitInfo informations about the collision ray
         */
        static ::RayHitInfo getCollisionRay(const ::Ray &ray, const ::Model &model);

        /**
         * @brief Get the Collision Ray object
         *
         * @param ray The ray
         * @param p1 The first point
         * @param p2 The second point
         * @param p3 The thirst point
         * @return RayHitInfo informations about the collision ray
         */
        static ::RayHitInfo getCollisionRay(const ::Ray &ray, const Vector3 &p1, const Vector3 &p2, const Vector3 &p3);

        /**
         * @brief Get the Collision Ray object
         *
         * @param ray The ray
         * @param groundHeight The ground height
         * @return RayHitInfo informations about the collision ray
         */
        static ::RayHitInfo getCollisionRay(const ::Ray &ray, const float &groundHeight);

    };

#include "Collision3D.inl"

}

#endif /* !COLLISION3D_HPP_ */
