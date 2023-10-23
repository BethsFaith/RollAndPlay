//
// Created by VerOchka on 22.10.2023.
//

#ifndef ROLLANDPLAY_PICKING_HPP
#define ROLLANDPLAY_PICKING_HPP

#include "graphic/buffers/Fbo.hpp"
#include "graphic/textures/Texture.hpp"

class Picking {
public:
    struct PixelInfo {
        float ObjectID = 0.0f;
        float DrawID = 0.0f;
        float PrimID = 0.0f;
    };

    Picking() = default;
    ~Picking() = default;

    bool init(unsigned int windowWidth, unsigned int windowHeight);

    void enableWriting() const;

    void disableWriting() const;

    PixelInfo readPixel(unsigned int x, unsigned int y);

private:
    Graphic::Buffers::FBO::Ptr _fbo;
    Graphic::Textures::Texture::Ptr _texture;
};

#endif //ROLLANDPLAY_PICKING_HPP
