//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMPAGE_HPP
#define ROLLANDPLAY_SYSTEMPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "BasePage.hpp"
#include "../data/System.hpp"

namespace Pages {
    class SystemPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<SystemPage>;

        explicit SystemPage(GraphicLib::PickableTexture::Ptr canvas);
        ~SystemPage() override = default;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Data::System _system;
    };
}

#endif //ROLLANDPLAY_SYSTEMPAGE_HPP
