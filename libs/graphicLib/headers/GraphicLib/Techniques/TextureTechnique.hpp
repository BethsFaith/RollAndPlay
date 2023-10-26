//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTURETECHNIQUE_HPP
#define ROLLANDPLAY_TEXTURETECHNIQUE_HPP

#include "Technique.hpp"
#include "GraphicLib/Textures/Texture.hpp"

namespace GraphicLib::Techniques {
    class TextureTechnique : public Technique {
    public:
        ~TextureTechnique() override = default;

        void execute() override;

        void setTexture(const Textures::Texture::Ptr &texture);

        void setTextureIndex(int textureIndex);

    private:
        Textures::Texture::Ptr _texture;
        int _textureIndex;
    };
}

#endif //ROLLANDPLAY_TEXTURETECHNIQUE_HPP
