//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_RECTANGLE_HPP
#define ROLLANDPLAY_RECTANGLE_HPP

#include "Primitive.hpp"
#include "../Buffers/Vbo.hpp"
#include "../Buffers/Ebo.hpp"

namespace GraphicLib::Primitives {
    class Rectangle : public Primitive {
    public:
        using Ptr = std::shared_ptr<Rectangle>;

        explicit Rectangle(const Primitive::Settings &settings);

        ~Rectangle() override = default;

        void draw() override;

        void bindData(const unsigned int &bindFlag) override;

    private:
        static std::vector<glm::vec3> getPosition();

        static std::vector<glm::vec3> getNormals();

        static std::vector<glm::vec2> getTextureCoordinates();
    };
}

#endif //ROLLANDPLAY_RECTANGLE_HPP
