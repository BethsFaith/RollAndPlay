//
// Created by VerOchka on 25.10.2023.
//

#include "ViewWindow.hpp"

ViewWindow::ViewWindow(int x, int y, Forms::Color viewColor, const GraphicLib::PickableTexture::Ptr& canvas)
: _gui(canvas) {
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

    float startOffset = -8.7f;
    std::vector<Forms::Button::Ptr> buttons;
    std::vector<std::string> names = {
            "Система", "Навыки", "Классы", "Расы", "Экспорт"
    };

    _gui.setTextSize(0.05, 0.05);
    for (int i{}; i < 5; ++i) {
        auto button = std::make_shared<Forms::Button>(startOffset,9.0f);

        button->color = Forms::Color::LIGHT_BLUE;

        button->text = names.at(i);
        _gui.addButton(button, rectangle);
        _controller.addButton(button);
        buttons.push_back(button);

        startOffset += 1.3;
    }
    buttons[0]->setPressCallback([&](){
        std::cout << "1PRESS" << std::endl;
        _currentPageTag = PageTag::SYSTEM_START;
    });
    buttons[1]->setPressCallback([&](){
        std::cout << "2PRESS" << std::endl;
    });
    buttons[2]->setPressCallback([&](){
        std::cout << "3PRESS" << std::endl;
    });
    buttons[3]->setPressCallback([&](){
        std::cout << "4PRESS" << std::endl;
    });
    buttons[4]->setPressCallback([&](){
        std::cout << "5PRESS" << std::endl;
    });

    _view.setPrimitive(rectangle);

    auto colorTechnique = std::make_shared<Graphic::Techniques::ColorTechnique>();
    colorTechnique->setColor(Forms::getRGB(viewColor));
    _view.addTechnique(Graphic::Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<Graphic::Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(1.85, 1.65, 0.0f));
    transformTechnique->enableTransform(glm::vec3(x,
                                                  y, 0.0f));
    _view.addTechnique(Graphic::Techniques::TRANSFORM, transformTechnique);
}

void ViewWindow::display() {
    _gui.draw();

    _view.render(_shader);
    _pages[_currentPageTag]->draw();
}

void ViewWindow::processKeyboardInput(GLFWwindow *window) {
    _controller.processKeyboardInput(window);
}

void ViewWindow::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
    _controller.processMouseButton(window, mouseButton, action, mods);
}

void ViewWindow::processMouseCursor(GLFWwindow *window, double x_pos, double y_pos) {
    _controller.processMouseCursor(window, x_pos, y_pos);
}

void ViewWindow::processMouseScroll(GLFWwindow *window, double x_offset, double y_offset) {
    _controller.processMouseCursor(window, x_offset, y_offset);
}

ViewWindow::~ViewWindow() {
    _controller.clear();
}

void ViewWindow::addPage(ViewWindow::PageTag tag, Pages::Page::Ptr page) {
    _pages[tag] = std::move(page);
    _controller.setViewController(_pages[tag]->getController()); // убрать
}
