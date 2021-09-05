/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Text
*/

inline void Raylib::Text::drawText(const std::string &title, const int &posX, const int &posY, const int &fontSize, const Raylib::Color &color)
{
    ::DrawText(title.c_str(), posX, posY, fontSize, color.getCStruct());
}

inline void Raylib::Text::drawTextEx(const std::string &font, const std::string &text, const std::pair<int, int> &position, const float &fontSize, const float &spacing, const Color &tint)
{
    ::Vector2 vec = {static_cast<float>(position.first), static_cast<float>(position.second)};
    ::Font loadedFont = ::LoadFont(font.c_str());

    ::SetTextureFilter(loadedFont.texture, TEXTURE_FILTER_BILINEAR);
    ::DrawTextEx(loadedFont, text.c_str(), vec, fontSize, spacing, tint.getCStruct());
}

inline int Raylib::Text::measureText(const std::string &text, const int &fontSize)
{
    return ::MeasureText(text.c_str(), fontSize);
}

inline bool Raylib::Text::textIsEqual(const std::string &text1, const std::string &text2)
{
    return ::TextIsEqual(text1.c_str(), text2.c_str());
}

inline int Raylib::Text::textLength(const std::string &text)
{
    return ::TextLength(text.c_str());
}