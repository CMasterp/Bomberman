/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.inl
*/

inline Vector4 Raylib::Vector4::operator=(const Vector4 &copy)
{
    x = copy.x;
    y = copy.y;
    z = copy.z;
    w = copy.w;
    return *this;
}

inline Vector4 Raylib::Vector4::operator=(const ::Vector4 &cvec)
{
    x = cvec.x;
    y = cvec.y;
    z = cvec.z;
    w = cvec.w;
    return *this;
}

inline ::Vector4 Raylib::Vector4::getCStruct() const
{
    return ::Vector4({x, y, z, w});
}