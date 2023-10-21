//
// Created by VerOchka on 21.10.2023.
//

#include "Fbo.hpp"

namespace Graphic::Buffers {
    FBO::FBO(GLuint colorAttachment, unsigned int texture) : RaiiBuffer(3), _texture(texture),
    _attachment(colorAttachment) {
        glGenFramebuffers(1, &_fbo);
    }

    FBO::~FBO() {
        glDeleteFramebuffers(1, &_fbo);
    }

    void FBO::bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
    }

    void FBO::unbind() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void FBO::bindData(const unsigned int &bind_flag) {
        glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, _attachment, GL_TEXTURE_2D, _texture, 0);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE) {
            // Выполняем победный танец
        }
    }

    unsigned int FBO::get() const {
        return _fbo;
    }
}