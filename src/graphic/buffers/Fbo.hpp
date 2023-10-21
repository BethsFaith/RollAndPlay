//
// Created by VerOchka on 21.10.2023.
//

#ifndef ROLLANDPLAY_FBO_HPP
#define ROLLANDPLAY_FBO_HPP

#include "RaiiBuffer.hpp"

namespace Graphic::Buffers {
    class FBO : RaiiBuffer {
    public:
        FBO(GLuint colorAttachment, unsigned int texture);
        ~FBO() override;

    private:
        void bind() override;

        void unbind() override;

        void bindData(const unsigned int &bind_flag) override;

        [[nodiscard]] unsigned int get() const override;

    private:
        unsigned int _fbo{};
        unsigned int _texture;
        unsigned int _attachment{};
    };
}


#endif //ROLLANDPLAY_FBO_HPP
