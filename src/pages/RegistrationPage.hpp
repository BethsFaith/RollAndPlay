//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"

namespace Pages {
    class RegistrationPage : public BasePage {
    public:
        enum StateTag {
            CREATE,
            VIEW,
        };

        using Ptr = std::shared_ptr<RegistrationPage>;

        explicit RegistrationPage(const GraphicLib::PickableTexture::Ptr &canvas);
        ~RegistrationPage() override = default;

    private:
        void update() override;
        void toCreate();
        void toView();

        StateTag _currentTag = CREATE;
    };
}

#endif //ROLLANDPLAY_REGISTRATIONPAGE_HPP
