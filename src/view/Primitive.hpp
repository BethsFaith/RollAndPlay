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
#include "buffers/Vao.hpp"
#include "buffers/Vertex.hpp"

namespace View {
    class Primitive : public AbstractPrimitive{
    public:
        struct Settings {
            bool with_normals = true;
            bool with_texture_coords = true;
            bool with_tangent = true;
            bool with_bitangent = true;
        };

        explicit Primitive(const int& vertex_number);
        explicit Primitive(const int& vertex_number, const Settings &settings_);
        ~Primitive() override = default;

        void bind() override;
        void unbind() override;

        void bindData(const unsigned int& bind_flag) override;

        void draw() override;

        [[nodiscard]] unsigned int getUid() const override;

    protected:
        void add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer);

        std::vector<std::shared_ptr<Buffers::RaiiBuffer>> buffers{};

        const int vertex_number;

        Settings settings;

    private:
        std::shared_ptr<Buffers::VAO> _vao;
    };
}


#endif //ROLLANDPLAY_PRIMITIVE_HPP
