//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_COLORTECHNIQUE_HPP
#define ROLLANDPLAY_COLORTECHNIQUE_HPP

#include "Technique.hpp"

namespace Graphic::Techniques {
    class ColorTechnique : public Technique {
    public:
        ColorTechnique() = default;
        ~ColorTechnique() override = default;

        void execute() override;

        void setColor(float r, float g, float b);
        void setColor(glm::vec3 rgb);

    private:
        glm::vec3 _rgb;
    };
} // Techniques

#endif //ROLLANDPLAY_COLORTECHNIQUE_HPP
