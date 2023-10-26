//
// Created by VerOchka on 26.10.2023.
//

#include "TracingTechnique.hpp"

namespace GraphicLib::Techniques {
    void TracingTechnique::execute() {

    }

    void TracingTechnique::setTransform(const Technique::Ptr &transform) {
        _transform = transform;
    }
}
