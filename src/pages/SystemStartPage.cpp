//
// Created by VerOchka on 25.10.2023.
//

#include "SystemStartPage.hpp"

namespace Pages {
    SystemStartPage::SystemStartPage(GraphicLib::PickableTexture::Ptr canvas) : _gui(std::move(canvas)) {
        _controller = std::make_shared<Controllers::CommonController>();

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
        _controller->addSubController(_gui.getController());

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
        auto button = std::make_shared<Forms::Button>(rectangle);
        button->init({0.1, 0.1f, 0.0f}, {-8.5, 7.0}, {
            .content =  "Создать",
            .x = 0.06,
            .y = 0.15
        });
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::VIEW;
            this->update();
        });

        _gui.addButton(button);
    }

    void SystemStartPage::toView() {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        //кнопочки
        auto button = std::make_shared<Forms::Button>(rectangle);
        button->init({0.1, 0.1f, 0.0f}, {-8.5, 7.0}, {
                .content =  "Сохранить",
                .x = 0.055,
                .y = 0.15
        });
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::START;
            this->update();
        });

        _gui.addButton(button);

        auto inputButton = std::make_shared<Forms::InputField>(rectangle);
        inputButton->init({0.7f, 0.1f, 0.0f}, { -0.79, 4.0}, {
            .content = "Название",
            .x = 0.055,
            .y = 0.25
        }, Forms::Color::LIGHT_GRAY);

        _gui.addButton(inputButton);
    }
}