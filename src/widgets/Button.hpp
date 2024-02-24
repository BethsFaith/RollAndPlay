//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <functional>
#include <iostream>
#include <utility>

#include "Widget.hpp"
#include "graphic/PickableForm.hpp"
#include "styles/Color.hpp"
#include "styles/TextParams.hpp"

namespace Widgets {
    class Button : public Widget {
    public:
        using Ptr = std::shared_ptr<Button>;

        explicit Button(GraphicLib::Primitives::AbstractPrimitive::Ptr graphicPrimitive);
        ~Button() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setProjection(float minX, float maxX, float minY, float maxY) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;

        glm::vec2 getPosition() override;
        glm::vec2 getScale() override;

        virtual void press();
        virtual void release();

        [[nodiscard]] bool isUnderCursor() const;
        [[nodiscard]] bool isPressed() const;

        [[nodiscard]] bool checkId(int id_) const;
        void setPressCallback(const std::function<void()>& function);

        void setReleaseCallback(const std::function<void()>& function);

        void setUnderCursor(bool isUnderCursor);
        virtual void setLabelParams(const Styles::TextParams& text);
        virtual void setLabelText(const std::u16string& text);
        virtual void setLabelPosition(glm::vec2 position);
        virtual void setLabelColor(Styles::Color color);
        virtual void setLabelTextSize(float size);

        virtual void setColor(Styles::Color color);
        virtual void setTraceColor(Styles::Color traceColor);
        virtual void setColor(glm::vec3 color);

        virtual void setTraceColor(glm::vec3 traceColor);
        std::u16string getTextLabelContent();
        glm::vec2 getTextLabelPosition();

        glm::vec3 getColor();
        void setScale(glm::vec2 scale) override;

    protected:
        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, WidgetType type);

        virtual void updateTextPosition(glm::vec2 position, glm::vec2 scale);

        static int IdCounter;

        int id;
        bool _isUnderCursor = false;
        bool _isPressed = false;

        std::function<void()> _pressCallback{[]() {}};
        std::function<void()> _releaseCallback{[]() {}};

        Graphic::PickableForm _form;
        Graphic::Form _tracing;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_BUTTON_HPP
