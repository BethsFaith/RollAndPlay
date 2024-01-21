//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTFORM_HPP
#define ROLLANDPLAY_TEXTFORM_HPP

#include <iostream>

#include "Color.hpp"

namespace Forms {
    struct TextForm {
        std::u16string content;
        Color color = Color::WHITE;
    };
}

#endif    //ROLLANDPLAY_TEXTFORM_HPP
