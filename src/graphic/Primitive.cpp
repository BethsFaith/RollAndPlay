//
// Created by VerOchka on 10.10.2023.
//

#include "Primitive.hpp"

namespace Graphic {
    Primitive::Primitive(const int &vertex_number_) : Primitive(vertex_number_, {}) {}

    Primitive::Primitive(const int &vertex_number_, const Settings &settings_)
            : vertex_number(vertex_number_), settings(settings_) {

        _vao = std::make_shared<Buffers::VAO>();
        add(_vao);
    }

    void Primitive::bind() {
        _vao->bind();
    }

    void Primitive::unbind() {
        _vao->unbind();
    }

    void Primitive::bindData(const unsigned int &bind_flag) {
        for (auto &buffer: buffers) {
            buffer->bind();
            buffer->bindData(bind_flag);
        }
    }

    void Primitive::draw() {
        bind();
    }

    void Primitive::add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer) {
        buffers.push_back(std::move(raii_buffer));

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