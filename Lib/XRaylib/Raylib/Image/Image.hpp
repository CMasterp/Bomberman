/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Font/Font.hpp"
#include "Color/Color.hpp"
#include "Rectangle/Rectangle.hpp"

namespace Raylib
{
    class Image {

    public:
        /**
         * @brief Construct a new Image object
         */
        Image();

        /**
         * @brief Construct a new Image object
         *
         * @param image An Image
         */
        Image(const Image &image);

        /**
         * @brief Construct a new Image object
         *
         * @param fileName A string
         */
        Image(const std::string &fileName);

        /**
         * @brief Construct a new Image object
         *
         * @param fileName A string
         * @param width An int
         * @param height An int
         * @param format An int
         * @param headerSize An int
         */
        Image(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

        /**
         * @brief Destroy the Image object
         */
        ~Image();

        /**
         * @brief Getter of Image structure (private attribute)
         *
         * @return An Image C structure
         */
        ::Image getCStruct(void) const;

        /**
        * @brief Get pixel data from screen buffer and return an Image (screenshot)
        *
        * @return An Image Class
        */
        Image getScreenData(void);

        /**
         * @brief Load image from file into CPU memory (RAM)
         *
         * @param fileName A const std::string
         * @return An Image
         */
        Image loadImage(const std::string &fileName);

        /**
         * @brief Load image from RAW file data
         *
         * @param fileName A const std::string
         * @param width An int
         * @param height An int
         * @param format An int
         * @param headerSize An int
         * @return An Image
         */
        Image loadImageRaw(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

        /**
         * @brief Load image sequence from file (frames appended to image.data)
         *
         * @param fileName A const std::string
         * @param frames An int *
         * @return An Image
         */
        Image loadImageAnim(const std::string &fileName, int *frames);

        /**
         * @brief Load image from memory buffer
         *
         * @param fileType A const std::string
         * @param fileData A const unsigned std::string
         * @param dataSize An int
         * @return An Image
         */
        Image loadImageFromMemory(const std::string &fileType, const std::string &fileData, const int &dataSize);

        /**
         * @brief Unload image from CPU memory (RAM)
         *
         * @param image An Image
         */
        void unloadImage(void);

        /**
         * @brief Export image data to file, returns true on success
         *
         * @param image An Image
         * @param fileName A const std::string
         * @return A boolean
         */
        bool exportImage(const Image &image, const std::string &fileName) const;

        /**
         * @brief Export image as code file defining an array of bytes, returns true on success
         *
         * @param image An Image
         * @param fileName A const std::string
         * @return true or false
         */
        bool exportImageAsCode(const Image &image, const std::string &fileName) const;

        /**
         * @brief Returns the pixel data size of the image.
         *
         * @return The pixel data size of the image.
         */
        int getPixelDataSize(void) const;

        /**
         * @brief Overload of '=' operator
         *
         * @param music A const reference to An Image
         * @return A reference to Image (Image &)
         */
        Image &operator=(const Image &image);

        /**
        * @brief Get pixel data from GPU texture and return an Image
        *
        * @param texture A const reference to a Texture
        * @return An Image Class
        */
        Image getTextureData(::Texture const &texture) const;

        /**
         * @brief Generate image: plain color
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param color A const pointer to a Class Color
         * @return An Image Class
         */
        Image genImageColor(int const &width, int const &height, Color const &color);

        /**
         * @brief Generate image: vertical gradient
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param top A const pointer to a Class Color
         * @param bottom A const pointer to a Class Color
         * @return An Image Class
         */
        Image genImageGradientV(int const &width, int const &height, Color const &top, Color const &bottom);

        /**
         * @brief Generate image: horizontal gradient
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param left A const pointer to a Class Color
         * @param right A const pointer to a Class Color
         * @return An Image Class
         */
        Image genImageGradientH(int const &width, int const &height, Color const &left, Color const &right);

        /**
         * @brief Generate image: radial gradient
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param inner A const pointer to a Class Color
         * @param outer A const pointer to a Class Color
         * @return An Image Class
         */
        Image genImageGradientRadial(int const &width, int const &height, float density, Color inner, Color outer);

        /**
         * @brief Generate image: checked
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param checksX A const reference to an int
         * @param checksY A const reference to an int
         * @param col1 A const pointer to a Class Color
         * @param col2 A const pointer to a Class Color
         * @return An Image Class
         */
        Image genImageChecked(int const &width, int const &height, int const &checksX, int const &checksY, Color col1, Color col2);

        /**
         * @brief Generate image: white noise
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param factor A const reference to a float
         * @return An Image Class
         */
        Image genImageWhiteNoise(int const &width, int const &height, float const &factor);

        /**
         * @brief Generate image: perlin noise
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param offsetX A const reference to an int
         * @param offsetY A const reference to an int
         * @param scale A const reference to a float
         * @return An Image Class
         */
        Image genImagePerlinNoise(int const &width, int const &height, int offsetX, int offsetY, float scale);

        /**
         * @brief Generate image: cellular algorithm. Bigger tileSize means bigger cells
         *
         * @param width A const reference to an int
         * @param height A const reference to an int
         * @param tileSize A const reference to an int
         * @return An Image Class
         */
        Image genImageCellular(int const &width, int const &height, int const &tileSize);

        /**
         * @brief Create an image duplicate (useful for transformations)
         *
         * @param image A const reference to a Class Image
         * @return An Image Class
         */
        Image imageCopy(Image const &image);

        /**
         * @brief Create an image from another image piece
         *
         * @param image A const reference to a Class Image
         * @param rec A const reference to a Class Rectangle
         * @return An Image Class
         */
        Image imageFromImage(Image const &image, ::Rectangle const &rec);

        /**
         * @brief Create an image from text (default font)
         *
         * @param text A const pointer to a char
         * @param fontSize A const reference to an int
         * @param color A const reference to a Class Color
         * @return An Image Class
         */
        Image imageText(const char *text, int const &fontSize, Color const &color);

        /**
         * @brief Create an image from text (custom sprite font)
         *
         * @param font A const reference to a Class Font
         * @param text A const pointer to a char
         * @param fontSize A const pointer to a float
         * @param spacing A const pointer to a float
         * @param tint A const reference to a Class Color
         * @return An Image Class
         */
        Image imageTextEx(Font const &font, const char *text, float const &fontSize, float const &spacing, Color const &tint);

    private:
        /**
         * @brief Set Image
         *
         * @param image An Image C Structure
         */
        void set(const ::Image &image);

        /**
         * @brief Set Image
         *
         * @param image A const reference to An Image object
         */
        void set(const Image &image);

        ::Image _image; // Image C structure
    };

#include "Image.inl"
}

#endif /* !IMAGE_HPP_ */
