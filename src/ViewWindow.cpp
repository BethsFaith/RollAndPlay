//
// Created by VerOchka on 25.10.2023.
//

#include "ViewWindow.hpp"

ViewWindow::ViewWindow(int x, int y, Forms::Color viewColor, const GraphicLib::PickableTexture::Ptr &canvas)
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

    // кнопки
    float startOffset = -8.7f;
    std::vector<Forms::Button::Ptr> buttons;
    std::vector<std::string> names = {
            "Система", "Навыки", "Классы", "Расы", "Экспорт"
    };

    for (int i{}; i < 5; ++i) {
        auto button = std::make_shared<Forms::Button>(rectangle);

        float textX = 0.05f + 0.065f * (float)buttons.size();

        button->init({0.1f, 0.1f, 0.0f}, {startOffset, 9.0f},
                     {.content = names.at(i),
                             .x = textX,
                             .y = 0.05
                     }, Forms::Color::LIGHT_BLUE);

        _gui.addButton(button);

        buttons.push_back(button);

        startOffset += 1.3;
    }
    buttons[0]->setPressCallback([&]() {
        std::cout << "1PRESS" << std::endl;
        _currentPageTag = PageTag::SYSTEM_START;
        updateControllers();
    });
    buttons[1]->setPressCallback([&]() {
        std::cout << "2PRESS" << std::endl;
    });
    buttons[2]->setPressCallback([&]() {
        std::cout << "3PRESS" << std::endl;
    });
    buttons[3]->setPressCallback([&]() {
        std::cout << "4PRESS" << std::endl;
    });
    buttons[4]->setPressCallback([&]() {
        std::cout << "5PRESS" << std::endl;
    });

    // маленькое окно для вида
    _view.setPrimitive(rectangle);

    auto colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
    colorTechnique->setColor(Forms::getRGB(viewColor));
    _view.addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(1.85, 1.65, 0.0f));
    transformTechnique->enableTransform(glm::vec3(x,
                                                  y, 0.0f));
    _view.addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

    updateControllers();
}

ViewWindow::~ViewWindow() {
    _controller.clear();
}

void ViewWindow::display() {
    _view.render(_shader);
    _gui.draw();

    if (_pages.contains(_currentPageTag)) {
        _pages[_currentPageTag]->draw();
    }
}

void ViewWindow::updateControllers() {
    _controller.clear();
    if (_pages.contains(_currentPageTag)) {
        _controller.addSubController(_pages[_currentPageTag]->getController());
    }
    _controller.addSubController(_gui.getController());
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

void ViewWindow::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {
    _controller.processCharMods(window, codepoint, mods);
}

void ViewWindow::addPage(ViewWindow::PageTag tag, Pages::Page::Ptr page) {
    _pages[tag] = std::move(page);
}
