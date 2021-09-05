/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Gamepad
*/

inline bool Raylib::Gamepad::isGamepadAvailable(const int &gamepad)
{
    return ::IsGamepadAvailable(gamepad);
}

inline bool Raylib::Gamepad::isGamepadName(const int &gamepad, const std::string &name)
{
    return ::IsGamepadName(gamepad, name.c_str());
}

inline std::string Raylib::Gamepad::getGamepadName(const int &gamepad)
{
    return ::GetGamepadName(gamepad);
}

inline bool Raylib::Gamepad::isGamepadButtonPressed(const int &gamepad, const int &button)
{
    return ::IsGamepadButtonPressed(gamepad, button);
}

inline bool Raylib::Gamepad::isGamepadButtonDown(const int &gamepad, const int &button)
{
    return ::IsGamepadButtonDown(gamepad, button);
}

inline bool Raylib::Gamepad::isGamepadButtonReleased(const int &gamepad, const int &button)
{
    return ::IsGamepadButtonReleased(gamepad, button);
}

inline bool Raylib::Gamepad::isGamepadButtonUp(const int &gamepad, const int &button)
{
    return ::IsGamepadButtonUp(gamepad, button);
}

inline int Raylib::Gamepad::getGamepadButtonPressed(void)
{
    return ::GetGamepadButtonPressed();
}

inline int Raylib::Gamepad::getGamepadAxisCount(const int &gamepad)
{
    return ::GetGamepadAxisCount(gamepad);
}

inline float Raylib::Gamepad::getGamepadAxisMovement(const int &gamepad, const int &axis)
{
    return ::GetGamepadAxisMovement(gamepad, axis);
}

inline int Raylib::Gamepad::setGamepadMappings(const std::string &mappings)
{
    return ::SetGamepadMappings(mappings.c_str());
}