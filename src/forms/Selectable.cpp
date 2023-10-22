//
// Created by VerOchka on 22.10.2023.
//

#include "Selectable.hpp"

namespace Forms {
    bool Selectable::init(unsigned int windowWidth, unsigned int windowHeight) {
        _texture = std::make_shared<Graphic::Textures::Texture>("", "");
        _texture->bind();
        _texture->setImage(GL_RGB32F, GL_RGB, windowWidth, windowHeight,
                           GL_FLOAT, nullptr);

        _fbo = std::make_shared<Graphic::Buffers::FBO>(GL_FRAMEBUFFER, _texture->getId());
        _fbo->bindData(GL_COLOR_ATTACHMENT0);

        glReadBuffer(GL_NONE);
        glDrawBuffer(GL_COLOR_ATTACHMENT0);

        // Restore the default framebuffer
        _texture->unbind();
        _fbo->unbind();

        return glGetError();
    }

    void Selectable::enableWriting() {
        _fbo->setMode(GL_DRAW_FRAMEBUFFER);
        _fbo->bind();
    }

    void Selectable::disableWriting() {
        _fbo->setMode(GL_DRAW_FRAMEBUFFER);
        _fbo->unbind();
    }

    Selectable::PixelInfo Selectable::readPixel(unsigned int x, unsigned int y) {
        _fbo->setMode(GL_READ_FRAMEBUFFER);
        _fbo->bind();
        _fbo->startRead();

        PixelInfo Pixel;
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &Pixel);

        _fbo->stopRead();
        _fbo->unbind();

        return Pixel;
    }
}