/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Sound {

    public:
        /**
         * @brief Construct a new Sound object
         */
        Sound();

        /**
         * @brief Destroy the Sound object
         */
        ~Sound();

        /**
         * @brief Construct a new Sound object
         *
         * @param vec A Sound Object
         */
        Sound(const Sound &vec);

        /**
         * @brief Construct a new Sound object
         *
         * @param fileName A string path to sound
         */
        Sound(const std::string &fileName);

        /**
         * @brief Update sound buffer with new data, assuming it's the same sample count.
         *
         * @param data A const pointer
         * @return A reference to a Sound object
         */
        Sound &update(const void *data);

        /**
         * @brief Unload sound
         *
         * @return A reference to a Sound object
         */
        void unload(void) const;

        /**
         * @brief Play a sound
         *
         * @return A reference to a Sound object
         */
        Sound &play(void);

        /**
         * @brief Stop playing a sound
         *
         * @return A reference to a Sound object
         */
        Sound &stop(void);

        /**
         * @brief Pause a sound
         *
         * @return A reference to a Sound object
         */
        Sound &pause(void);

        /**
         * @brief Resume a paused sound
         *
         * @return A reference to a Sound object
         */
        Sound &resume(void);

        /**
         * @brief Check if a sound is currently playing
         *
         * @return A boolean
         */
        bool isPlaying(void) const;

        /**
         * @brief Set volume for a sound (1.0 is max level)
         *
         * @param volume A float
         * @return A reference to a Sound object
         */
        Sound &setVolume(const float &volume);

        /**
         * @brief Set pitch for a sound (1.0 is base level)
         *
         * @param pitch A float
         * @return A reference to a Sound object
         */
        Sound &setPitch(const float &pitch);

        /**
         * @brief Overload of '=' operator
         *
         * @param sound A const reference to a Sound
         * @return A reference to Sound (Sound &)
         */
        Sound &operator=(const Sound &sound);

    private:
        /**
         * @brief Set Sound
         *
         * @param sound A Sound C Structure
         */
        void set(const ::Sound &sound);

        /**
         * @brief Set Sound
         *
         * @param sound A const reference to a Sound object
         */
        void set(const Sound &sound);

        ::Sound _sound; // Sound C structure
    };

#include "Sound.inl"
}

#endif /* !SOUND_HPP_ */
