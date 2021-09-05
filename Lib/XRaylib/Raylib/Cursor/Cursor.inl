/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cursor
*/

inline void Raylib::Cursor::showCursor(void)
{
    ::ShowCursor();
}

inline void Raylib::Cursor::hideCursor(void)
{
    ::HideCursor();
}

inline bool Raylib::Cursor::isCursorHidden(void)
{
    return ::IsCursorHidden();
}

inline void Raylib::Cursor::enableCursor(void)
{
    ::EnableCursor();
}

inline void Raylib::Cursor::disableCursor(void)
{
    ::DisableCursor();
}

inline bool Raylib::Cursor::isCursorOnScreen(void)
{
    return ::IsCursorOnScreen();
}
