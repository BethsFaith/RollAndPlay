//
// Created by VerOchka on 22.09.2023.
//

#include "../../headers/GraphicLib/Buffers/Vertex.hpp"

namespace GraphicLib::Buffers {
    void setVertexAttribute(const int &index, const int &size, const int &stride, void *offset) {
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(index);
    }
}