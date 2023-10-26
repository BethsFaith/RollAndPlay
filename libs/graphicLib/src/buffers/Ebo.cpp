//
// Created by VerOchka on 19.08.2023.
//

#include "../../headers/GraphicLib/Buffers/Ebo.hpp"

namespace GraphicLib::Buffers {
    EBO::EBO(std::vector<unsigned int> indices) : RaiiBuffer(2), _indices(std::move(indices)) {
        glGenBuffers(1, &_ebo);
    }

    EBO::~EBO() {
        glDeleteBuffers(1, &_ebo);
    }

    void EBO::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    }

    void EBO::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void EBO::bindData(const unsigned int &bindFlag) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(float), &_indices[0], bindFlag);
    }

    unsigned int EBO::get() const {
        return _ebo;
    }

    const std::vector<unsigned int> &EBO::getIndices() const {
        return _indices;
    }
}