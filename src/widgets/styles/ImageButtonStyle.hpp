//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_IMAGEBUTTONSTYLE_HPP
#define ROLLANDPLAY_IMAGEBUTTONSTYLE_HPP

#include "ButtonStyle.hpp"

namespace Widgets::Styles {
    struct ImageButtonStyle : public ButtonStyle {
        using Ptr = std::shared_ptr<ImageButtonStyle>;

        ImageButtonStyle() = default;
        ~ImageButtonStyle() override = default;

        std::string defaultTexturePath;
        int defaultTextureIndex = 0;
    };
}

#endif    //ROLLANDPLAY_IMAGEBUTTONSTYLE_HPP
