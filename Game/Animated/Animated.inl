/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Animated.inl
*/

inline Raylib::Vector3 Game::Animated::getPositions(void) const
{
    return _positions;
}

inline void Game::Animated::setPositions(Raylib::Vector3 &positions)
{
    _positions = positions;
}

inline void Game::Animated::drawEntity()
{
    float rad_rotation = (0 * PI) / 180;

    if (!_moving)
        _model.makeEmote();
    else
        _moving = false;

    _model.update();
    _model.getModel().transform = {
            0, 0, 1, 0,
            cosf(rad_rotation), sinf(rad_rotation), 0, 0,
            -sinf(rad_rotation), cosf(rad_rotation), 0, 0,
            0, 0, 0, 1
    };
    DrawModelEx(_model.getModel(), _positions.getCStruct(), {0, 0, 1}, _rotation, {_scalable, _scalable, _scalable}, _color.getCStruct());
}

inline void Game::Animated::setColor(const Raylib::Color &color)
{
    _color = color;
}

inline void Game::Animated::setColor(const std::string &color)
{
    if (color.compare("Blue") == 0
        || color.compare("Green") == 0
        || color.compare("Yellow") == 0
        || color.compare("Red") == 0) {
        std::map<std::string, Raylib::Color> colors = {
                {"Blue",   Raylib::Color::Blue()},
                {"Green",  Raylib::Color::Green()},
                {"Yellow", Raylib::Color::Yellow()},
                {"Red",    Raylib::Color::Red()}
        };
        setColor(colors[color]);
    }
}

inline void Game::Animated::setShouldDisplay(const bool &shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

inline bool Game::Animated::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

inline float Game::Animated::getScalable(void) const
{
    return _scalable;
}

inline void Game::Animated::setScalable(const float &scalable)
{
    _scalable = scalable;
}

inline void Game::Animated::setRotation(const float &rotation)
{
    _rotation = rotation;
}