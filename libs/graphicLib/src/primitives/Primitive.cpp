//
// Created by VerOchka on 10.10.2023.
//

#include "../../headers/GraphicLib/Primitives/Primitive.hpp"

namespace GraphicLib::Primitives {
    Primitive::Primitive(const int &vertexNumber) : Primitive(vertexNumber, {}) {}

    Primitive::Primitive(const int &vertexNumber, const Settings &settings_)
            : vertexNumber(vertexNumber), settings(settings_) {

        _vao = std::make_shared<Buffers::VAO>();
        add(_vao);
    }

    void Primitive::bind() {
        _vao->bind();
    }

    void Primitive::unbind() {
        _vao->unbind();
    }

    void Primitive::bindData(const unsigned int &bindFlag) {
        for (auto &buffer: buffers) {
            buffer->bind();
            buffer->bindData(bindFlag);
        }
    }

    void Primitive::draw() {
        bind();
    }

    void Primitive::add(Buffers::RaiiBuffer::Ptr raiiBuffer) {
        buffers.push_back(std::move(raiiBuffer));

        std::sort(buffers.begin(),
                  buffers.end(),
                  [](const std::shared_ptr<Buffers::RaiiBuffer> &buf1,
                     const std::shared_ptr<Buffers::RaiiBuffer> &buf2) {
                      return buf1->getPriority() < buf2->getPriority();
                  });
    }

    unsigned int Primitive::getUid() const {
        return _vao->get();
    }
}