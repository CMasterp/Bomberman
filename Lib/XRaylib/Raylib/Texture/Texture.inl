/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

inline Raylib::Texture &Raylib::Texture::operator=(const Texture &texture)
{
    set(texture);
    return *this;
}

inline ::Texture Raylib::Texture::getCStruct(void) const
{
    return _texture;
}

inline void Raylib::Texture::set(const ::Texture &texture)
{
    _texture = texture;
}

inline void Raylib::Texture::set(const Texture &texture)
{
    _texture = texture._texture;
}

inline void Raylib::Texture::unloadTexture(Texture const &texture) const
{
    ::UnloadTexture(texture._texture);
}

inline void Raylib::Texture::setShapesTexture(const Texture &texture, const Rectangle &source)
{
    ::SetShapesTexture(texture._texture, source.getCStruct());
}

inline Raylib::Texture &Raylib::Texture::loadTexture(const std::string fileName)
{
    _texture = ::LoadTexture(fileName.c_str());
    return *this;
}

inline Raylib::Texture &Raylib::Texture::loadTextureFromImage(Image const &image)
{
    _texture = ::LoadTextureFromImage(image.getCStruct());
    return *this;
}

inline void Raylib::Texture::beginTextureMode(RenderTexture const &target) const
{
    ::BeginTextureMode(target.getCStruct());
}

inline void Raylib::Texture::endTextureMode(void) const
{
    ::EndTextureMode();
}

inline Raylib::Texture Raylib::Texture::loadTextureCubemap(Image const &image, int const &layout)
{
    _texture = ::LoadTextureCubemap(image.getCStruct(), layout);
    return *this;
}

inline void Raylib::Texture::updateTexture(Texture const &texture, const void *pixels) const
{
    ::UpdateTexture(texture._texture, pixels);
}

inline void Raylib::Texture::updateTextureRec(Texture const &texture, Rectangle const &rec, const void *pixels) const
{
    ::UpdateTextureRec(texture._texture, rec.getCStruct(), pixels);
}

inline void Raylib::Texture::genTextureMipmaps(Texture const *texture) const
{
    ::Texture c_texture = texture->getCStruct();

    ::GenTextureMipmaps(&c_texture);
}

inline void Raylib::Texture::setTextureFilter(Texture const &texture, int const &filter) const
{
    ::SetTextureFilter(texture._texture, filter);
}

inline void Raylib::Texture::setTextureWrap(Texture const &texture, int const &wrap) const
{
    ::SetTextureWrap(texture._texture, wrap);
}

inline void Raylib::Texture::drawTexture(const int &posX, const int &posY, const Color &tint = Color::White()) const
{
    ::DrawTexture(_texture, posX, posY, tint.getCStruct());
}

inline void Raylib::Texture::drawTexture(const float &posX, const float &posY, float const &rotation, float const &scale, Color const &tint) const
{
    ::DrawTextureEx(_texture, {posX, posY}, rotation, scale, tint.getCStruct());
}

inline void Raylib::Texture::drawTextureV(Texture const &texture, Vector2 const &position, Color const &tint) const
{
    ::DrawTextureV(texture._texture, position.getCStruct(), tint.getCStruct());
}

inline void Raylib::Texture::drawTextureRec(Texture const &texture, Rectangle const &source, Vector2 const &position, Color const &tint = Color::White()) const
{
    ::DrawTextureRec(texture._texture, source.getCStruct(), position.getCStruct(), tint.getCStruct());
}

inline void Raylib::Texture::drawTextureQuad(Texture const &texture, Vector2 const &tiling, Vector2 const &offset, Rectangle const &quad, Color const &tint = Color::White()) const
{
    ::DrawTextureQuad(texture._texture, tiling.getCStruct(), offset.getCStruct(), quad.getCStruct(), tint.getCStruct());
}

inline void Raylib::Texture::drawTextureTiled(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, float const &scale, Color const &tint = Color::White()) const
{
    ::DrawTextureTiled(texture._texture, source.getCStruct(), dest.getCStruct(), origin.getCStruct(), rotation, scale, tint.getCStruct());
}

inline void Raylib::Texture::drawTexturePro(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::White()) const
{
    ::DrawTexturePro(texture._texture, source.getCStruct(), dest.getCStruct(), origin.getCStruct(), rotation, tint.getCStruct());
}

inline void Raylib::Texture::drawTextureNPatch(Texture const &texture, NPatchInfo const &nPatchInfo, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::White()) const
{
    ::DrawTextureNPatch(texture._texture, nPatchInfo, dest.getCStruct(), origin.getCStruct(), rotation, tint.getCStruct());
}

inline void Raylib::Texture::drawTexturePoly(const Texture &texture, const Vector2 &center, Vector2 &points, Vector2 &texcoords, const int &pointsCount, const Color &tint) const
{
    ::Vector2 pts = points.getCStruct();
    ::Vector2 tex = texcoords.getCStruct();

    ::DrawTexturePoly(texture._texture, center.getCStruct(), &pts, &tex, pointsCount, tint.getCStruct());
    points = pts;
    texcoords = tex;
}