//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_APAGE_HPP
#define ROLLANDPLAY_APAGE_HPP

#include <iostream>

#include <GraphicLib/PickableTexture.hpp>

#include "../controllers/GLController.hpp"

namespace Pages {
    class APage {
    public:
        using Ptr = std::shared_ptr<APage>;

        APage() = default;

        virtual ~APage() = default;

        virtual void draw() = 0;

        virtual Controllers::GLController::Ptr getController() = 0;
    };
}

#endif //ROLLANDPLAY_APAGE_HPP
