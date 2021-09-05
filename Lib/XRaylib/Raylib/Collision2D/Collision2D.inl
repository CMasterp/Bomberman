/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera2D
*/

inline bool Raylib::Collision2D::checkCollision(const Rectangle &rec1, const Rectangle &rec2)
{
    return ::CheckCollisionRecs(rec1.getCStruct(), rec2.getCStruct());
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &center1, const float &radius1, const Vector2 &center2, const float &radius2)
{
    return ::CheckCollisionCircles(center1.getCStruct(), radius1, center2.getCStruct(), radius2);
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &center, const float &radius, const Rectangle &rec)
{
    return ::CheckCollisionCircleRec(center.getCStruct(), radius, rec.getCStruct());
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &point, const Rectangle &rec)
{
    return ::CheckCollisionPointRec(point.getCStruct(), rec.getCStruct());
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &point, const Vector2 &center, const float &radius)
{
    return ::CheckCollisionPointCircle(point.getCStruct(), center.getCStruct(), radius);
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &point, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3)
{
    return ::CheckCollisionPointTriangle(point.getCStruct(), p1.getCStruct(), p2.getCStruct(), p3.getCStruct());
}

inline bool Raylib::Collision2D::checkCollision(const Vector2 &startPos1, const Vector2 &endPos1, const Vector2 &startPos2, const Vector2 &endPos2, Vector2 &collisionPoint)
{
    ::Vector2 collisionVector;
    bool res = ::CheckCollisionLines(startPos1.getCStruct(), endPos1.getCStruct(), startPos2.getCStruct(), endPos2.getCStruct(), &collisionVector);

    collisionPoint = collisionVector;
    return res;
}

inline Rectangle Raylib::Collision2D::getCollision(const Rectangle &rec1, const Rectangle &rec2)
{
    return Rectangle(::GetCollisionRec(rec1.getCStruct(), rec2.getCStruct()));
}