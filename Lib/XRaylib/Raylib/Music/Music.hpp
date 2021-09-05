/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Music {

    public:
        /**
         * @brief Construct a new Music object
         */
        Music();

        /**
         * @brief Construct a new Music object
         *
         * @param music A Music object
         */
        Music(const Music &music);

        /**
         * @brief Load music stream from file
         *
         * @param fileName A string path to music
         */
        Music(const std::string &fileName);

        /**
         * @brief Load music stream from memory
         *
         * @param fileType A string
         * @param data A string
         * @param dataSize An int
         */
        Music(const std::string &fileType, const std::string &data, const int &dataSize);

        /**
         * @brief Destroy the Music object
         */
        ~Music();

        /**
         * @brief Unload music stream
         */
        void unloadMusic(void) const;

        /**
         * @brief Start music playing
         *
         * @return A reference to a Music object
         */
        Music &playMusic(void);

        /**
         * @brief Updates buffers for music streaming
         *
         * @return A reference to a Music object
         */
        Music &update(void);

        /**
         * @brief Stop music playing
         *
         * @return A reference to a Music object
         */
        Music &stop(void);

        /**
         * @brief Pause music playing
         *
         * @return A reference to a Music object
         */
        Music &pause(void);

        /**
         * @brief Resume music playing
         *
         * @return A reference to a Music object
         */
        Music &resume(void);

        /**
         * @brief Check if music is playing
         *
         * @return A reference to a Music object
         */
        bool isPlaying(void) const;

        /**
         * @brief Set volume for music
         *
         * @return A reference to a Music object
         */
        Music &setVolume(const float &volume);

        /**
         * @brief Set pitch for music
         *
         * @return A reference to a Music object
         */
        Music &setPitch(const float &pitch);

        /**
         * @brief Get music time length (in seconds)
         *
         * @return A float
         */
        float getTimeLength(void) const;

        /**
         * @brief Get current music time played (in seconds)
         *
         * @return A float
         */
        float getTimePlayed(void) const;

        /**
         * @brief Overload of '=' operator
         *
         * @param music A const reference to a Music
         * @return A reference to Music (Music &)
         */
        Music &operator=(const Music &music);

    private:
        /**
         * @brief Set Music
         *
         * @param music A Music C Structure
         */
        void set(const ::Music &music);

        /**
         * @brief Set Music
         *
         * @param music A const reference to a Music object
         */
        void set(const Music &music);

        ::Music _music; // Music C structure
    };

#include "Music.inl"
}

#endif /* !MUSIC_HPP_ */
