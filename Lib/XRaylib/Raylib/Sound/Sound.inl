/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Sound
*/

inline void Raylib::Sound::unload(void) const
{
    ::UnloadSound(_sound);
}

inline Raylib::Sound &Raylib::Sound::play(void)
{
    ::PlaySound(_sound);
    return *this;
}

inline Raylib::Sound &Raylib::Sound::update(const void *data)
{
    ::UpdateSound(_sound, data, _sound.sampleCount);
    return *this;
}

inline Raylib::Sound &Raylib::Sound::stop(void)
{
    ::StopSound(_sound);
    return *this;
}

inline Raylib::Sound &Raylib::Sound::pause(void)
{
    ::PauseSound(_sound);
    return *this;
}

inline Raylib::Sound &Raylib::Sound::resume(void)
{
    ::ResumeSound(_sound);
    return *this;
}

inline bool Raylib::Sound::isPlaying(void) const
{
    return ::IsSoundPlaying(_sound);
}

inline Raylib::Sound &Raylib::Sound::setVolume(const float &volume)
{
    ::SetSoundVolume(_sound, volume);
    return *this;
}

inline Raylib::Sound &Raylib::Sound::setPitch(const float &pitch)
{
    ::SetSoundPitch(_sound, pitch);
    return *this;
}

inline void Raylib::Sound::set(const ::Sound &sound)
{
    _sound = sound;
}

inline void Raylib::Sound::set(const Sound &sound)
{
    _sound = sound._sound;
}

inline Raylib::Sound &Raylib::Sound::operator=(const Sound &sound)
{
    set(sound);
    return *this;
}