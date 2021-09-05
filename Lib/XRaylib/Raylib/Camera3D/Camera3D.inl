/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera3D
*/

inline ::Camera3D Raylib::Camera3D::getCStruct(void) const
{
    return _camera3D;
}

inline Raylib::Camera3D &Raylib::Camera3D::operator=(const Raylib::Camera3D &camera)
{
    set(camera);
    return *this;
}

inline void Raylib::Camera3D::set(const ::Camera3D &camera)
{
    _camera3D = camera;
}

inline void Raylib::Camera3D::set(const Raylib::Camera3D &camera)
{
    _camera3D = camera._camera3D;
}

inline void Raylib::Camera3D::beginMode3D(void) const
{
    return ::BeginMode3D(_camera3D);
}

inline void Raylib::Camera3D::endMode3D(void) const
{
    return ::EndMode3D();
}

inline void Raylib::Camera3D::setCameraMode(int const &mode) const
{
    return ::SetCameraMode(_camera3D, mode);
}

inline void Raylib::Camera3D::updateCamera(void)
{
    return ::UpdateCamera(&_camera3D);
}

inline void Raylib::Camera3D::setPosition(const Vector3 &position)
{
    _camera3D.position = position.getCStruct();
}

inline void Raylib::Camera3D::setCameraPanControl(int const &keyPan) const
{
    return ::SetCameraPanControl(keyPan);
}

inline void Raylib::Camera3D::setCameraAltControl(int const &keyAlt) const
{
    return ::SetCameraAltControl(keyAlt);
}

inline void Raylib::Camera3D::setCameraSmoothZoomControl(int const &keySmoothZoom) const
{
    return ::SetCameraSmoothZoomControl(keySmoothZoom);
}

inline void Raylib::Camera3D::setCameraMoveControls(int const &frontKey, int const &backKey, int const &rightKey, int const &leftKey, int const &upKey, int const &downKey) const
{
    return ::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
}

inline Ray Raylib::Camera3D::getMouseRay(::Vector2 const &mousePosition) const
{
    return ::GetMouseRay(mousePosition, _camera3D);
}

inline Matrix Raylib::Camera3D::getCameraMatrix(void) const
{
    return ::GetCameraMatrix(_camera3D);
}

inline ::Vector2 Raylib::Camera3D::getWorldToScreen(Vector3 const &position) const
{
    return ::GetWorldToScreen(position.getCStruct(), _camera3D);
}

inline ::Vector2 Raylib::Camera3D::getWorldToScreenEx(Vector3 const &position, int const &width, int const &height) const
{
    return ::GetWorldToScreenEx(position.getCStruct(), _camera3D, width, height);
}

inline void Raylib::Camera3D::drawBillboard(Texture2D const &texture, Vector3 const &center, float const &size, Raylib::Color const &tint) const
{
    return ::DrawBillboard(_camera3D, texture, center.getCStruct(), size, tint.getCStruct());
}

inline void Raylib::Camera3D::drawBillboardRec(Texture2D const &texture,
                                               Raylib::Rectangle const &source, Vector3 const &center, const float &size, Raylib::Color const &tint) const
{
    return ::DrawBillboardRec(_camera3D, texture, source.getCStruct(), center.getCStruct(), size, tint.getCStruct());
}
