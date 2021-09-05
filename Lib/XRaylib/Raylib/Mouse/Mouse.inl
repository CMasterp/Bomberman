/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Mouse
*/

inline bool Raylib::Mouse::isButtonPressed(const size_t &button)
{
    return ::IsMouseButtonPressed(button);
}

inline bool Raylib::Mouse::isButtonDown(const size_t &button)
{
    return ::IsMouseButtonDown(button);
}

inline bool Raylib::Mouse::isButtonReleased(const size_t &button)
{
    return ::IsMouseButtonReleased(button);
}

inline bool Raylib::Mouse::isButtonUp(const size_t &button)
{
    return ::IsMouseButtonUp(button);
}

inline size_t Raylib::Mouse::getMouseX(void)
{
    return ::GetMouseX();
}

inline size_t Raylib::Mouse::getMouseY(void)
{
    return ::GetMouseY();
}

inline void Raylib::Mouse::setMousePosition(const size_t &x, const size_t &y)
{
    ::SetMousePosition(x, y);
}

inline void Raylib::Mouse::setMouseOffset(const size_t &offsetX, const size_t &offsetY)
{
    ::SetMouseOffset(offsetX, offsetY);
}

inline void Raylib::Mouse::setMouseScale(const float &scaleX, const float &scaleY)
{
    ::SetMouseScale(scaleX, scaleY);
}

inline float Raylib::Mouse::getMouseWheelMove(void)
{
    return ::GetMouseWheelMove();
}

inline void Raylib::Mouse::setMouseCursor(const size_t &cursor)
{
    ::SetMouseCursor(cursor);
}

inline size_t Raylib::Mouse::getTouchX(void)
{
    return ::GetTouchX();
}

inline size_t Raylib::Mouse::getTouchY(void)
{
    return ::GetTouchY();
}