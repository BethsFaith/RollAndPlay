//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TRACINGTECHNIQUE_HPP
#define ROLLANDPLAY_TRACINGTECHNIQUE_HPP

#include "../headers/GraphicLib/Techniques/ColorTechnique.hpp"
#include "../headers/GraphicLib/Techniques/TransformTechnique.hpp"

namespace GraphicLib::Techniques {
    class TracingTechnique : public ColorTechnique {
    public:
        ~TracingTechnique() override = default;

        void execute() override;

        void setTransform(const Ptr &transform);

    private:
        TransformTechnique::Ptr _transform;
    };
}

#endif //ROLLANDPLAY_TRACINGTECHNIQUE_HPP
