//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_BASEPAGE_HPP
#define ROLLANDPLAY_BASEPAGE_HPP

#include <utility>

#include "APage.hpp"
#include "../Gui.hpp"
#include "../controllers/CommonController.hpp"

namespace Pages {
    class BasePage : public APage {
    public:
        explicit BasePage(GraphicLib::PickableTexture::Ptr canvas);
        ~BasePage() override = default;

        Controllers::GLController::Ptr getController() override;

        void draw() override;

    protected:
        virtual void update();
        void addButton(const Forms::Button::Ptr& button);

    private:
        Controllers::CommonController::Ptr _controller;
        Gui _gui;
    };
}

#endif //ROLLANDPLAY_BASEPAGE_HPP
