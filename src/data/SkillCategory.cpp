//
// Created by VerOchka on 30.10.2023.
//

#include "SkillCategory.hpp"

namespace Data {
    uint8_t SkillCategory::index = 0;

    SkillCategory::SkillCategory() {
        _index = index++;
    }

    size_t SkillCategory::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t SkillCategory::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    size_t SkillCategory::serialized_size() const noexcept {
        return 0;
    }

    [[maybe_unused]] uint8_t SkillCategory::getIndex() const {
        return _index;
    }

    const std::string& SkillCategory::getName() const {
        return _name;
    }

    void SkillCategory::setName(const std::string& name) {
        _name = name;
    }

    const std::string& SkillCategory::getIconPath() const {
        return _iconPath;
    }

    void SkillCategory::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }
}    //namespace Data
