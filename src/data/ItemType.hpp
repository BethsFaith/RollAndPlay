//
// Created by BethsFaith on 12.03.2024.
//

#ifndef INC_1_BIN_ITEMTYPE_HPP
#define INC_1_BIN_ITEMTYPE_HPP

#include "BaseData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class ItemType : public BaseData {
    public:
        using Ptr = std::shared_ptr<ItemType>;

        ~ItemType() override = default;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        Type getType() override;

        void clear();

        void setName(const std::u16string& name);
        void setIconPath(const std::string& iconPath);
        void setUserId(unsigned int userId);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] unsigned int getUserId() const;

    private:
        std::u16string _name;
        std::string _iconPath;

        unsigned int _userId = NULL_ID;
    };
}    //namespace Data

#endif    //INC_1_BIN_ITEMTYPE_HPP
