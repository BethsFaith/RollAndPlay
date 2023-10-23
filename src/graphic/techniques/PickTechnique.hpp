//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_PICKTECHNIQUE_HPP
#define ROLLANDPLAY_PICKTECHNIQUE_HPP

#include "Technique.hpp"

namespace Graphic::Techniques  {
    class PickTechnique : public Technique {
    public:
        using Ptr = std::shared_ptr<PickTechnique>;

        PickTechnique() = default;

        void setDrawId(float drawId);
        void setObjectId(float objectId);

        ~PickTechnique() override = default;

        void execute() override;

    private:
        void setId(const std::string& name, float id);

        float _drawId = 0.0f;
        float _objectId = 0.0f;
    };
}

#endif //ROLLANDPLAY_PICKTECHNIQUE_HPP
