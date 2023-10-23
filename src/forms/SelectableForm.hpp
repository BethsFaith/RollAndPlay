//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_SELECTABLEFORM_HPP
#define ROLLANDPLAY_SELECTABLEFORM_HPP

#include <PickableTexture.hpp>

namespace Forms {
    class SelectableForm {
    public:
        SelectableForm() = default;
        ~SelectableForm() = default;

        virtual bool checkSelecting(unsigned int x, unsigned int y) = 0;

        void setCanvas(const GraphicLib::PickableTexture::Ptr &canvas);
    protected:
        GraphicLib::PickableTexture::Ptr canvas;
    };
}


#endif //ROLLANDPLAY_SELECTABLEFORM_HPP
