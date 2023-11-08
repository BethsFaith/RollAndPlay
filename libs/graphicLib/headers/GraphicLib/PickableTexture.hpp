//
// Created by VerOchka on 22.10.2023.
//

#ifndef ROLLANDPLAY_PICKABLETEXTURE_HPP
#define ROLLANDPLAY_PICKABLETEXTURE_HPP

#include "Buffers/Fbo.hpp"
#include "Textures/Texture.hpp"

namespace GraphicLib {
    class PickableTexture {
    public:
        using Ptr = std::shared_ptr<PickableTexture>;

        struct PixelInfo {
            float ObjectID = 0.0f;
            float DrawID = 0.0f;
            float PrimID = 0.0f;
        };

        PickableTexture() = default;
        ~PickableTexture() = default;

        bool init(unsigned int windowWidth, unsigned int windowHeight);

        void enableWriting() const;

        void disableWriting() const;

        PixelInfo readPixel(unsigned int x, unsigned int y);

    private:
        GraphicLib::Buffers::FBO::Ptr _fbo;
        GraphicLib::Textures::Texture::Ptr _texture;
    };
}

#endif //ROLLANDPLAY_PICKABLETEXTURE_HPP
