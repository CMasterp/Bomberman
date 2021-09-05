/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Music
*/

inline void Raylib::Music::unloadMusic(void) const
{
    ::UnloadMusicStream(_music);
}

inline Raylib::Music &Raylib::Music::playMusic(void)
{
    ::PlayMusicStream(_music);
    return *this;
}

inline Raylib::Music &Raylib::Music::update(void)
{
    ::UpdateMusicStream(_music);
    return *this;
}

inline Raylib::Music &Raylib::Music::stop(void)
{
    ::StopMusicStream(_music);
    return *this;
}

inline Raylib::Music &Raylib::Music::pause(void)
{
    ::PauseMusicStream(_music);
    return *this;
}

inline Raylib::Music &Raylib::Music::resume(void)
{
    ::ResumeMusicStream(_music);
    return *this;
}

inline bool Raylib::Music::isPlaying(void) const
{
    return ::IsMusicPlaying(_music);
}

inline Raylib::Music &Raylib::Music::setVolume(const float &volume)
{
    ::SetMusicVolume(_music, volume);
    return *this;
}

inline Raylib::Music &Raylib::Music::setPitch(const float &pitch)
{
    ::SetMusicPitch(_music, pitch);
    return *this;
}

inline float Raylib::Music::getTimeLength(void) const
{
    return ::GetMusicTimeLength(_music);
}

inline float Raylib::Music::getTimePlayed(void) const
{
    return ::GetMusicTimePlayed(_music);
}

inline void Raylib::Music::set(const ::Music &music)
{
    _music = music;
}

inline void Raylib::Music::set(const Music &music)
{
    _music = music._music;
}

inline Raylib::Music &Raylib::Music::operator=(const Music &music)
{
    set(music);
    return *this;
}