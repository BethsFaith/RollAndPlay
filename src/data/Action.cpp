//
// Created by VerOchka on 05.10.2023.
//

#include "Action.hpp"

namespace Data {
    size_t Action::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t Action::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    void Action::serialize(Json::Value& jsonValue) {
        if (id != -1) {
            jsonValue["id"] = id;
        }

        jsonValue["name"] = Convert::toUTF8(_name);
        jsonValue["icon"] = _iconPath;
        jsonValue["points"] = _pointsNumber;

        if (_skillId != -1) {
            jsonValue["skill_id"] = _skillId;
        }
    }

    void Action::deserialize(const Json::Value& jsonValue) {
        id = jsonValue["id"].asInt();

        _name = Convert::toUTF16(jsonValue["name"].asString());
        _iconPath = jsonValue["icon"].asString();
        _userId = jsonValue["user_id"].asInt();

        if (jsonValue.isMember("skill_id")) {
            _skillId = jsonValue["skill_id"].asInt();
        }
    }

    size_t Action::serialized_size() const noexcept {
        return 0;
    }

    void Action::setId(unsigned int index) {
        id = index;
    }

    void Action::setName(const std::u16string& name) {
        _name = name;
    }

    void Action::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void Action::setPointsNumber(uint8_t pointsNumber) {
        _pointsNumber = pointsNumber;
    }

    void Action::setUserId(unsigned int userId) {
        _userId = userId;
    }

    void Action::setSkillId(int skillId) {
        _skillId = skillId;
    }

    const std::string& Action::getIconPath() const {
        return _iconPath;
    }

    const std::u16string& Action::getName() const {
        return _name;
    }

    uint8_t Action::getPointsNumber() const {
        return _pointsNumber;
    }

    unsigned int Action::getUserId() const {
        return _userId;
    }

    int Action::getSkillId() const {
        return _skillId;
    }

    int Action::getId() {
        return id;
    }

    Type Action::getType() {
        return ACTION;
    }

}    //namespace Data
