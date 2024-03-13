//
// Created by BethsFaith on 12.03.2024.
//

#ifndef INC_1_BIN_ITEM_HPP
#define INC_1_BIN_ITEM_HPP

#include "BaseData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class Item : public BaseData {
    public:
        using Ptr = std::shared_ptr<Item>;

        ~Item() override = default;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        Type getType() override;

        void clear();

        void setName(const std::u16string& name);
        void setDescription(const std::u16string& description);
        void setIconPath(const std::string& iconPath);
        void setTypeId(unsigned int typeId);
        void setUserId(unsigned int userId);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::u16string& getDescription() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] unsigned int getTypeId() const;
        [[nodiscard]] unsigned int getUserId() const;

    private:
        std::u16string _name;
        std::u16string _description;
        std::string _iconPath;

        unsigned int _typeId = NULL_ID;
        unsigned int _userId = NULL_ID;
    };
}    //namespace Data

#endif    //INC_1_BIN_ITEM_HPP
