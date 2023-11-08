//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_PRIMITIVE_HPP
#define ROLLANDPLAY_PRIMITIVE_HPP

#include <algorithm>
#include <format>
#include <functional>
#include <vector>

#include "AbstractPrimitive.hpp"
#include "../Buffers/Vao.hpp"
#include "../Buffers/Vertex.hpp"

namespace GraphicLib::Primitives {
    class Primitive : public AbstractPrimitive {
    public:
        using Ptr = std::shared_ptr<Primitive>;

        struct Settings {
            bool with_normals = true;
            bool with_texture_coords = true;
            bool with_tangent = true;
            bool with_bitangent = true;
        };

        explicit Primitive(const int &vertexNumber);

        explicit Primitive(const int &vertexNumber, const Settings &settings_);

        ~Primitive() override = default;

        void bind() override;

        void unbind() override;

        void bindData(const unsigned int &bindFlag) override;

        void draw() override;

        [[nodiscard]] unsigned int getUid() const override;

    protected:
        void add(Buffers::RaiiBuffer::Ptr raiiBuffer);

        std::vector<Buffers::RaiiBuffer::Ptr> buffers{};

        const int vertexNumber;

        Settings settings;

    private:
        Buffers::VAO::Ptr _vao;
    };
}


#endif //ROLLANDPLAY_PRIMITIVE_HPP
