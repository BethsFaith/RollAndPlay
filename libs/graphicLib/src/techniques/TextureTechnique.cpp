//
// Created by VerOchka on 26.10.2023.
//

#include "GraphicLib/Techniques/TextureTechnique.hpp"

namespace GraphicLib::Techniques {
    void TextureTechnique::execute() {
        shader->setInt("Texture", _textureIndex);
        _texture->activate(GL_TEXTURE0+_textureIndex);
    }

    void TextureTechnique::setTexture(const Textures::Texture::Ptr &texture) {
        _texture = texture;
    }

    void TextureTechnique::setTextureIndex(int textureIndex) {
        _textureIndex = textureIndex;
    }
}