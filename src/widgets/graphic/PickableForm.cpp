//
// Created by BethsFaith on 28.01.2024.
//

#include "PickableForm.hpp"

namespace Widgets::Graphic {

    PickableForm::PickableForm(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive,
                               float identifier) : Form(graphicPrimitive) {

        auto picking = std::make_shared<GraphicLib::Techniques::PickTechnique>();

        picking->setObjectId(identifier);

        _object.addTechnique(GraphicLib::Techniques::PICK, picking);
        _object.disableTechnique(GraphicLib::Techniques::PICK);
    }

    void PickableForm::renderPick(GraphicLib::Shaders::ShaderProgram::Ptr shader,
                                  const GraphicLib::PickableTexture::Ptr& canvas) {
        canvas->enableWriting();

        _object.enableTechnique(GraphicLib::Techniques::PICK);
        _object.enableTechnique(GraphicLib::Techniques::TRANSFORM);

        _object.render(std::move(shader));

        canvas->disableWriting();

        _object.disableTechnique(GraphicLib::Techniques::PICK);
        _object.disableTechnique(GraphicLib::Techniques::TRANSFORM);
    }
}