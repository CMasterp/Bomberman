/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib {
    class Audio {
        /// Audio device management functions
    public:
        /**
         * @brief Construct a new Audio object
         */
        Audio();

        /**
         * @brief Destroy the Audio object
         */
        ~Audio();

        /**
         * @brief Initialize audio device and context
         */
        static void initAudioDevice(void);

        /**
         * @brief close the audio device and context
         */
        static void closeAudioDevice(void);

        /**
         * @brief Check if audio device has been initialized successfully
         *
         * @return true when succesfull, false otherwise
         */
        static bool isAudioDeviceReady(void);

        /**
         * @brief Set master volume (listener)
         *
         * @param volume
         */
        static void setMasterVolume(float volume);

    };

#include "Audio.inl"

}

#endif /* !AUDIO_HPP_ */
