//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMSTARTPAGE_HPP
#define ROLLANDPLAY_SYSTEMSTARTPAGE_HPP

#include <primitives/Rectangle.hpp>
#include <utility>

#include "Page.hpp"
#include "../Gui.hpp"
#include "../controllers/PageController.hpp"

namespace Pages {
    class SystemStartPage : public Page{
    public:
        using Ptr = std::shared_ptr<SystemStartPage>;

        explicit SystemStartPage(GraphicLib::PickableTexture::Ptr canvas);
        ~SystemStartPage() override = default;

        void draw() override;

        Controllers::GLController::Ptr getController() override;

    private:
        Gui _gui;
        Controllers::PageController::Ptr _controller;
    };
}

#endif //ROLLANDPLAY_SYSTEMSTARTPAGE_HPP
