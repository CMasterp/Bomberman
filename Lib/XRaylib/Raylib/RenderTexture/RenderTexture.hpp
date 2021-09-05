/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** RenderTexture
*/

#ifndef RENDERTEXTURE_HPP_
#define RENDERTEXTURE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib {

    class RenderTexture {

    public:
        /**
         * @brief Construct a new RenderTexture object
         */
        RenderTexture();

        /**
         * @brief Construct a new RenderTexture object
         */
        ~RenderTexture();

        /**
         * @brief Overload of '=' operator
         *
         * @param music A const reference to a RenderTexture
         * @return A reference to RenderTexture (Texture &)
         */
        RenderTexture &operator=(const RenderTexture &rendertexture);

        /**
         * @brief Getter of RenderTexture structure (private attribute)
         *
         * @return An RenderTexture C structure
         */
        ::RenderTexture getCStruct(void) const;

        /**
        * @brief Initializes render texture for drawing
        *
        * @param target A const reference to Class RenderTexture
        */
        void BeginTextureMode(RenderTexture target) const;

        /**
        * @brief Ends drawing to render texture
        */
        void EndTextureMode(void) const;

        /**
        * @brief Load texture for rendering (framebuffer)
        *
        * @param width A const reference to an int
        * @param height A const reference to an int
        * @return A RenderTexture
        */
        RenderTexture loadRenderTexture(int const &width, int const &height);

        /**
        * @brief Unload render texture from GPU memory (VRAM)
        *
        * @param target A const reference to a RenderTexture
        */
        void unloadRenderTexture(RenderTexture const &target) const;

    private:
        /**
         * @brief Set RenderTexture
         *
         * @param texture A RenderTexture C Structure
         */
        void set(const ::RenderTexture &rendertexture);

        /**
         * @brief Set Texture
         *
         * @param texture A const reference to a RenderTexture object
         */
        void set(const RenderTexture &rendertexture);

        ::RenderTexture _rendertexture; // RenderTexture C structure
    };

#include "RenderTexture.inl"

}

#endif /* !RENDERTEXTURE_HPP_ */
