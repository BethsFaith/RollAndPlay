//
// Created by VerOchka on 17.08.2023.
//

#include "../../headers/GraphicLib/Buffers/Vao.hpp"

namespace GraphicLib::Buffers {
    VAO::VAO() : RaiiBuffer(0) {
        glGenVertexArrays(1, &_vao);
    }

    VAO::~VAO() {
        glDeleteVertexArrays(1, &_vao);
    }

    void VAO::bind() {
        glBindVertexArray(_vao);
    }

    void VAO::bindData(const unsigned int &bindFlag) {}

    void VAO::unbind() {
        glBindVertexArray(0);
    }

    unsigned int VAO::get() const {
        return _vao;
    }
}