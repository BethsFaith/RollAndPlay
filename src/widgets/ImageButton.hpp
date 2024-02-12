//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_IMAGEBUTTON_HPP
#define ROLLANDPLAY_IMAGEBUTTON_HPP

#include <GraphicLib/Textures/Loader.hpp>
#include <GraphicLib/Textures/Texture.hpp>

#include "Button.hpp"

namespace Widgets {
    class ImageButton : public Button {
    public:
        using Ptr = std::shared_ptr<ImageButton>;

        explicit ImageButton(GraphicLib::Primitives::AbstractPrimitive::Ptr graphicPrimitive);

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        void setColor(Styles::Color color) override;
        void setImage(const std::string& texturePath, int textureIndex);

        [[nodiscard]] const GraphicLib::Textures::Texture::Ptr& getTexture() const;
    protected:
        void updateTextPosition(glm::vec2 position, glm::vec2 scale) override;

    private:
        GraphicLib::Textures::Texture::Ptr _texture;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_IMAGEBUTTON_HPP
