//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMSTARTPAGE_HPP
#define ROLLANDPLAY_SYSTEMSTARTPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "Page.hpp"
#include "../Gui.hpp"
#include "../controllers/PageController.hpp"
#include "../controllers/InputFieldController.hpp"
#include "../forms/InputField.hpp"

namespace Pages {
    class SystemStartPage : public Page {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<SystemStartPage>;

        explicit SystemStartPage(GraphicLib::PickableTexture::Ptr canvas);

        ~SystemStartPage() override = default;

        void draw() override;

        Controllers::GLController::Ptr getController() override;

    private:
        void update();

        void toStart();

        void toView();

        StateTag _currentTag = START;
        Gui _gui;
        Controllers::PageController::Ptr _controller;
    };
}

#endif //ROLLANDPLAY_SYSTEMSTARTPAGE_HPP
