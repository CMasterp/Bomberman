/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Powerups.hpp
*/

#ifndef POWERUPS_HPP_
#define POWERUPS_HPP_

#include "Animated/Animated.hpp"
#include "Player/Player.hpp"

namespace Game
{
    class Powerups : public Animated
    {
    public:
        Powerups(const Raylib::Vector3 &position, const std::string &type);
        ~Powerups();

        virtual void applyPowerupTo(Game::Player &player) = 0;
        std::string getType() const override;

    private:

    };

    class Life : public Powerups
    {
    public:
        Life(const Raylib::Vector3 &position);
        ~Life();

        void applyPowerupTo(Game::Player &player) override;

    private:

    };

    class Pass : public Powerups
    {
    public:
        Pass(const Raylib::Vector3 &position);
        ~Pass();

        void applyPowerupTo(Game::Player &player) override;

    private:

    };

    class Fire : public Powerups
    {
    public:
        Fire(const Raylib::Vector3 &position);
        ~Fire();

        void applyPowerupTo(Game::Player &player) override;

    private:

    };

    class BombUp : public Powerups
    {
    public:
        BombUp(const Raylib::Vector3 &position);
        ~BombUp();

        void applyPowerupTo(Game::Player &player) override;

    private:

    };

    class Speed : public Powerups
    {
    public:
        Speed(const Raylib::Vector3 &position);
        ~Speed();

        void applyPowerupTo(Game::Player &player) override;

    private:

    };

#include "Powerups.inl"
}

#endif