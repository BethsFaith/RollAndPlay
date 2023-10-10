//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_RECTANGLE_HPP
#define ROLLANDPLAY_RECTANGLE_HPP

#include "Primitive.hpp"
#include "buffers/Vbo.hpp"
#include "buffers/Ebo.hpp"

namespace Graphic {
    class Rectangle : public Primitive{
    public:
        explicit Rectangle(const Primitive::Settings &settings);

        ~Rectangle() override = default;
        void draw() override;

    protected:
        void bindData(const unsigned int& bind_flag) override;

    private:
        static std::vector<glm::vec3> getPosition();
        static std::vector<glm::vec3> getNormals();
        static std::vector<glm::vec2> getTextureCoordinates();
    };
}


#endif //ROLLANDPLAY_RECTANGLE_HPP
