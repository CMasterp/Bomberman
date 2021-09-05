/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Color/Color.hpp"
#include "RenderTexture/RenderTexture.hpp"
#include "Vector2/Vector2.hpp"
#include "Rectangle/Rectangle.hpp"
#include "Image/Image.hpp"

namespace Raylib
{
    class Texture {

    public:
        /**
         * @brief Construct a new Texture object
         */
        Texture(const std::string &fileName);

        /**
         * @brief Construct a new Texture object
         */
        Texture(const Texture &texture) = default;

        /**
         * @brief Construct a new Texture object
         */
        Texture(const Image &texture);

        /**
         * @brief Destroy the Texture object
         */
        ~Texture();

        /**
         * @brief Overload of '=' operator
         *
         * @param texture A const reference to a Texture
         * @return A reference to Texture (Texture &)
         */
        Texture &operator=(const Texture &texture);

        /**
         * @brief Getter of Texture structure (private attribute)
         *
         * @return An Texture C structure
         */
        ::Texture getCStruct(void) const;

        /**
         * @brief Set texture and rectangle to be used on shapes drawing
         *
         * @param texture A Texture Object
         * @param source A Rectangle Object
         */
        void setShapesTexture(const Texture &texture, const Rectangle &source);

        /**
         * @brief Load texture from file into GPU memory (VRAM)
         *
         * @param fileName A string that represents path to file
         * @return A reference to the texture - Texture&
         */
        Texture &loadTexture(const std::string fileName);

        /**
         * @brief Load texture from image data
         *
         * @param image A const reference to the Image Object
         * @return A reference to the texture - Texture&
         */
        Texture &loadTextureFromImage(Image const &image);

        /**
         * @brief Initializes render texture for drawing
         *
         * @param target A const reference to the RenderTexture Object
         */
        void beginTextureMode(RenderTexture const &target) const;

        /**
         * @brief Ends drawing to render texture
         */
        void endTextureMode(void) const;

        /**
         * @brief Load cubemap from image, multiple image cubemap layouts supported
         *
         * @param image A const reference to the Image Object
         * @param layout A const reference to an int
         * @param texture A const reference to the Texture Object
         * @return A Texture
         */
        Texture loadTextureCubemap(Image const &image, int const &layout);

        /**
        * @brief Unload texture from GPU memory (VRAM)
        *
        * @param texture A const reference to a Texture
        */
        void unloadTexture(Texture const &texture) const;

        /**
        * @brief Update GPU texture with new data
        *
        * @param texture A const reference to a Texture
        * @param pixels A const to a void *
        */
        void updateTexture(Texture const &texture, const void *pixels) const;

        /**
        * @brief Update GPU texture rectangle with new data
        *
        * @param texture A const reference to a Texture
        */
        void updateTextureRec(Texture const &texture, Rectangle const &rec, const void *pixels) const;

        /**
        * @brief Generate GPU mipmaps for a texture
        *
        * @param texture A const pointer to a Texture
        */
        void genTextureMipmaps(Texture const *texture) const;

        /**
        * @brief Set texture scaling filter mode
        *
        * @return An Image Class
        */
        void setTextureFilter(Texture const &texture, int const &filter) const;

        /**
        * @brief Set texture wrapping mode
        *
        * @param texture A const pointer to a Texture
        * @param wrap A const reference to an int
        */
        void setTextureWrap(Texture const &texture, int const &wrap) const;

        /**
         * @brief Draw a Texture with position XY
         *
         * @param posX An int
         * @param posY An int
         * @param tint A Color
         * @return A reference to the texture - Texture&
         */
        void drawTexture(const int &posX, const int &posY, const Color &tint) const;

        /**
         * @brief Draw a Texture with position defined as Vector2
         *
         * @param texture A const pointer to a Texture
         * @param position A const reference to a Vector2
         * @param tint A const reference to a Color
         */
        void drawTextureV(Texture const &texture, Vector2 const &position, Color const &tint = Color::White()) const;

        /**
         * @brief Draw a Texture with extended parameters
         *
         * @param texture A const pointer to a Texture
         * @param position A const reference to a Vector2
         * @param rotation A const reference to a float
         * @param scale A const reference to a float
         * @param tint A const reference to a Color
         */
        void drawTexture(const float &posX, const float &posY, float const &rotation, float const &scale, Color const &tint = Color::White()) const;

        /**
         * @brief Draw a part of a texture defined by a rectangle
         *
         * @param texture A const pointer to a Texture
         * @param position A const reference to a Vector2
         * @param rotation A const reference to a float
         * @param scale A const reference to a float
         * @param tint A const reference to a Color
         */
        void drawTextureRec(Texture const &texture, Rectangle const &source, Vector2 const &position, Color const &tint) const;

        /**
         * @brief Draw texture quad with tiling and offset parameters
         *
         * @param texture A const pointer to a Texture
         * @param tiling A const reference to a Vector2
         * @param offset A const reference to a Vector2
         * @param quad A const reference to a Rectangle
         * @param tint A const reference to a Color
         */
        void drawTextureQuad(Texture const &texture, Vector2 const &tiling, Vector2 const &offset, Rectangle const &quad, Color const &tint) const;

        /**
         * @brief Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
         *
         * @param texture A const pointer to a Texture
         * @param source A const reference to a Rectangle
         * @param dest A const reference to a Rectangle
         * @param origin A const reference to a Vector2
         * @param rotation A const reference to a float
         * @param scale A const reference to a float
         * @param tint A const reference to a Color
         */
        void drawTextureTiled(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, float const &scale, Color const &tint) const;

        /**
         * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
         *
         * @param texture A const pointer to a Texture
         * @param tiling A const reference to a Vector2
         * @param offset A const reference to a Vector2
         * @param quad A const reference to a Rectangle
         * @param tint A const reference to a Color
         * @return A reference to the texture - Texture&
         */
        void drawTexturePro(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint) const;

        /**
         * @brief Draws a texture (or part of it) that stretches or shrinks nicely
         *
         * @param texture A const pointer to a Texture
         * @param tiling A const reference to a Vector2
         * @param offset A const reference to a Vector2
         * @param quad A const reference to a Rectangle
         * @param tint A const reference to a Color
         * @return A reference to the texture - Texture&
         */
        void drawTextureNPatch(Texture const &texture, NPatchInfo const &nPatchInfo, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint) const;

        /**
         * @brief Draw a textured polygon
         *
         * @param texture A const pointer to a Texture
         * @param tiling A const reference to a Vector2
         * @param offset A const reference to a Vector2
         * @param quad A const reference to a Rectangle
         * @param tint A const reference to a Color
         * @return A reference to the texture - Texture&
         */
        void drawTexturePoly(const Texture &texture, const Vector2 &center, Vector2 &points, Vector2 &texcoords, const int &pointsCount, const Color &tint) const;

    private:
        /**
         * @brief Set Texture
         *
         * @param texture A Texture C Structure
         */
        void set(const ::Texture &texture);

        /**
         * @brief Set Texture
         *
         * @param texture A const reference to a Texture object
         */
        void set(const Texture &texture);

        ::Texture _texture; // Texture C structure
    };

#include "Texture.inl"
}

#endif /* !TEXTURE_HPP_ */
