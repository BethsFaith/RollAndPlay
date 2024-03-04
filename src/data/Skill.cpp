//
// Created by VerOchka on 05.10.2023.
//

#include "Skill.hpp"

namespace Data {
    size_t Skill::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t Skill::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    void Skill::serialize(Json::Value& jsonValue) {
        BaseData::serialize(jsonValue);

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;

        if (_categoryId != -1) {
            jsonValue["category_id"] = _categoryId;
        }
    }

    void Skill::deserialize(const Json::Value& jsonValue) {
        BaseData::deserialize(jsonValue);

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();
        _userId = jsonValue["user_id"].asInt();

        if (jsonValue.isMember("category_id")) {
            _categoryId = jsonValue["category_id"].asInt();
        }
    }

    size_t Skill::serialized_size() const noexcept {
        return 0;
    }

    Type Skill::getType() {
        return SKILL;
    }

    const unsigned int& Skill::getUserId() const {
        return _userId;
    }

    void Skill::setName(const std::u16string& name) {
        _name = name;
    }

    void Skill::setName(const std::string& name) {
        _name = Convert::toUTF16(name);
    }

    void Skill::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void Skill::setCategoryId(const uint8_t& index) {
        _categoryId = index;
    }

    void Skill::setUserId(unsigned int userId) {
        _userId = userId;
    }

    const std::u16string& Skill::getName() const {
        return _name;
    }

    const std::string& Skill::getIconPath() const {
        return _iconPath;
    }

    int Skill::getCategoryId() const {
        return _categoryId;
    }

    void Skill::setUserName(const std::u16string& userName) {
        _userName = userName;
    }

    const std::u16string& Skill::getUserName() const {
        return _userName;
    }
}    //namespace Data
