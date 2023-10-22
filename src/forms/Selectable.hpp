//
// Created by VerOchka on 22.10.2023.
//

#ifndef ROLLANDPLAY_SELECTABLE_HPP
#define ROLLANDPLAY_SELECTABLE_HPP

#include "../graphic/buffers/Fbo.hpp"
#include "../graphic/textures/Texture.hpp"

namespace Forms {
    class Selectable {
    public:
        struct PixelInfo {
            float ObjectID = 0.0f;
            float DrawID = 0.0f;
            float PrimID = 0.0f;
        };

        Selectable() = default;

        virtual ~Selectable() = default;

        virtual bool init(unsigned int windowWidth, unsigned int windowHeight);

        void enableWriting();

        void disableWriting();

        PixelInfo readPixel(unsigned int x, unsigned int y);

    private:
        Graphic::Buffers::FBO::Ptr _fbo;
        Graphic::Textures::Texture::Ptr _texture;
    };
}

#endif //ROLLANDPLAY_SELECTABLE_HPP
