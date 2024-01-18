//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include "../net/ApiClient.hpp"

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../data/User.hpp"
#include "../forms/TextBox.hpp"

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

        void init(const glm::vec2 &screenOffset) override;

    private:
        void update() override;
        void toCreate();
        void toView();

        StateTag _currentTag = CREATE;

        Forms::Button::Ptr _saveButton;
        Forms::InputField::Ptr _loginInputField;
        Forms::InputField::Ptr _passwordInputField;
        Forms::InputField::Ptr _repeatedPasswordInputField;
        Forms::TextBox::Ptr _messageBox;
    };
}

#endif //ROLLANDPLAY_REGISTRATIONPAGE_HPP
