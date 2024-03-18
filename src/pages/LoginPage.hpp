//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include "BasePage.hpp"
#include "../data/User.hpp"
#include "style/Constants.hpp"

namespace Pages {
    class LoginPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW,
            EDIT,
        };

        using Ptr = std::shared_ptr<LoginPage>;

        explicit LoginPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~LoginPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toStart();
        void toView();
        void toEdit();

        static bool validate(const std::u16string& login,
                      const std::u16string& password,
                      const GraphicLib::GuiObjects::TextBox::Ptr& errorBox);
        static bool validate(const std::u16string& login,
                      const std::u16string& password,
                      const std::u16string& nickname,
                      const GraphicLib::GuiObjects::TextBox::Ptr& errorBox);

        Net::ApiClient::Result logIn(const std::u16string& login, const std::u16string& password);
        Net::ApiClient::Result pullUserData();
        Net::ApiClient::Result changeUserData(const std::u16string& login,
                                                const std::u16string& password,
                                                const std::u16string& nickname);

        static void showResultError(Net::ApiClient::Result& result, const GraphicLib::GuiObjects::TextBox::Ptr& errorBox);

        StateTag _nextState = START;

        Data::User _user{};
        std::u16string _loginMessage;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_LOGINPAGE_HPP
