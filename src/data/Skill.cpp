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

    void Skill::serialize(Json::Value& jsonValue) {}

    void Skill::deserialize(const Json::Value& jsonValue) {}

    size_t Skill::serialized_size() const noexcept {
        return 0;
    }

    Type Skill::getType() {
        return SKILL;
    }

    unsigned int Skill::getIndex() {
        return 0;
    }
}    //namespace Data
