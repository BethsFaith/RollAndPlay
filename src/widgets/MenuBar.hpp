//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_MENUBAR_HPP
#define ROLLANDPLAY_MENUBAR_HPP

#include "Button.hpp"

namespace Widgets {
    class MenuBar : public Widget {
    public:
        using Ptr = std::shared_ptr<MenuBar>;

        explicit MenuBar(glm::vec2 position, glm::vec2 scale, bool horizontal = true);
        ~MenuBar() override = default;
        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;
        glm::vec2 getScale() override;

        glm::vec2 getPosition() override;
        void addElement(const Button::Ptr& element);

        void removeElement(const Button::Ptr& element);
        bool contains(const Button::Ptr& element);
        void update();
        void clear();

        void setSelectedItemColor(const glm::vec3& color);
        void setSelectedItemColor(const Styles::Color& color);

        [[nodiscard]] const std::vector<Button::Ptr>& getElements() const;
        [[nodiscard]] const glm::vec3& getSelectedItemColor() const;
        void setProjection(float minX, float maxX, float minY, float maxY) override;

    private:
        glm::vec2 _position;
        glm::vec2 _scale;
        glm::vec3 _selectedItemColor;
        glm::vec3 _color;

        bool _horizontal;
        float _elemOffset = 0.01f;
        float _minX = -1;
        float _minY = -1;
        float _maxX = 1;
        float _maxY = 1;

        std::vector<Button::Ptr> _elements;
        std::weak_ptr<Widgets::Button> _activeElement;
    };
}

#endif    //ROLLANDPLAY_MENUBAR_HPP
