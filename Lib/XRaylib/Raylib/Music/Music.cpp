/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Music
*/

#include "Music.hpp"
#include "Exception/Exception.hpp"

Raylib::Music::Music()
{
}

Raylib::Music::Music(const Music &music)
{
    set(music);
}

Raylib::Music::Music(const std::string &fileName)
{
    _music = ::LoadMusicStream(fileName.c_str());
}

Raylib::Music::Music(const std::string &fileType, const std::string &data, const int &dataSize)
{
    _music = ::LoadMusicStreamFromMemory(fileType.c_str(), (unsigned char *)data.c_str(), dataSize);
}

Raylib::Music::~Music()
{
    ::UnloadMusicStream(_music);
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try


int catchThrowTryunloadMusic() {
    try
    {   Raylib::Music test;
        test.unloadMusic();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}