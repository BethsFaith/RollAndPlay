//
// Created by VerOchka on 22.09.2023.
//

#include "../../headers/GraphicLib/Textures/Texture.hpp"

#include <utility>

namespace GraphicLib::Textures {
    Texture::Texture(std::string name, std::string path, GLenum type) : _name(std::move(name)), _path(std::move(path)), _type(type) {
        glGenTextures(1, &_id);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &_id);
    }

    void Texture::bind() const{
        glBindTexture(_type, _id);
    }

    void Texture::unbind() const{
        glBindTexture(_type, 0);
    }

    void Texture::activate(unsigned int gl_int) const {
        glActiveTexture(gl_int);
        bind();
    }

    void Texture::deactivate() const {
        glActiveTexture(GL_TEXTURE0);
        unbind();
    }

    unsigned int Texture::getId() const {
        return _id;
    }

    const std::string& Texture::getName() const {
        return _name;
    }

    const std::string& Texture::getPath() const {
        return _path;
    }

    GLenum Texture::getType() const {
        return _type;
    }

    void Texture::setImage(int internalFormat, unsigned int format, int width, int height, int dataType,
                           unsigned char *data) const {
        setImage(_type, internalFormat, format, width, height, dataType, data);
    }

    void Texture::setImage(unsigned int type, int internalFormat, unsigned int format, int width, int height,
                           int dataType,
                           unsigned char *data) {
        glTexImage2D(type, 0, internalFormat, width, height, 0, format, dataType, data);
    }
}
