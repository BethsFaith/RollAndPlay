//
// Created by BethsFaith on 12.03.2024.
//

#include "ItemType.hpp"

namespace Data {
    void ItemType::serialize(Json::Value& jsonValue) {
        BaseData::serialize(jsonValue);

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;
    }

    void ItemType::deserialize(const Json::Value& jsonValue) {
        BaseData::deserialize(jsonValue);

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();
        _userId = jsonValue["user_id"].asInt();
    }

    Type ItemType::getType() {
        return ITEM_TYPE;
    }

    void ItemType::setName(const std::u16string& name) {
        _name = name;
    }

    void ItemType::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void ItemType::setUserId(unsigned int userId) {
        _userId = userId;
    }

    const std::u16string& ItemType::getName() const {
        return _name;
    }

    const std::string& ItemType::getIconPath() const {
        return _iconPath;
    }

    unsigned int ItemType::getUserId() const {
        return _userId;
    }

    void ItemType::clear() {
        _userId = NULL_ID;

        _name.clear();
        _iconPath.clear();
    }
}    //namespace Data
