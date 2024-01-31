//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_MENUBAR_HPP
#define ROLLANDPLAY_MENUBAR_HPP

#include "Button.hpp"

namespace Widgets {
    class MenuBar : public Widget {
    public:
        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;
        using Ptr = std::shared_ptr<MenuBar>;

        explicit MenuBar(glm::vec2 position, glm::vec2 scale, bool horizontal = true);
        ~MenuBar() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;

        void addElement(const Button::Ptr& element);

        void removeElement(const Button::Ptr& element);

        bool contains(const Button::Ptr& element);

        void clear();
        [[nodiscard]] const std::vector<Button::Ptr>& getElements() const;
        void setScale(glm::vec2 scale) override;

    private:
        glm::vec2 _position;
        glm::vec2 _scale;
        bool _horizontal;

        std::vector<Button::Ptr> _elements;
    };
}

#endif    //ROLLANDPLAY_MENUBAR_HPP
