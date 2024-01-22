//
// Created by VerOchka on 22.01.2024.
//

#include "ViewDrawer.hpp"

#include <utility>

ViewDrawer::ViewDrawer(GraphicLib::PickableTexture::Ptr canvas, GraphicLib::Shaders::ShaderProgram::Ptr shader) :
      _gui(std::move(canvas)), _shader(std::move(shader)) {}

void ViewDrawer::init(int x, int y, Widgets::Color viewColor) {
    using namespace GraphicLib;

    auto rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    _view.setPrimitive(rectangle);

    auto colorTechnique = std::make_shared<Techniques::ColorTechnique>();
    colorTechnique->setColor( Widgets::getRGB(viewColor));
    _view.addTechnique(Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(1.80, 1.65, 0.0f));
    transformTechnique->enableTransform(glm::vec3(x, y, 0.0f));
    _view.addTechnique(Techniques::TRANSFORM, transformTechnique);
}

void ViewDrawer::draw() {
    _view.render(_shader);

//    if (_page != nullptr) {
//        _page->draw();
//    }
}

//void ViewDrawer::setPage(const Pages::APage::Ptr& page) {
//    _page = page;
//}
