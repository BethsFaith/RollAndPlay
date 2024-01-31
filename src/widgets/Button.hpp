//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <functional>
#include <iostream>
#include <utility>

#include "Color.hpp"
#include "TextData.hpp"
#include "Widget.hpp"
#include "graphic/PickableForm.hpp"

namespace Widgets {
    class Button : public Widget {
    public:
        using Ptr = std::shared_ptr<Button>;

        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~Button() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                   GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                   GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;

        glm::vec2 getPosition() override;
        glm::vec2 getScale() override;

        virtual void press();
        virtual void release();

        [[nodiscard]] bool isUnderCursor() const;
        [[nodiscard]] bool checkId(int id_) const;

        void setPressCallback(const std::function<void()>& function);
        void setReleaseCallback(const std::function<void()>& function);

        void setUnderCursor(bool isUnderCursor);

        virtual void setTextLabel(const TextData& text);
        virtual void setTextLabelPosition(glm::vec2 position, glm::vec2 scale);
        virtual void setColor(Color color);
        virtual void setTraceColor(Color traceColor);

        std::u16string getTextLabelContent();
        glm::vec2 getTextLabelPosition();
        void setScale(glm::vec2 scale) override;

    protected:
        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, WidgetType type);

        int id;
        static int IdCounter;
        bool _isUnderCursor = false;

        std::function<void()> _pressCallback{[]() {}};
        std::function<void()> _releaseCallback{[]() {}};

        Graphic::PickableForm _form;
        Graphic::Form _tracing;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_BUTTON_HPP
