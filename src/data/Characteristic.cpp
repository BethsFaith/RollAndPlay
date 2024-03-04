//
// Created by BethsFaith on 04.03.2024.
//

#include "Characteristic.hpp"

namespace Data {
    void Characteristic::serialize(Json::Value& jsonValue) {
        BaseData::serialize(jsonValue);

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;
    }

    void Characteristic::deserialize(const Json::Value& jsonValue) {
        BaseData::deserialize(jsonValue);

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();
        _userId = jsonValue["user_id"].asInt();
    }

    Type Characteristic::getType() {
        return CHARACTERISTIC;
    }

    void Characteristic::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void Characteristic::setName(const std::u16string& name) {
        _name = name;
    }

    void Characteristic::setUserId(unsigned int userId) {
        _userId = userId;
    }

    const std::string& Characteristic::getIconPath() const {
        return _iconPath;
    }

    const std::u16string& Characteristic::getName() const {
        return _name;
    }

    unsigned int Characteristic::getUserId() const {
        return _userId;
    }
}