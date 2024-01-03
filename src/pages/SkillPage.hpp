//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include "BasePage.hpp"
#include <GraphicLib/Primitives/Rectangle.hpp>

namespace Pages {
    class SkillPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        explicit SkillPage(GraphicLib::PickableTexture::Ptr canvas);
        ~SkillPage() override = default;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;
    };
}

#endif //ROLLANDPLAY_SKILLPAGE_HPP
