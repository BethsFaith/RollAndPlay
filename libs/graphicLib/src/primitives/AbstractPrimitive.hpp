//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_ABSTRACTPRIMITIVE_HPP
#define ROLLANDPLAY_ABSTRACTPRIMITIVE_HPP

#include <iostream>

namespace GraphicLib::Primitives {
    class AbstractPrimitive {
    public:
        using Ptr = std::shared_ptr<AbstractPrimitive>;

        explicit AbstractPrimitive() = default;

        virtual ~AbstractPrimitive() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void bindData(const unsigned int &bind_flag) = 0;

        virtual void draw() = 0;

        [[nodiscard]] virtual unsigned int getUid() const = 0;
    };
}


#endif //ROLLANDPLAY_ABSTRACTPRIMITIVE_HPP
