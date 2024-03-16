//
// Created by BethsFaith on 12.03.2024.
//

#ifndef INC_1_BIN_ITEMPAGE_HPP
#define INC_1_BIN_ITEMPAGE_HPP

#include <stack>

#include "BasePage.hpp"
#include "style/Constants.hpp"

namespace Pages {
    class ItemPage : public BasePage {
    public:
        enum StateTag {
            START,
            CREATE_ITEM,
            VIEW_ITEM,
            EDIT_ITEM,
            CREATE_ITEM_TYPE,
            VIEW_ITEM_TYPE,
            EDIT_ITEM_TYPE,
            CHOOSE_ITEM_TYPE,
        };

        struct Buffer {
            Data::Item::Ptr item;
            Data::ItemType::Ptr itemType;
            std::multimap<int, Data::Item::Ptr> itemsByTypeId;
        };

        explicit ItemPage(const GraphicLib::Objects::PickableTexture::Ptr& canvas,
                          const GraphicLib::GuiObjects::WidgetBuilder::Ptr& builder);
        ~ItemPage() override = default;

        void init(const glm::vec2& screenOffset) override;

        void update() override;

    private:
        void toStart();
        void toItemCreating();
        void toItemViewing();
        void toItemEditing();
        void toItemTypeChoice();
        void toItemTypeCreating();
        void toItemTypeViewing();
        void toItemTypeEditing();

        static bool checkItemInput(const std::u16string& name,
                            const std::u16string& description,
                            const std::string& path,
                            const GraphicLib::GuiObjects::TextBox::Ptr& errorBox);
        static bool checkTypeInput(const std::u16string& name,
                                   const std::string& path,
                                   const GraphicLib::GuiObjects::TextBox::Ptr& errorBox);

        std::stack<StateTag> _tags;
        Buffer _buffer;
    };
}

#endif    //INC_1_BIN_ITEMPAGE_HPP
