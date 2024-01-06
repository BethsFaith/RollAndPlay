//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_FORM_HPP
#define ROLLANDPLAY_FORM_HPP

#include <GraphicLib/PickableTexture.hpp>

#include "FormType.hpp"

namespace Forms {
    class Form {
    public:
        using Ptr = std::shared_ptr<Form>;

        explicit Form(FormType type);
        virtual ~Form() = default;

        virtual bool checkSelecting(unsigned int x, unsigned int y) = 0;

        void setCanvas(const GraphicLib::PickableTexture::Ptr &canvas);

        [[nodiscard]] FormType getType() const;

    protected:
        GraphicLib::PickableTexture::Ptr canvas;

    private:
        FormType _type;
    };
}


#endif //ROLLANDPLAY_FORM_HPP
