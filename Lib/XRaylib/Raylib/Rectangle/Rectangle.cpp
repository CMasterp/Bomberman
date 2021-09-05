/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Rectangle
*/

#include "Rectangle.hpp"
#include "Exception/Exception.hpp"

Raylib::Rectangle::Rectangle(float x, float y, float width, float height)
        : _rectangle({x, y, width, height})
{

}

Raylib::Rectangle::Rectangle(const Vector2 &position, const Vector2 &size)
        : _rectangle({position.x, position.y, size.x, size.y})
{

}

Raylib::Rectangle::Rectangle(const Vector2 &size)
        : _rectangle({0, 0, size.x, size.y})
{

}

Raylib::Rectangle::Rectangle(::Rectangle rec)
        : _rectangle(rec)
{

}

Raylib::Rectangle::~Rectangle()
{

}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try


int catchThrowTryRectangle() {
    try
    {   Raylib::Rectangle test;
        Raylib::Color color;
        auto grey = color.Gray();
        test.drawRectangle(1,1,1,1,grey);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydrawRectangleV() {
    try
    {   Raylib::Rectangle test;
        Vector2 position;
        Vector2 size;
        Raylib::Color color;
        auto grey = color.Gray();
        test.drawRectangleV(position, size,grey);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydrawRectanglePro() {
    try
    {   Raylib::Rectangle test;
        Raylib::Rectangle rec;
        Vector2 origin;
        float rotation = 1.0;
        Raylib::Color color;
        auto grey = color.Gray();
        test.drawRectanglePro(rec,origin,rotation,color);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}