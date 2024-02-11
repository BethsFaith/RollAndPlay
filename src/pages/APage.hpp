//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_APAGE_HPP
#define ROLLANDPLAY_APAGE_HPP

#include <GraphicLib/PickableTexture.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "../controllers/GLController.hpp"

namespace Pages {
    class APage {
    public:
        using Ptr = std::shared_ptr<APage>;

        APage() = default;

        virtual ~APage() = default;

        virtual void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) = 0;

        virtual void draw() = 0;

        virtual void update() = 0;

        virtual Controllers::GLController::Ptr getController() = 0;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_APAGE_HPP
