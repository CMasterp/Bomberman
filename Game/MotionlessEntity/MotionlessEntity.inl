/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

inline Raylib::Vector3 Game::MotionlessEntity::getPositions(void) const
{
    return _positions;
}

inline void Game::MotionlessEntity::setPositions(Raylib::Vector3 &vector)
{
    _positions = vector;
}

inline void Game::MotionlessEntity::setShouldDisplay(const bool &shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

inline bool Game::MotionlessEntity::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

inline void Game::SolidWall::drawEntity()
{
    Raylib::Drawing::drawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), _width, _height, _length, Raylib::Color::White());
}

inline void Game::BreakableWall::drawEntity()
{
    Raylib::Drawing::drawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), _width, _height, _length, Raylib::Color::White());
}

inline void Game::Floor::drawEntity()
{
    Raylib::Drawing::drawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), _width, _height, _length, Raylib::Color::White());
}

inline std::string Game::SolidWall::getType() const
{
    return ("SolidWall");
}

inline std::string Game::BreakableWall::getType() const
{
    return ("BreakableWall");
}

inline std::string Game::Floor::getType() const
{
    return ("Floor");
}