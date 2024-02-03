//
// Created by BethsFaith on 28.01.2024.
//

#ifndef ROLLANDPLAY_PICKABLEFORM_HPP
#define ROLLANDPLAY_PICKABLEFORM_HPP

#include "Form.hpp"

namespace Widgets::Graphic {
    class PickableForm : public Form {
    public:
        using Ptr = std::shared_ptr<PickableForm>;

        PickableForm(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, float identifier);

        void renderPick(GraphicLib::Shaders::ShaderProgram::Ptr shader, const GraphicLib::PickableTexture::Ptr& canvas);
    };
}

#endif    //ROLLANDPLAY_PICKABLEFORM_HPP
