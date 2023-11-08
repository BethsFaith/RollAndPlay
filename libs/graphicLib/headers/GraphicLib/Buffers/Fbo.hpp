//
// Created by VerOchka on 21.10.2023.
//

#ifndef ROLLANDPLAY_FBO_HPP
#define ROLLANDPLAY_FBO_HPP

#include <iostream>

#include "RaiiBuffer.hpp"

namespace GraphicLib::Buffers {
    class FBO : RaiiBuffer {
    public:
        using Ptr = std::shared_ptr<FBO>;

        FBO(GLuint mode, unsigned int texture);

        void setMode(unsigned int mode);

        ~FBO() override;

        void bind() override;

        void unbind() override;

        void bindData(const unsigned int &attachment) override;

        void startRead() const;
        static void stopRead();

        void draw() const;

        [[nodiscard]] unsigned int get() const override;

    private:
        unsigned int _fbo{};
        unsigned int _mode{};
        unsigned int _texture{};
        unsigned int _attachment{};
    };
}


#endif //ROLLANDPLAY_FBO_HPP
