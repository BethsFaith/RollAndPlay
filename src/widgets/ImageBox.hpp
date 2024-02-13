//
// Created by BethsFaith on 08.02.2024.
//

#ifndef INC_1_BIN_IMAGEBOX_HPP
#define INC_1_BIN_IMAGEBOX_HPP

#include <GraphicLib/Textures/Loader.hpp>
#include <GraphicLib/Textures/Texture.hpp>

#include "Widget.hpp"
#include "graphic/Form.hpp"

namespace Widgets {
    class ImageBox : public Widget {
    public:
        using Ptr = std::shared_ptr<ImageBox>;

        explicit ImageBox(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~ImageBox() override = default;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        void setProjection(float minX, float maxX, float minY, float maxY) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        void setImage(const std::string& texturePath, int textureIndex);

        [[nodiscard]] const GraphicLib::Textures::Texture::Ptr& getTexture() const;

    private:
        Graphic::Form _form;

        GraphicLib::Textures::Texture::Ptr _texture;
    };

}    //namespace Widgets

#endif    //INC_1_BIN_IMAGEBOX_HPP
