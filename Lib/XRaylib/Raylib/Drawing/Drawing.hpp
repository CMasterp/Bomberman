/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Drawing
*/

#ifndef DRAWING_HPP_
#define DRAWING_HPP_

#include "Color/Color.hpp"
#include "Vector3/Vector3.hpp"
#include "Texture/Texture.hpp"

namespace Raylib
{
    class Drawing {

    public:
        /**
         * @brief Construct a new Drawing object
         */
        Drawing();

        /**
         * @brief Destroy the Drawing object
         */
        ~Drawing();

        /**
         * @brief Set background color (framebuffer clear color)
         *
         * @param color A Color Object
         */
        static void clearBackground(const Color &color);

        /**
         * @brief Setup canvas (framebuffer) to start drawing
         */
        static void beginDrawing(void);

        /**
         * @brief End canvas drawing and swap buffers (double buffering)
         */
        static void endDrawing(void);

        /**
         * @brief Draw cube textured
         */
        static void drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured

        /**
         * @brief Draw sphere
         */
        static void drawSphere(Vector3 centerPos, float radius, Color color);
    };

#include "Drawing.inl"
}

#endif /* !DRAWING_HPP_ */
