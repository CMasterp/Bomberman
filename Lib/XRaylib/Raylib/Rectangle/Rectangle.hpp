/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Color/Color.hpp"
#include "Image/Image.hpp"
#include "Vector2/Vector2.hpp"

namespace Raylib {
    class Rectangle {

    public:
        /**
         * @brief Construct a new Rectangle object with parameters
         *
         * @param x Position X
         * @param y Position Y
         * @param width The width of the rectangle
         * @param height The height of the rectangle
         */
        Rectangle(float x = 0, float y = 0, float width = 0, float height = 0);

        /**
         * @brief Construct a new Rectangle object
         *
         * @param rec C Rectangle structure
         */
        Rectangle(::Rectangle rec);

        /**
         * @brief Construct a new Rectangle object with parameters
         *
         * @param position An const reference to the Vector2
         * @param size An const reference to the Vector2
         */
        Rectangle(Vector2 const &position, Vector2 const &size);

        /**
         * @brief Construct a new Rectangle object with parameters
         *
         * @param size An const reference to the Vector2
         */
        Rectangle(Vector2 const &size);

        /**
         * @brief Overload of '=' operator
         *
         * @param rectangle A const reference to a Rectangle
         * @return A reference to Rectangle (Rectangle &)
         */
        Rectangle &operator=(const Rectangle &rectangle);

        /**
         * @brief Destroy the Rectangle object
         */
        ~Rectangle();

        /**
         * @brief Getter of Texture structure (private attribute)
         *
         * @return  An Rectangle C structure
         */
        ::Rectangle getCStruct(void) const;

        /**
         * @brief Draw a color-filled rectangle
         *
         * @param posX A const reference to an int
         * @param posY A const reference to an int
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param color A const reference to Class Color
         */
        static void drawRectangle(int const &posX, int const &posY, int const &width,
                                  int const &height, Color const &color);

        /**
         * @brief Draw a color-filled rectangle (Vector version)
         *
         * @param position A const reference to a Class Vector2
         * @param size A const reference to a Class Vector2
         * @param color A const reference to Class Color
         */
        void drawRectangleV(const Vector2 &position, const Vector2 &size,
                            const Color &color) const;

        /**
         * @brief Draw a color-filled rectangle
         *
         * @param rec A const reference to a Class Rectangle
         * @param color A const reference to Class Color
         */
        static void drawRectangleRec(Rectangle const &rec, Color const &color);

        /**
         * @brief Draw a color-filled rectangle with pro parameters
         *
         * @param rec A const reference to a Class Rectangle
         * @param orgin A const reference to a Class Vector2
         * @param rotation A const reference to a float
         * @param color A const reference to Class Color
         */
        void drawRectanglePro(Rectangle const &rec, Vector2 const &origin,
                              float const &rotation, Color const &color) const;

        /**
         * @brief Draw a vertical-gradient-filled rectangle
         *
         * @param posX A const reference to an int
         * @param posY A const reference to an int
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param col1 A const reference to Class Color
         * @param col2 A const reference to Class Color
         */
        void drawRectangleGradientV(int const &posX, int const &posY,
                                    int const &width, int const &height,
                                    Color const &color1,
                                    Color const &color2) const;

        /**
         * @brief Draw a horizontal-gradient-filled rectangle
         *
         * @param posX A const reference to an int
         * @param posY A const reference to an int
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param col1 A const reference to Class Color
         * @param col2 A const reference to Class Color
         */
        void drawRectangleGradientH(int const &posX, int const &posY,
                                    int const &width, int const &height,
                                    Color const &color1,
                                    Color const &color2) const;

        /**
         * @brief Draw a gradient-filled rectangle with custom vertex colors
         *
         * @param rec A const reference to a Class Rectangle
         * @param col1 A const reference to Class Color
         * @param col2 A const reference to Class Color
         * @param col3 A const reference to Class Color
         * @param col4 A const reference to Class Color
         */
        void drawRectangleGradientEx(Rectangle const &rec, Color const &col1,
                                     Color const &col2, Color const &col3,
                                     Color const &col4) const;

        /**
         * @brief Draw rectangle outline
         *
         * @param posX A const reference to an int
         * @param posY A const reference to an int
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param color A const reference to Class Color
         */
        static void drawRectangleLines(int const &posX, int const &posY, int const &width,
                                       int const &height, Color const &color);

        /**
         * @brief Draw rectangle outline with extended parameters
         *
         * @param rec A const reference to Class Rectangle
         * @param lineThick A const reference to an int
         * @param color A const reference to Class Color
         */
        void drawRectangleLinesEx(Rectangle const &rec, int const &lineThick,
                                  Color const &color) const;

        /**
         * @brief Draw rectangle with rounded edges
         *
         * @param rec A const reference to Class Rectangle
         * @param roundness A const reference to a float
         * @param segments A const reference to an int
         * @param color A const reference to Class Color
         */
        void drawRectangleRounded(Rectangle const &rec, float const &roundness,
                                  int const &segments,
                                  Color const &color) const;

        /**
         * @brief Draw rectangle with rounded edges outline
         *
         * @param rec A const reference to Class Rectangle
         * @param roundness A const reference to a float
         * @param segments A const reference to an int
         * @param lineThick A const reference to an int
         * @param color A const reference to Class Color
         */
        void
        drawRectangleRoundedLines(Rectangle const &rec, float const &roundness,
                                  int const &segments, int const &lineThick,
                                  Color const &color) const;

    private:
        /**
         * @brief Set Rectangle
         *
         * @param Rectangle A Rectangle C Structure
         */
        void set(const ::Rectangle &texture);

        /**
         * @brief Set Rectangle
         *
         * @param Rectangle A const reference to a Rectangle object
         */
        void set(const Rectangle &texture);

        ::Rectangle _rectangle; // Rectangle C structure
    };

#include "Rectangle.inl"

}

#endif /* !RECTANGLE_HPP_ */
