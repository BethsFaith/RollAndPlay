//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_RAIIBUFFER_HPP
#define INC_2_SHADERS_RAIIBUFFER_HPP

#include <iostream>

#include "EntryPoint.hpp"

namespace GraphicLib::Buffers {
    class RaiiBuffer {
    public:
        using Ptr = std::shared_ptr<RaiiBuffer>;

        explicit RaiiBuffer(const int &priority);

        virtual ~RaiiBuffer() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void bindData(const unsigned int &bindFlag) = 0;

        [[nodiscard]] unsigned int getPriority() const;

        [[nodiscard]] virtual unsigned int get() const = 0;

    private:
        unsigned int _priority;
    };
}

#endif    //INC_2_SHADERS_RAIIBUFFER_HPP
