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
        };
        struct Buffer {
            Data::Skill::Ptr skill;
            Data::SkillCategory::Ptr category;
        };

        explicit SkillPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~SkillPage() override = default;

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

        void updateLists();

        Net::HttpSession::Result postCategory();
        Net::HttpSession::Result postSkills();

        Net::HttpSession::Result pullCategories();
        Net::HttpSession::Result pullSkills();

        Net::HttpSession::Result updateCategory();
        Net::HttpSession::Result updateSkill();

        std::vector<Widgets::ImageButton::Ptr> createCategoryButtons();
        std::vector<Widgets::ImageButton::Ptr> createSkillButtons();

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

        std::condition_variable _cv;
        std::shared_ptr<std::mutex> _mutex;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
