//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTDATA_HPP
#define ROLLANDPLAY_TEXTDATA_HPP

#include <iostream>

#include "Color.hpp"

namespace Widgets {
    struct TextData {
        std::u16string content;
        Color color = Color::WHITE;
    };
}

#endif    //ROLLANDPLAY_TEXTDATA_HPP
