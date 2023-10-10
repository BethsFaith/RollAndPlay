//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_ABSTRACTPRIMITIVE_HPP
#define ROLLANDPLAY_ABSTRACTPRIMITIVE_HPP

namespace Graphic {
    class AbstractPrimitive {
    public:
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
