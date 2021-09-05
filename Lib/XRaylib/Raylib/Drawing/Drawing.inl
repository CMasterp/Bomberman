/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Drawing
*/

inline void Raylib::Drawing::clearBackground(const Color &color)
{
    ::ClearBackground(color.getCStruct());
}

inline void Raylib::Drawing::beginDrawing(void)
{
    ::BeginDrawing();
}

inline void Raylib::Drawing::endDrawing(void)
{
    ::EndDrawing();
}

inline void Raylib::Drawing::drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color)
{
    ::DrawCubeTexture(texture, position.getCStruct(), width, height,  length, color.getCStruct());
}

inline void Raylib::Drawing::drawSphere(Vector3 centerPos, float radius, Color color)
{
    ::DrawSphere(centerPos.getCStruct(), radius, color.getCStruct());
}