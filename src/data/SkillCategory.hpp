//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLCATEGORY_HPP
#define ROLLANDPLAY_SKILLCATEGORY_HPP

#include <iostream>
#include <utility>
#include <vector>

#include "Skill.hpp"

namespace Data {
    class SkillCategory : public ISerializable {
    public:
        using Ptr = std::shared_ptr<SkillCategory>;

        SkillCategory();
        ~SkillCategory() override = default;

        size_t serialize(std::ostream &os) const override;

        size_t deserialize(std::istream &is) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;
        [[nodiscard]] uint8_t getIndex() const;
        [[nodiscard]] const std::string &getName() const;
        [[nodiscard]] const std::string &getIconPath() const;

        void setName(const std::string &name);
        void setIconPath(const std::string &iconPath);

    private:
        uint8_t _index;
        std::string _name;
        std::string _iconPath;

        static uint8_t index;
    };
}

#endif //ROLLANDPLAY_SKILLCATEGORY_HPP
