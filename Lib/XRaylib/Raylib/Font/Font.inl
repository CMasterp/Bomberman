/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Font
*/

inline void Raylib::Font::unload(void) const
{
    ::UnloadFont(_font);
}

inline Raylib::Font &Raylib::Font::operator=(const Font &font)
{
    set(font);
    return *this;
}

inline void Raylib::Font::set(const ::Font &font)
{
    _font = font;
}

inline void Raylib::Font::set(const Font &font)
{
    _font = font._font;
}

inline ::Font Raylib::Font::getCStruct(void) const
{
    return _font;
}