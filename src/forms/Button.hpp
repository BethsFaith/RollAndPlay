//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <iostream>
#include <functional>
#include <utility>

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/PickTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <GraphicLib/Techniques/TextTechnique.hpp>

#include "Form.hpp"
#include "Color.hpp"
#include "Text.hpp"

namespace Forms {
    class Button : public Form {
    public:
        using Ptr = std::shared_ptr<Button>;

        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~Button() override = default;

        void init(glm::vec3 scale, glm::vec2 position, const Text &text, Color color = Color::GRAY);

        virtual void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderPick(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        virtual void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader);

        void press();

        void setPressCallback(const std::function<void()> &function);

        [[nodiscard]] bool isSelected() const;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setSelected(bool isSelected);

        void setTraceColor(Color traceColor);

    protected:
        explicit Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, FormType type);

        int id;
        static int IdCounter;
        bool _isSelected = false;

        Color _color;
        Color _traceColor = Color::WHITE;

        std::function<void()> _pressCallback{[]() {}};

        GraphicLib::Object _object{};
    };
}

#endif //ROLLANDPLAY_BUTTON_HPP
