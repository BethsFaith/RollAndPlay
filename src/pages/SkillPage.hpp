//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include "BasePage.hpp"

namespace Pages {
    class SkillPage : public BasePage {
    public:
        enum StateTag {
            START,
            CREATE_SKILL,
            CREATE_CATEGORY,
            VIEW_SKILL,
            VIEW_CATEGORY,
            EDIT_SKILL,
            EDIT_CATEGORY,
            CATEGORY_CHOICE,
            CHARACTERISTIC_CHOICE,
        };

        struct Buffer {
            Data::Skill::Ptr skill;
            Data::SkillCategory::Ptr category;
            Data::Characteristic::Ptr characteristic;
        };

        explicit SkillPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~SkillPage() override;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toSkillCreate();
        void toCategoryCreate();
        void toSkillView();
        void toCategoryView();
        void toSkillEdit();
        void toCategoryEdit();
        void toCategoryChoice();
        void toCharacteristicChoice();

        void updateLists();

        bool checkInput();

        Net::ApiClient::Result postCategory();
        Net::ApiClient::Result postSkills();

        Net::ApiClient::Result pullAndUpdateCategoryList();
        Net::ApiClient::Result pullAndUpdateSkillList();

        Net::ApiClient::Result updateCategory();
        Net::ApiClient::Result updateSkill();

        static Net::ApiClient::Result pullCategory(int id);
        static Net::ApiClient::Result pullCharacteristic(int id);
        static Net::ApiClient::Result pullSkill(int id);
        static Net::ApiClient::Result pullSkills(int categoryId);

        std::vector<GraphicLib::GuiObjects::ImageButton::Ptr> createCategoryButtons(const std::vector<Data::SkillCategory::Ptr>& categories);
        std::vector<GraphicLib::GuiObjects::ImageButton::Ptr> createSkillButtons(const std::vector<Data::Skill::Ptr>& skills);

        StateTag _currentTag = START;

        Buffer _buf;

        GraphicLib::GuiObjects::HorizontalLayout::Ptr _viewCategoryLayout;
        GraphicLib::GuiObjects::HorizontalLayout::Ptr _viewSkillLayout;

        GraphicLib::GuiObjects::TextInputField::Ptr _nameInputField;
        GraphicLib::GuiObjects::ImageButton::Ptr _iconButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _iconPathInputField;

        GraphicLib::GuiObjects::TextBox::Ptr _messageBox;

        std::vector<Data::SkillCategory::Ptr> _categoryList;
        std::vector<Data::Skill::Ptr> _skillList;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
