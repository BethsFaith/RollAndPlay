//
// Created by VerOchka on 25.10.2023.
//

#include "SystemStartPage.hpp"

namespace Pages {
    SystemStartPage::SystemStartPage(GraphicLib::PickableTexture::Ptr canvas) : _gui(std::move(canvas)) {
        _controller = std::make_shared<Controllers::PageController>();

        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);


        _gui.setTextSize(0.06, 0.15);

        float yOffset = 7.0;
        //кнопочки
        auto button = std::make_shared<Forms::Button>(-8.5, yOffset);
        button->color = Forms::Color::GRAY;
        button->text = "Создать";
        button->setPressCallback([](){
           std::cout << "CREATE" << std::endl;
        });
        _gui.addButton(button, rectangle);
        _controller->addButton(button);

        yOffset -= 1.5;
        button = std::make_shared<Forms::Button>(-8.5, 6.0);
        button->color = Forms::Color::GRAY;
        button->text = "Создать";
        button->setPressCallback([](){
            std::cout << "CREATE" << std::endl;
        });
        _gui.addButton(button, rectangle);
        _controller->addButton(button);
    }

    void SystemStartPage::draw() {
        glDisable(GL_DEPTH_TEST);
        _gui.draw();
        glEnable(GL_DEPTH_TEST);
    }

    Controllers::GLController::Ptr SystemStartPage::getController() {
        return _controller;
    }
}