//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP
#define ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP

#include "Technique.hpp"

namespace GraphicLib::Techniques {
    class TransformTechnique : public Technique {
    public:
        struct Rotate {
            float angle{360.0f};
            glm::vec3 coordinates{0.0f};
        };

        TransformTechnique() = default;
        ~TransformTechnique() override = default;

        void execute() override;

        void enableTransform(const glm::vec3 &transformValue);
        void enableTransform();
        void disableTransform();

        void enableScale(const glm::vec3 &scaleValue);
        void enableScale();
        void disableScale();

        void enableRotateValue(const Rotate &rotateValue);
        void enableRotateValue();
        void disableRotateValue();

        const glm::vec3 &getTransformValue() const;

        const glm::vec3 &getScaleValue() const;

        const Rotate &getRotateValue() const;

    private:
        bool _needRotate = false;
        bool _needScale = false;
        bool _needTransform = false;

        glm::vec3 _transformValue{0.0f};
        glm::vec3 _scaleValue{0.0f};
        Rotate _rotateValue{};
    };

} // Techiques

#endif //ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP
