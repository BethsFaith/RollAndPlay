//
// Created by VerOchka on 25.10.2023.
//

#include "SystemStartPage.hpp"

namespace Pages {
    SystemStartPage::SystemStartPage(GraphicLib::PickableTexture::Ptr canvas) : _gui(std::move(canvas)) {
        _controller = std::make_shared<Controllers::PageController>();

        update();
    }

    void SystemStartPage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    Controllers::GLController::Ptr SystemStartPage::getController() {
        return _controller;
    }

    void SystemStartPage::update() {
        _controller->clear();
        _gui.clear();

        switch (_currentTag) {
            case START:
                toStart();
                break;
            case VIEW:
                toView();
                break;
        }
    }

    void SystemStartPage::toStart() {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);


        //кнопочки
        auto button = std::make_shared<Forms::Button>(-8.5, 7.0);
        button->color = Forms::Color::GRAY;
        button->title = "Создать";
        button->scale = glm::vec3(0.1, 0.1f, 0.0f);
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::VIEW;
            this->update();
        });
        _gui.setTextSize(0.06, 0.15);
        _gui.addButton(button, rectangle);
        _controller->addButton(button);
    }

    void SystemStartPage::toView() {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        _gui.setTextSize(0.055, 0.15);
        //кнопочки
        auto button = std::make_shared<Forms::Button>(-8.5, 7.0);
        button->color = Forms::Color::GRAY;
        button->title = "Сохранить";
        button->scale = glm::vec3(0.1, 0.1f, 0.0f);
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::START;
            this->update();
        });
        _gui.addButton(button, rectangle);
        _controller->addButton(button);

        auto fieldController = std::make_shared<Controllers::InputFieldController>();
        _controller->addController(fieldController);

        auto inputButton = std::make_shared<Forms::InputField>(-0.79, 4.0, "Название");
        inputButton->color = Forms::Color::LIGHT_GRAY;
        inputButton->scale = glm::vec3(0.7f, 0.1f, 0.0f);

        fieldController->addButton(inputButton);
        _gui.setTextSize(0.055, 0.25);
        _gui.addButton(inputButton, rectangle);
    }
}