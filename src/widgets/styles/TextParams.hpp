//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTPARAMS_HPP
#define ROLLANDPLAY_TEXTPARAMS_HPP

#include <iostream>

#include "Color.hpp"

namespace Widgets::Styles {
    struct TextParams {
        Color color = Color::WHITE;

        float size;
        glm::vec2 position;
    };
}

#endif    //ROLLANDPLAY_TEXTPARAMS_HPP
