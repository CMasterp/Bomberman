/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Image
*/

inline ::Image Raylib::Image::getCStruct(void) const
{
    return _image;
}

inline void Raylib::Image::set(const ::Image &image)
{
    _image = image;
}

inline void Raylib::Image::set(const Image &image)
{
    _image = image._image;
}

inline Raylib::Image Raylib::Image::getScreenData(void)
{
    _image = ::GetScreenData();
    return *this;
}

inline Raylib::Image Raylib::Image::loadImage(const std::string &fileName)
{
    _image = ::LoadImage(fileName.c_str());
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageRaw(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize)
{
    _image = ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageAnim(const std::string &fileName, int *frames)
{
    _image = ::LoadImageAnim(fileName.c_str(), frames);
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageFromMemory(const std::string &fileType, const std::string &fileData, const int &dataSize)
{
    set(::LoadImageFromMemory(fileType.c_str(), (const unsigned char *)fileData.c_str(), dataSize));
    return *this;
}

inline void Raylib::Image::unloadImage(void)
{
    if (_image.data != NULL) {
        ::UnloadImage(_image);
        _image.data = NULL;
    }
}

inline bool Raylib::Image::exportImage(const Image &image, const std::string &fileName) const
{
    return ::ExportImage(_image, fileName.c_str());
}

inline bool Raylib::Image::exportImageAsCode(const Image &image, const std::string &fileName) const
{
    return ::ExportImageAsCode(_image, fileName.c_str());
}

inline int Raylib::Image::getPixelDataSize(void) const
{
    return ::GetPixelDataSize(_image.width, _image.height, _image.format);
}

inline Raylib::Image &Raylib::Image::operator=(const Image &image)
{
    set(image);
    return *this;
}

inline Raylib::Image Raylib::Image::getTextureData(::Texture const &texture) const
{
    ::GetTextureData(texture);
    return *this;
}

inline Raylib::Image Raylib::Image::genImageColor(int const &width, int const &height, Color const &color)
{
    ::GenImageColor(width, height, color.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientV(int const &width, int const &height, Color const &top, Color const &bottom)
{
    ::GenImageGradientV(width, height, top.getCStruct(), bottom.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientH(int const &width, int const &height, Color const &left, Color const &right)
{
    ::GenImageGradientH(width, height, left.getCStruct(), right.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientRadial(int const &width, int const &height, float density, Color inner, Color outer)
{
    ::GenImageGradientRadial(width, height, density, inner.getCStruct(), outer.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageChecked(int const &width, int const &height, int const &checksX, int const &checksY, Color col1, Color col2)
{
    ::GenImageChecked(width, height, checksX, checksY, col1.getCStruct(), col2.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageWhiteNoise(int const &width, int const &height, float const &factor)
{
    ::GenImageWhiteNoise(width, height, factor);
    return *this;
}

inline Raylib::Image Raylib::Image::genImagePerlinNoise(int const &width, int const &height, int offsetX, int offsetY, float scale)
{
    ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    return *this;
}

inline Raylib::Image Raylib::Image::genImageCellular(int const &width, int const &height, int const &tileSize)
{
    ::GenImageCellular(width, height, tileSize);
    return *this;
}

inline Raylib::Image Raylib::Image::imageCopy(Image const &image)
{
    ::ImageCopy(image.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::imageFromImage(Image const &image, ::Rectangle const &rec)
{
    ::ImageFromImage(image.getCStruct(), rec);
    return *this;
}

inline Raylib::Image Raylib::Image::imageText(const char *text, int const &fontSize, Color const &color)
{
    ::ImageText(text, fontSize, color.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::imageTextEx(Font const &font, const char *text, float const &fontSize, float const &spacing, Color const &tint)
{
    ::ImageTextEx(font.getCStruct(), text, fontSize, spacing, tint.getCStruct());
    return *this;
}
