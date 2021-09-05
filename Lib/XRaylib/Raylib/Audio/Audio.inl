/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Audio
*/

inline void Raylib::Audio::initAudioDevice(void) {
    ::InitAudioDevice();
}

inline void Raylib::Audio::closeAudioDevice(void) {
    ::CloseAudioDevice();
}

inline bool Raylib::Audio::isAudioDeviceReady(void) {
    return ::IsAudioDeviceReady();
}

inline void Raylib::Audio::setMasterVolume(float volume) {
    ::SetMasterVolume(volume);
}
