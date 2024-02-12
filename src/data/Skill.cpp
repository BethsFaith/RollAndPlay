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
        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;
        if (_categoryIndex != -1) {
            jsonValue["category_index"] = _categoryIndex;
        }
    }

    void Skill::deserialize(const Json::Value& jsonValue) {
        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();

        if (jsonValue.isMember("category_index")) {
            _categoryIndex = jsonValue["category_index"].asUInt();
        }
    }

    size_t Skill::serialized_size() const noexcept {
        return 0;
    }

    Type Skill::getType() {
        return SKILL;
    }

    unsigned int Skill::getIndex() {
        return 0;
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

    void Skill::setCategory(const uint8_t& index) {
        _categoryIndex = index;
    }

    const std::u16string& Skill::getName() const {
        return _name;
    }

    const std::string& Skill::getIconPath() const {
        return _iconPath;
    }

    uint8_t Skill::getCategoryIndex() const {
        return _categoryIndex;
    }
}    //namespace Data
