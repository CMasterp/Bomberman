/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Collision3D
*/

inline bool Raylib::Collision3D::checkCollision(const Vector3 &center1, const float &radius1, const Vector3 &center2, const float &radius2)
{
    return ::CheckCollisionSpheres(center1.getCStruct(), radius1, center2.getCStruct(), radius2);
}

inline bool Raylib::Collision3D::checkCollision(::BoundingBox const &box1, const ::BoundingBox &box2)
{
    return ::CheckCollisionBoxes(box1, box2);
}

inline bool Raylib::Collision3D::checkCollision(const ::BoundingBox &box1, const Vector3 &center, const float &radius)
{
    return ::CheckCollisionBoxSphere(box1, center.getCStruct(), radius);
}

inline bool Raylib::Collision3D::checkCollision(const ::Ray &ray, const Vector3 &center, const float &radius)
{
    return ::CheckCollisionRaySphere(ray, center.getCStruct(), radius);
}

inline bool Raylib::Collision3D::checkCollision(const ::Ray &ray, const Vector3 &center, const float &radius, Vector3 &collisionPoint)
{
    ::Vector3 collisionVector;
    bool res = ::CheckCollisionRaySphereEx(ray, center.getCStruct(), radius, &collisionVector);

    collisionPoint = collisionVector;
    return res;
}

inline bool Raylib::Collision3D::checkCollision(const ::Ray &ray, const ::BoundingBox &box)
{
    return ::CheckCollisionRayBox(ray, box);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(const ::Ray &ray, const ::Mesh &mesh, const ::Matrix &transform)
{
    return ::GetCollisionRayMesh(ray, mesh, transform);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(const ::Ray &ray, const ::Model &model)
{
    return ::GetCollisionRayModel(ray, model);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(const ::Ray &ray, const Vector3 &p1, const Vector3 &p2, const Vector3 &p3)
{
    return ::GetCollisionRayTriangle(ray, p1.getCStruct(), p2.getCStruct(), p3.getCStruct());
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(const ::Ray &ray, const float &groundHeight)
{
    return ::GetCollisionRayGround(ray, groundHeight);
}

