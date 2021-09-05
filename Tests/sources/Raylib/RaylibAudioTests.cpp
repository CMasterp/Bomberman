/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RaylibAudioTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Audio/Audio.hpp"

TEST(AudioTest, initAudioDeviceTest1)
{
    try {
        Raylib::Audio test;
        test.initAudioDevice();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid audio settings", ex.what());
    }
}

TEST(AudioTest, initAudioDeviceTest2)
{
    try {
        Raylib::Audio test;
        test.closeAudioDevice();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid audio settings", ex.what());
    }
}

TEST(AudioTest, isAudioDeviceReady)
{
    Raylib::Audio test;

    auto res = test.isAudioDeviceReady();

    EXPECT_EQ(false,res);
}

TEST(AudioTest, setMasterVolume1)
{
    try {
        Raylib::Audio test;
        test.setMasterVolume(1.0);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid volume parameters", ex.what());
    }
}