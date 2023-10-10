//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_VERTEX_HPP
#define INC_2_SHADERS_VERTEX_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace Graphic::Buffers {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;

        // Касательный вектор
        glm::vec3 tangent;
        // Вектор бинормали (вектор, перпендикулярный касательному вектору и вектору нормали)
        glm::vec3 bitangent;
    };

    void setVertexAttribute(const int& index, const int& size, const int& stride, void* offset);
}

#endif    //INC_2_SHADERS_VERTEX_HPP
