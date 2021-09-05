/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Timing
*/

inline void Raylib::Timing::setTargetFPS(const int &fps)
{
    ::SetTargetFPS(fps);
}

inline int Raylib::Timing::getFPS(void)
{
    return ::GetFPS();
}

inline float Raylib::Timing::getFrameTime(void)
{
    return ::GetFrameTime();
}

inline double Raylib::Timing::getTime(void)
{
    return ::GetTime();
}
