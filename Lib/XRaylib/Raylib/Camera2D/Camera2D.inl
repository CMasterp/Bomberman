/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera2D
*/

inline ::Camera2D Raylib::Camera2D::getCStruct(void) const
{
    return _camera2D;
}

inline void Raylib::Camera2D::beginMode2D(Raylib::Camera2D const &camera) const
{
    ::BeginMode2D(camera.getCStruct());
}

inline void Raylib::Camera2D::EndMode2D(void) const
{
    ::EndMode2D();
}

inline ::Matrix Raylib::Camera2D::getCameraMatrix2D(Raylib::Camera2D const &camera) const
{
    return ::GetCameraMatrix2D(camera.getCStruct());
}

inline ::Vector2 Raylib::Camera2D::getWorldToScreen2D(::Vector2 const &position, Raylib::Camera2D const &camera) const
{
    return ::GetWorldToScreen2D(position, camera.getCStruct());
}

inline ::Vector2 Raylib::Camera2D::getScreenToWorld2D(::Vector2 const &position, Raylib::Camera2D const &camera) const
{
    return ::GetScreenToWorld2D(position, camera.getCStruct());
}

inline Raylib::Camera2D &Raylib::Camera2D::operator=(const Camera2D &camera2D)
{
    set(camera2D);
    return *this;
}

inline void Raylib::Camera2D::set(const ::Camera2D &camera2D)
{
    _camera2D = camera2D;
}

inline void Raylib::Camera2D::set(const Camera2D &camera2D)
{
    _camera2D = camera2D._camera2D;
}
