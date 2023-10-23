//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_TECHNIQUE_HPP
#define ROLLANDPLAY_TECHNIQUE_HPP

#include <utility>
#include <shaders/ShaderProgram.hpp>

namespace Graphic::Techniques {
    class Technique {
    public:
        using Ptr = std::shared_ptr<Technique>;

        Technique() = default;
        virtual ~Technique() = default;

        virtual void execute() = 0;

        void enable();
        void disable();

        [[nodiscard]] bool isEnabled() const;

        void setShader(GraphicLib::Shaders::ShaderProgram::Ptr shaderProgram);

    protected:
        GraphicLib::Shaders::ShaderProgram::Ptr shader;

    private:
        bool enabled = true;
    };
}

#endif //ROLLANDPLAY_TECHNIQUE_HPP
