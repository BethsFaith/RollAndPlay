//
// Created by VerOchka on 05.10.2023.
//

#include "Skill.hpp"

namespace Data {
    size_t Skill::serialize(Storage::StreamWriter &writer) const {
        return 0;
    }

    size_t Skill::deserialize(Storage::StreamReader &reader) {
        return 0;
    }

    size_t Skill::serialized_size() const noexcept {
        return 0;
    }
}