/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.inl
*/

inline Vector2 Raylib::Vector2::operator=(const Vector2 &copyVector) {
    this->x = copyVector.x;
    this->y = copyVector.y;
    return *this;
}

inline Vector2 Raylib::Vector2::operator=(const ::Vector2 &copyVector) {
    this->x = copyVector.x;
    this->y = copyVector.y;
    return *this;
}

inline ::Vector2 Raylib::Vector2::getCStruct(void) const {
    return ::Vector2({this->x, this->y});
}