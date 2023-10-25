//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_SHADERPROGRAM_HPP
#define ROLLANDPLAY_SHADERPROGRAM_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace GraphicLib::Shaders {
    class ShaderProgram {
    public:
        using Ptr = std::shared_ptr<ShaderProgram>;

        // Конструктор считывает данные и выполняет построение шейдера
        ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

        // Использование/активация шейдера
        void use();

        // Полезные uniform-функции
        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void set3UnsignedIntVector(const std::string& name, void* uiv) const;
        void set3FloatVector(const std::string& name, float c1, float c2, float c3) const;
        void set3FloatVector(const std::string& name, const glm::vec3& vector) const;
        void set4FloatVector(const std::string& name, float c1, float c2, float c3, float c4) const;
        void set4FloatVector(const std::string& name, const glm::vec4& vector) const;
        void set4FloatMat(const std::string& name, const GLfloat* value) const;

        [[nodiscard]] unsigned int getId() const;

    private:
        // IdCounter - идентификатор программы
        unsigned int ID;
    };
}

#endif //ROLLANDPLAY_SHADERPROGRAM_HPP
