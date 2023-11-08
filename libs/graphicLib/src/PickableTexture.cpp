//
// Created by VerOchka on 22.10.2023.
//

#include "../headers/GraphicLib/PickableTexture.hpp"

namespace GraphicLib {
    bool PickableTexture::init(unsigned int windowWidth, unsigned int windowHeight) {
        _texture = std::make_shared< GraphicLib::Textures::Texture>("", "");
        _texture->bind();
        _texture->setImage(GL_RGB32F, GL_RGB, windowWidth, windowHeight,
                           GL_FLOAT, nullptr);

        _fbo = std::make_shared< GraphicLib::Buffers::FBO>(GL_FRAMEBUFFER, _texture->getId());
        _fbo->bindData(GL_COLOR_ATTACHMENT0);

        _fbo->stopRead();
        _fbo->draw();

        // Restore the default framebuffer
        _texture->unbind();
        _fbo->unbind();

        return glGetError();
    }

    void PickableTexture::enableWriting() const {
        _fbo->setMode(GL_DRAW_FRAMEBUFFER);
        _fbo->bind();
    }

    void PickableTexture::disableWriting() const {
        _fbo->setMode(GL_DRAW_FRAMEBUFFER);
        _fbo->unbind();
    }

    PickableTexture::PixelInfo PickableTexture::readPixel(unsigned int x, unsigned int y) {
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