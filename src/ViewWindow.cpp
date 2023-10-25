//
// Created by VerOchka on 25.10.2023.
//

#include "ViewWindow.hpp"

ViewWindow::ViewWindow(int x, int y, Forms::Color viewColor) {
    using namespace GraphicLib;

    _shader = std::make_shared<Shaders::ShaderProgram>(R"(..\..\rsrc\shaders\gui.vert)",
                                                       R"(..\..\rsrc\shaders\gui.frag)");

    Primitives::AbstractPrimitive::Ptr rectangle =
            std::make_shared<Primitives::Rectangle>(
                    Primitives::Primitive::Settings{.with_normals = false,
                            .with_texture_coords = false,
                            .with_tangent = false,
                            .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    _view.setPrimitive(rectangle);

    auto colorTechnique = std::make_shared<Graphic::Techniques::ColorTechnique>();
    colorTechnique->setColor(Forms::getRGB(viewColor));
    _view.addTechnique(Graphic::Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<Graphic::Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(1.85, 1.5, 0.0f));
    transformTechnique->enableTransform(glm::vec3(x,
                                                  y, 0.0f));
    _view.addTechnique(Graphic::Techniques::TRANSFORM, transformTechnique);
}

void ViewWindow::display() {
    _view.render(_shader);
}
