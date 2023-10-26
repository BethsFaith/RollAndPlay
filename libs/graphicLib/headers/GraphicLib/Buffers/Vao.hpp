//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_VAO_HPP
#define INC_2_SHADERS_VAO_HPP

#include "RaiiBuffer.hpp"

namespace GraphicLib::Buffers {
    class VAO : public RaiiBuffer {
    public:
        using Ptr = std::shared_ptr<VAO>;

        VAO();

        ~VAO() override;

        void bindData(const unsigned int &bindFlag) override;

        void bind() override;

        void unbind() override;

        [[nodiscard]] unsigned int get() const override;

    private:
        unsigned int _vao{};
    };
}

#endif    //INC_2_SHADERS_VAO_HPP
