/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Shader
*/

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib {
    class Shader {
    public:
        /**
         * @brief Construct a new Shader object
         */
        Shader();

        /**
         * @brief Destroy the Shader object
         */
        ~Shader();

        /**
         * @brief Construct a new Shader object (Copy Constructor)
         *
         * @param Shader A Shader C Structure
         */
        Shader(::Shader const &shader);

        /**
         * @brief Construct a new Shader object (Copy Constructor)
         *
         * @param vsFileName A const reference to a char *
         * @param fsFileName A const reference to a char *
         */
        Shader(const std::string &vsFileName, const std::string &fsFileName);

        /**
         * @brief Get C Structure for Shader Class
         * @return A Shader C Structure
         */
        ::Shader getCStruct(void) const;

        /**
          * @brief Overload of '=' operator
          *
          * @param shader A const reference to a Shader
          * @return A reference to Shader (Shader &)
          */
        Shader &operator=(const Shader &shader);

        /**
          * @brief Begin custom shader drawing
          *
          * @param shader A const reference to a Shader
          */
        void beginShaderMode(Shader const &shader) const;

        /**
          * @brief End custom shader drawing (use default shader)
          */
        void endShaderMode(void) const;

        /**
          * @brief Load shader from files and bind default locations
          *
          * @param vsFileName A const reference to a char *
          * @param fsFileName A const reference to a char *
          *
          * @return A Shader
          */
        Shader loadShader(const char *vsFileName, const char *fsFileName) const;

        /**
          * @brief Load shader from code strings and bind default locations
          *
          * @param vsCode A const reference to a char *
          * @param fsCode A const reference to a char *
          *
          * @return A Shader
          */
        Shader loadShaderFromMemory(const char *vsCode, const char *fsCode) const;

        /**
          * @brief Get shader uniform location
          *
          * @param shader A const reference to a Shader
          * @param uniformName A const reference to a char *
          * @return Int
          */
        int getShaderLocation(Shader const &shader, const char *uniformName) const;

        /**
          * @brief Get shader attribute location
          *
          * @param shader A const reference to a Shader
          * @param uniformName A const reference to a char *
          * @return Int
          */
        int getShaderLocationAttrib(Shader const &shader,
                                    const char *attribName) const;

        /**
          * @brief Set shader uniform value
          *
          * @param shader A const reference to a Shader
          * @param locIndex A const reference to an int
          * @param value A const Void *
          * @param uniformType A const reference to an int
          */
        void setShaderValue(Shader const &shader, int const &locIndex,
                            const void *value, int const &uniformType) const;

        /**
          * @brief Set shader uniform value vector
          *
          * @param shader A const reference to a Shader
          * @param locIndex A const reference to an int
          * @param value A const Void *
          * @param uniformType A const reference to an int
          * @param count A const reference to an int
          */
        void setShaderValueV(Shader const &shader, int const &locIndex,
                             const void *value, int const &uniformType,
                             int const &count) const;

        /**
          * @brief Set shader uniform value (matrix 4x4)
          *
          * @param shader A const reference to a Shader
          * @param locIndex A const reference to an int
          * @param mat A const reference to a Matrix
          */
        void setShaderValueMatrix(Shader const &shader, int const &locIndex,
                                  Matrix const &mat) const;

        /**
          * @brief Set shader uniform value for texture (sampler2d)
          *
          * @param shader A const reference to a Shader
          * @param locIndex A const reference to an int
          * @param texture A const reference to a Texture
          */
        void setShaderValueTexture(Shader const &shader, int const &locIndex,
                                   Texture2D const &texture) const;

        /**
          * @brief Unload shader from GPU memory (VRAM)
          *
          * @param shader A const reference to a Shader
          */
        void unloadShader(Shader shader) const;

    private:
        /**
         * @brief Set Shader
         *
         * @param Shader A Shader C Structure
         */
        void set(const ::Shader &shader);

        /**
         * @brief Set Shader
         *
         * @param Shader A const reference to a Shader object
         */
        void set(const Shader &shader);

        /**
         * @brief Declare a Shader
         *
         */
        ::Shader _shader;
    };

#include "Shader.inl"

} // namespace Raylib
#endif /* !SHADER_HPP_ */
