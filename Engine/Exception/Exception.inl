/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Exception.inl
*/

inline const std::string &Engine::Exception::getFile(void) const
{
    return _file;
}

inline size_t Engine::Exception::getLine(void) const
{
    return _line;
}

inline const std::string &Engine::Exception::getFunction(void) const
{
    return _function;
}

inline const std::string &Engine::Exception::getInfo(void) const
{
    return _info;
}