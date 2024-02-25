//
// Created by BethsFaith on 28.01.2024.
//

#ifndef ROLLANDPLAY_FORM_HPP
#define ROLLANDPLAY_FORM_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/PickTechnique.hpp>
#include <GraphicLib/Techniques/TextTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <GraphicLib/Techniques/TextureTechnique.hpp>

#include <GraphicLib/PickableTexture.hpp>

namespace Widgets::Graphic {
    class Form {
    public:
        using Ptr = std::shared_ptr<Form>;

        explicit Form(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);

        virtual void setProjection(float minX, float maxX, float minY, float maxY);
        virtual void setTransform(glm::vec2 position, glm::vec2 scale);
        virtual void setTransform(glm::vec2 position);
        virtual void setScale(glm::vec2 scale);
        virtual void setText(std::u16string content);
        virtual void setText(std::u16string content, glm::vec3 color);
        virtual void setTextPosition(glm::vec2 position);
        virtual void setTextSize(float scale);
        virtual void setTextColor(glm::vec3 color);
        virtual void setColor(glm::vec3 color);
        virtual void setTexture(GraphicLib::Textures::Texture::Ptr, int textureIndex);

        glm::vec2 getScale();
        glm::vec2 getPosition();
        std::u16string getText();
        glm::vec2 getTextPosition();
        float getTextScale();
        glm::vec3 getTextColor();
        glm::vec3 getColor();
        GraphicLib::Textures::Texture::Ptr getTexture();

        virtual void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader);

    protected:
        GraphicLib::Object _object{};
    };
}    //namespace Widgets::Graphic

#endif    //ROLLANDPLAY_FORM_HPP
