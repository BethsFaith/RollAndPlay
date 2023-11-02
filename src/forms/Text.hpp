//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXT_HPP
#define ROLLANDPLAY_TEXT_HPP

#include <iostream>

#include "Color.hpp"

namespace Forms {
    struct Text {
        std::u16string content;
        Color color = Color::WHITE;
    };
}

#endif //ROLLANDPLAY_TEXT_HPP
