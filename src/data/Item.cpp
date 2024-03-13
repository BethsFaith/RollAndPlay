//
// Created by BethsFaith on 12.03.2024.
//

#include "Item.hpp"

namespace Data {
    void Item::serialize(Json::Value& jsonValue) {
        BaseData::serialize(jsonValue);

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["description"] = Convert::toUTF8(_description);
        jsonValue["icon"] = _iconPath;
        jsonValue["type_id"] = _typeId;
    }

    void Item::deserialize(const Json::Value& jsonValue) {
        BaseData::deserialize(jsonValue);

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _description = Convert::toUTF16(jsonValue["description"].asString());
        _iconPath = jsonValue["icon"].asString();
        _typeId = jsonValue["type_id"].asInt();
        _userId = jsonValue["user_id"].asInt();
    }

    Type Item::getType() {
        return ITEM;
    }

    void Item::setName(const std::u16string& name) {
        _name = name;
    }

    void Item::setDescription(const std::u16string& description) {
        _description = description;
    }

    void Item::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void Item::setTypeId(unsigned int typeId) {
        _typeId = typeId;
    }

    void Item::setUserId(unsigned int userId) {
        _userId = userId;
    }

    const std::u16string& Item::getName() const {
        return _name;
    }

    const std::u16string& Item::getDescription() const {
        return _description;
    }

    const std::string& Item::getIconPath() const {
        return _iconPath;
    }

    unsigned int Item::getTypeId() const {
        return _typeId;
    }

    unsigned int Item::getUserId() const {
        return _userId;
    }

    void Item::clear() {
        _name.clear();
        _description.clear();
        _iconPath.clear();
        _typeId = NULL_ID;
        _userId = NULL_ID;
    }
}    //namespace Data
