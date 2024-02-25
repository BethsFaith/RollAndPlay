//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../widgets/ImageButton.hpp"
#include "../widgets/TextInputField.hpp"

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
        };

        struct Buffer {
            Data::Skill::Ptr skill;
            Data::SkillCategory::Ptr category;
        };

        explicit SkillPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~SkillPage() override;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

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

        void updateLists();

        Net::ApiClient::Result postCategory();
        Net::ApiClient::Result postSkills();

        Net::ApiClient::Result pullAndUpdateCategoryList();
        Net::ApiClient::Result pullAndUpdateSkillList();

        static Net::ApiClient::Result pullCategory(int id);
        static Net::ApiClient::Result pullSkill(int id);
        static Net::ApiClient::Result pullSkills(int categoryId);

        Net::ApiClient::Result updateCategory();
        Net::ApiClient::Result updateSkill();

        std::vector<Widgets::ImageButton::Ptr> createCategoryButtons(const std::vector<Data::SkillCategory::Ptr>& categories);
        std::vector<Widgets::ImageButton::Ptr> createSkillButtons(const std::vector<Data::Skill::Ptr>& skills);

        StateTag _currentTag = START;

        Widgets::HorizontalLayout::Ptr _viewCategoryLayout;
        Widgets::HorizontalLayout::Ptr _viewSkillLayout;

        Widgets::TextInputField::Ptr _nameInputField;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInputField;

        Buffer _buf;
        std::vector<Data::SkillCategory::Ptr> _categoryList;
        std::vector<Data::Skill::Ptr> _skillList;
        std::unique_ptr<std::thread> _updateListsThread;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
