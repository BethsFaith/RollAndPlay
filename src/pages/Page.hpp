//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_PAGE_HPP
#define ROLLANDPLAY_PAGE_HPP

#include <iostream>

#include "../../libs/graphicLib/headers/GraphicLib/PickableTexture.hpp"

#include "../controllers/GLController.hpp"

namespace Pages {
    class Page {
    public:
        using Ptr = std::shared_ptr<Page>;

        Page() = default;

        virtual ~Page() = default;

        virtual void draw() = 0;

        virtual Controllers::GLController::Ptr getController() = 0;
    };
}

#endif //ROLLANDPLAY_PAGE_HPP
