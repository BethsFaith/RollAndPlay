//
// Created by VerOchka on 21.10.2023.
//

#include "Fbo.hpp"

namespace Graphic::Buffers {
    FBO::FBO(GLuint mode, unsigned int texture)
            : RaiiBuffer(3),
              _texture(texture),
              _mode(mode){
        glGenFramebuffers(1, &_fbo);
    }

    FBO::~FBO() {
        glDeleteFramebuffers(1, &_fbo);
    }

    void FBO::bind() {
        glBindFramebuffer(_mode, _fbo);
    }

    void FBO::unbind() {
        glBindFramebuffer(_mode, 0);
    }

    void FBO::bindData(const unsigned int &attachment) {
        bind();
        glFramebufferTexture2D(_mode, attachment, GL_TEXTURE_2D, _texture, 0);
        auto status = glCheckFramebufferStatus(GL_READ_FRAMEBUFFER);
        if (glCheckFramebufferStatus(GL_READ_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            std::cout << "FB error, status: 0x%x\n" << status << std::endl;
        }
        _attachment = attachment;
    }

    unsigned int FBO::get() const {
        return _fbo;
    }

    void FBO::setMode(unsigned int mode) {
        _mode = mode;
    }

    void FBO::startRead() const {
        glReadBuffer(_attachment);
    }

    void FBO::stopRead() {
        glReadBuffer(GL_NONE);
    }

    void FBO::draw() const {
        glDrawBuffer(_attachment);
    }
}