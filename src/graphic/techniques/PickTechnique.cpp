//
// Created by VerOchka on 23.10.2023.
//

#include "PickTechnique.hpp"

namespace Graphic::Techniques {
    void PickTechnique::setId(const std::string &name, float id) {
        shader->setFloat(name, id);
    }

    void PickTechnique::setDrawId(float drawId) {
        _drawId = drawId;
    }

    void PickTechnique::setObjectId(float objectId) {
        _objectId = objectId;
    }

    void PickTechnique::execute() {
        setId("gDrawIndex", _drawId);
        setId("gObjectIndex", _objectId);
    }
}