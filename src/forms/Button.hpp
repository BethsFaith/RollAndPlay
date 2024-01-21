//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/PickTechnique.hpp>
#include <GraphicLib/Techniques/TextTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <functional>
#include <iostream>
#include <utility>

#include "Color.hpp"
#include "Form.hpp"
#include "TextForm.hpp"

namespace Forms {
    class Button : public Form {
    public:
        using Ptr = std::shared_ptr<Button>;

        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~Button() override = default;

        virtual void init(glm::vec2 scale, glm::vec2 position, const TextForm& text, Color color);

        virtual void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderPick(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader);

        virtual void press();
        virtual void release();

        void setPressCallback(const std::function<void()>& function);
        void setReleaseCallback(const std::function<void()>& function);

        [[nodiscard]] bool isUnderCursor() const;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setUnderCursor(bool isUnderCursor);

        void setTraceColor(Color traceColor);

    protected:
        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, FormType type);

        int id;
        static int IdCounter;
        bool _isUnderCursor = false;

        Color _traceColor = Color::WHITE;

        std::function<void()> _pressCallback{[]() {}};
        std::function<void()> _releaseCallback{[]() {}};

        GraphicLib::Object _object{};
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_BUTTON_HPP
