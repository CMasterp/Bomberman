/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Exception.hpp
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include <iostream>
#include <exception>
#include <cassert>
#include <assert.h>
#include <string>

namespace Engine
{
    class Exception : public std::exception
    {
        public:
            /**
             * @brief Detect if a certain functions hits and exception
             *
             * @param msg The error message
             * @param file The file containing the error
             * @param line The line containing the error
             * @param func The function containing the error
             * @param info The error informations
             */
            Exception(const std::string &msg, const std::string &file, const size_t &line, const std::string &function, const std::string &info);

            /**
            * @brief Get the file
            */
            const std::string &getFile(void) const;

            /**
             * @brief Get the line
             */
            size_t getLine(void) const;

            /**
             * @brief Get the function
             */
            const std::string &getFunction(void) const;

            /**
             * @brief Get the type of exceptions
             */
            const std::string &getInfo(void) const;

            // All the functions that test here in static with comments
            // XRAY
            static int catchThrowTrydisplayStudio();
            static int catchThrowTrydisplayTeamPresentation();
            static int catchThrowTryplayMusic();
            static int catchThrowTryplayAndUpdateMusic();
            static int catchThrowTrygoToAnotherSceneFromVictory();
            static int catchThrowTrydisplayVictoryScene();
            static int catchThrowTryupdateTransitionManager();
            static int catchThrowTrydisplaySettingsScene();
            static int catchThrowTrychangeMusicVolume();
            static int catchThrowTrychangeSfxVolume();
            static int catchThrowTrydetectPlayerInput();
            static int catchThrowTryremovePlayer();
            static int catchThrowTryaddPlayer();
            static int catchThrowTrymanageNextOrPrev();
            static int catchThrowTrydisplayCardsSettings();
            static int catchThrowTrydisplayBack();
            static int catchThrowTrydisplayPlayerChoiceScene();
            static int catchThrowTryshouldGoToEast();
            static int catchThrowTryshouldGoToWest();
            static int catchThrowTryshouldGoToNorth();
            static int catchThrowTryshouldGoToSouth();
            static int catchThrowTryshouldChangeToPrev();
            static int catchThrowTryshouldChangeToNext();
            static int catchThrowTryshouldSimulateAClick();
            static int catchThrowTryupdate();
            static int catchThrowTrymakeWalk();
            static int catchThrowTrymakeBomb();
            static int catchThrowTrymakeEmote();
            static int catchThrowTrydisplayMenuScene();
            static int catchThrowTrydisplayGameSettings();
            static int catchThrowTrycheckClickOnMapChoiceScene();
            static int catchThrowTrydisplayMapChoiceScene();
            static int catchThrowTryloadThisBackup();
            static int catchThrowTrydisplayLoadGameScene();
            static int catchThrowTryKeyboardException();
            static int catchThrowTryupdateGamepad();
            static int catchThrowTrygetTimeInFormat();
            static int catchThrowTrydrawPlayersHead();
            static int catchThrowTrydisplayPlayersPanels();
            static int catchThrowTrydisplayPauseScene();
            static int catchThrowTrydgoToAnotherScene();
            static int catchThrowTrymanagePlayersActions();
            static int catchThrowTrydisplayInGameScene();
            static int catchThrowTrydisplayHowToPlayScene();
            static int catchThrowTryGamepadException();
            static int catchThrowTrygoToAnotherSceneFromDefeat();
            static int catchThrowTrydisplayDefeatScenet();
            static int catchThrowTrydoesTimeElapsed();
            static int catchThrowTrygetElapsedTime();
            static int catchThrowTrydisplayCinematic();

            // RAYLIB_SRCS
            static int catchThrowTrywindowShouldClose();
            static int catchThrowTrycloseWindow();
            static int catchThrowTrysetWindowIcon();
            static int catchThrowTryisWindowFullscreen();
            static int catchThrowTrytoggleFullscreen();
            static int catchThrowTrysetTargetFPS();
            static int catchThrowTrygetFPSS();
            static int catchThrowTrygetFrameTime();
            static int catchThrowTrygetTime();
            static int catchThrowTrydrawText();
            static int catchThrowTrymeasureText();
            static int catchThrowTrytextIsEqual();
            static int catchThrowTrytextLength();
            static int catchThrowTryRectangle();
            static int catchThrowTrydrawRectangleV();
            static int catchThrowTrydrawRectanglePro();
            static int catchThrowTryunloadMusic();
            static int catchThrowTryisButtonPressed();
            static int catchThrowTryisButtonDown();
            static int catchThrowTryisButtonReleased();
            static int catchThrowTryisButtonUp();
            static int catchThrowTrygetMouseX();
            static int catchThrowTrygetMouseY();
            static int catchThrowTryisKeyPressed();
            static int catchThrowTryisKeyDown();
            static int catchThrowTryisKeyReleased();
            static int catchThrowTryisKeyUp();
            static int catchThrowTrygetKeyPressed();
            static int catchThrowTrygetCharPressed();

        private:
            /// This stores the file name
            std::string _file;
            /// This stores the actual line
            size_t _line;
            /// This stores the function
            std::string _function;
            /// This stores the exception info
            std::string _info;
        };

    #include "Exception.inl"
} // namespace Engine

#endif /* !MYEXCEPTION_HPP_ */
