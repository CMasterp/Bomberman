/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

inline void Raylib::Window::initWindow(const int &width, const int &height, const std::string &title)
{
    ::InitWindow(width, height, title.c_str());
}

inline bool Raylib::Window::windowShouldClose(void)
{
    return ::WindowShouldClose();
}

inline void Raylib::Window::closeWindow(void)
{
    ::CloseWindow();
}

inline void Raylib::Window::setWindowIcon(Raylib::Image image)
{
    ::SetWindowIcon(image.getCStruct());
}

inline bool Raylib::Window::isWindowFullscreen(void)
{
    return ::IsWindowFullscreen();
}
inline void Raylib::Window::toggleFullscreen()
{
    ::ToggleFullscreen();
}
