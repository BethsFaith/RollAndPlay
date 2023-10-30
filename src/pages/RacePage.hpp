//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_RACEPAGE_HPP
#define ROLLANDPLAY_RACEPAGE_HPP

#include "BasePage.hpp"
#include <GraphicLib/Primitives/Rectangle.hpp>

namespace Pages {
    class RacePage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<RacePage>;

        explicit RacePage(GraphicLib::PickableTexture::Ptr
        canvas);
        ~RacePage() override = default;

    private:
        void update() override;

        void toStart();

        void toView();

        StateTag _currentTag = START;
    };
}


#endif //ROLLANDPLAY_RACEPAGE_HPP
