//
// Created by VerOchka on 30.10.2023.
//

#include "SkillCategory.hpp"

namespace Data {
    size_t SkillCategory::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t SkillCategory::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    void SkillCategory::serialize(Json::Value& jsonValue) {
        BaseData::serialize(jsonValue);

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;
    }

    void SkillCategory::deserialize(const Json::Value& jsonValue) {
        BaseData::deserialize(jsonValue);

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();
        _userId = jsonValue["user_id"].asInt();
    }

    size_t SkillCategory::serialized_size() const noexcept {
        return 0;
    }

    void SkillCategory::setName(const std::u16string& name) {
        _name = name;
    }

    void SkillCategory::setName(const std::string& name) {
        _name = std::u16string(name.begin(), name.end());
    }

    const std::u16string& SkillCategory::getName() const {
        return _name;
    }

    const std::string& SkillCategory::getIconPath() const {
        return _iconPath;
    }

    void SkillCategory::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    Type SkillCategory::getType() {
        return SKILL_CATEGORY;
    }

    void SkillCategory::setUserId(unsigned int userId) {
        _userId = userId;
    }

    const unsigned int& SkillCategory::getUserId() const {
        return _userId;
    }

    const std::u16string& SkillCategory::getUserName() const {
        return _userName;
    }

    void SkillCategory::setUserName(const std::u16string& userName) {
        _userName = userName;
    }
}    //namespace Data
