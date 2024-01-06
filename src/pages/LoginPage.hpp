//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"

namespace Pages {
    class LoginPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<LoginPage>;

        explicit LoginPage(const GraphicLib::PickableTexture::Ptr &canvas);
        ~LoginPage() override = default;

    private:
        void update() override;
        void toStart();
        void toView();

        StateTag _currentTag = START;

        std::u16string _outputMessage{};
    };
}

#endif //ROLLANDPLAY_LOGINPAGE_HPP
