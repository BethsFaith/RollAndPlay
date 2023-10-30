//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

namespace Pages {
    BasePage::BasePage(GraphicLib::PickableTexture::Ptr canvas) : _gui(std::move(canvas)) {
        _controller = std::make_shared<Controllers::CommonController>();
    }

    void BasePage::update() {
        _controller->clear();
        _gui.clear();
        _controller->addSubController(_gui.getController());
    }

    Controllers::GLController::Ptr BasePage::getController() {
        return _controller;
    }

    void BasePage::addButton(const Forms::Button::Ptr& button) {
        _gui.addButton(button);
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }
}