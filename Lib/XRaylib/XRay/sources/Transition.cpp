/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Transition
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

void XRay::updateTransitionManager(Scene toFadeOut, Scene toFadeIn)
{
    _transitionManager[toFadeOut].first = false;
    _transitionManager[toFadeOut].second = true;
    _transitionManager[toFadeIn].first = true;
    _transitionManager[toFadeIn].second = false;
}

void XRay::fadeThisScene(Scene toFade)
{
    static float transAlpha = 0.0f;

    if (_transitionManager[toFade].first) {
        Raylib::Rectangle::drawRectangle(0, 0, 1920, 1080, Raylib::Color::fade(Raylib::Color::Black(), transAlpha));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        transAlpha -= 0.02f;
        if (transAlpha < -0.01f) {
            _transitionManager[toFade].first = false;
            transAlpha = 0.0f;
        }
    } else if (_transitionManager[toFade].second) {
        Raylib::Rectangle::drawRectangle(0, 0, 1920, 1080, Raylib::Color::fade(Raylib::Color::Black(), transAlpha));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        transAlpha += 0.02f;
        if (transAlpha > 1.01f) {
            _transitionManager[toFade].second = false;
            transAlpha = 1.0f;
        }
    }
}

int catchThrowTryupdateTransitionManager() {
    try
    {   XRay test;
        IGraphical::Scene toFadeOut;
        IGraphical::Scene toFadeIn;
        test.updateTransitionManager(toFadeOut, toFadeIn);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
