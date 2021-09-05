/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.inl
*/

inline Vector3 Raylib::Vector3::operator=(const Vector3 &copy) {
    x = copy.x;
    y = copy.y;
    z = copy.z;
    return *this;
}

inline Vector3 Raylib::Vector3::operator=(const ::Vector3 &cvec) {
    x = cvec.x;
    y = cvec.y;
    z = cvec.z;
    return *this;
}

inline ::Vector3 Raylib::Vector3::getCStruct(void) const {
    return ::Vector3({x, y, z});
}