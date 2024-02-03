//
// Created by VerOchka on 22.01.2024.
//

#include "ViewDrawer.hpp"

#include <utility>

ViewDrawer::ViewDrawer(GraphicLib::PickableTexture::Ptr canvas, GraphicLib::Shaders::ShaderProgram::Ptr shader) :
      _gui(std::move(canvas)), _shader(std::move(shader)) {}

void ViewDrawer::init(int x, int y, Widgets::Styles::Color viewColor) {
    using namespace GraphicLib;

    auto rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    _view.setPrimitive(rectangle);

    auto colorTechnique = std::make_shared<Techniques::ColorTechnique>();
    colorTechnique->setColor( Widgets::Styles::getRGB(viewColor));
    _view.addTechnique(Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(1.80, 1.65, 0.0f));
    transformTechnique->enableTransform(glm::vec3(x, y, 0.0f));
    _view.addTechnique(Techniques::TRANSFORM, transformTechnique);

    _verticalMenu = std::make_shared<Widgets::MenuBar>(glm::vec2{-0.95, 0.76},
                                                       glm::vec2{0.09f, 0.1f}, false);
    _horizontalMenu = std::make_shared<Widgets::MenuBar>(glm::vec2{-0.8f, 0.9f},
                                                         glm::vec2{0.2f, 0.1f});
}

void ViewDrawer::draw() {
    _view.render(_shader);

    _gui.draw();
//    if (_page != nullptr) {
//        _page->draw();
//    }
}

void ViewDrawer::createHorizontalMenu(int menuId, std::vector<std::u16string> names,
                                             std::vector<std::function<void()>> funcs) {
    using namespace GraphicLib;
    Primitives::AbstractPrimitive::Ptr rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    std::vector<Widgets::Button::Ptr> buttons;
    for (int i{}; i < names.size(); ++i) {
        auto button = std::make_shared<Widgets::Button>(rectangle);

        button->setColor(Widgets::Styles::Color::LIGHT_BLUE);
        button->setLabelText(names.at(i));
        button->setPressCallback(funcs[i]);

        buttons.push_back(button);
    }
    _horizontalMenuButtons[menuId] = buttons;
}

void ViewDrawer::createVerticalMenu(std::vector<std::u16string> names,
                                           std::vector<std::function<void()>> funcs) {
    using namespace GraphicLib;
    Primitives::AbstractPrimitive::Ptr rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    for (int i{}; i < names.size(); ++i) {
        auto button = std::make_shared<Widgets::Button>(rectangle);

        button->setColor(Widgets::Styles::Color::GRAY);
        button->setLabelText(names.at(i));
        button->setPressCallback(funcs[i]);

        _verticalMenu->addElement(button);
    }

    _gui.addWidget(_verticalMenu);
}

void ViewDrawer::showHorizontalMenu(int menuId) {
    _gui.clear();
    _horizontalMenu->clear();

    auto buttons = _horizontalMenuButtons[menuId];
    for (const auto& button : buttons) {
        _horizontalMenu->addElement(button);
    }

    _gui.addWidget(_horizontalMenu);
    _gui.addWidget(_verticalMenu);
}

Controllers::GuiController::Ptr ViewDrawer::getController() {
    return _gui.getController();
}

//void ViewDrawer::setPage(const Pages::APage::Ptr& page) {
//    _page = page;
//}
