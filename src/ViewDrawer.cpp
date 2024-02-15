//
// Created by VerOchka on 22.01.2024.
//

#include "ViewDrawer.hpp"

#include <utility>

ViewDrawer::ViewDrawer(GraphicLib::PickableTexture::Ptr canvas) :
      _gui(std::move(canvas)) {
    using namespace GraphicLib;

    auto rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    _verticalMenu = std::make_shared<Widgets::MenuBar>(glm::vec2{-0.95f, 0.77f},
                                                       glm::vec2{0.09f, 0.1f}, false);
    _verticalMenu->setProjection(-1, 1, -1, 1);
    _horizontalMenu = std::make_shared<Widgets::MenuBar>(glm::vec2{-0.8f, 0.9f},
                                                         glm::vec2{0.2f, 0.1f});
    _horizontalMenu->setProjection(-1, 1, -1, 1);

    _verticalMenu->setSelectedItemColor(Widgets::Styles::LIGHT_BLUE);
    _horizontalMenu->setSelectedItemColor(Widgets::Styles::DARK_GRAY);

    _gui.addWidget(_verticalMenu);
    _gui.addWidget(_horizontalMenu);
}

void ViewDrawer::draw(int windowWidth, int windowHeight) {
    _gui.draw();

    auto w = (float)windowWidth/2;
    auto h = (float)windowHeight/2;
    auto xMinPos = w * (1+ _xLine.x);
    auto xMaxPos = w * (1+_xLine.y);
    auto width = xMaxPos - xMinPos;
    auto yMinPos = h * (1+_yLine.x);
    auto yMaxPos = h * (1+_yLine.y);
    auto height = yMaxPos - yMinPos;

    glScissor((int)xMinPos, (int)yMinPos, (int)width, (int)height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);

    glClearColor(_viewBackgroundColor.x, _viewBackgroundColor.y, _viewBackgroundColor.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    if (_page != nullptr) {
        _page->draw();
    }

    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_DEPTH_TEST);
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
}

void ViewDrawer::showHorizontalMenu(int menuId) {
    _horizontalMenu->update();
    _horizontalMenu->clear();

    auto buttons = _horizontalMenuButtons[menuId];
    for (const auto& button : buttons) {
        _horizontalMenu->addElement(button);
    }
}

void ViewDrawer::setPosition(glm::vec2 xLine, glm::vec2 yLine) {
    _xLine = xLine;
    _yLine = yLine;
}

void ViewDrawer::setPage(const Pages::APage::Ptr& page) {
    _page = page;
}

Controllers::GuiController::Ptr ViewDrawer::getController() {
    return _gui.getController();
}

const Pages::APage::Ptr& ViewDrawer::getPage() const {
    return _page;
}

void ViewDrawer::setViewBackgroundColor(const glm::vec3& viewBackgroundColor) {
    _viewBackgroundColor = viewBackgroundColor;
}
