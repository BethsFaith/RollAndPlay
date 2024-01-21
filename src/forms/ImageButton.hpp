//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_IMAGEBUTTON_HPP
#define ROLLANDPLAY_IMAGEBUTTON_HPP

#include <GraphicLib/Techniques/TextureTechnique.hpp>
#include <GraphicLib/Textures/Loader.hpp>
#include <GraphicLib/Textures/Texture.hpp>

#include "Button.hpp"

namespace Forms {
    class ImageButton : public Button {
    public:
        using Ptr = std::shared_ptr<ImageButton>;

        explicit ImageButton(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);

        void init(glm::vec2 scale,
                  glm::vec2 position,
                  const TextForm& text,
                  const std::string& texturePath,
                  int textureIndex);

        void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void setImage(const std::string& texturePath);

    private:
        GraphicLib::Textures::Texture::Ptr _texture;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_IMAGEBUTTON_HPP
