//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

#include <utility>

namespace Pages {
    BasePage::BasePage(GraphicLib::PickableTexture::Ptr canvas)
    : _gui(std::move(canvas)){
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

    void BasePage::addForm(const Forms::Form::Ptr& form) {
        _gui.addForm(form);
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    void BasePage::init(const glm::vec2 &screenOffset) {
        ScreenOffset = screenOffset;
    }

    void BasePage::setNetConfig(Pages::NetConfig netConfig) {
        Net = std::move(netConfig);
    }
}