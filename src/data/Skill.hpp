//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_SKILL_HPP
#define ROLLANDPLAY_SKILL_HPP

#include <iostream>
#include <utility>

#include "ISerializable.hpp"

namespace Data {
    class Skill : ISerializable {
    public:
        using Ptr = std::shared_ptr<Skill>;

        ~Skill() override = default;

        size_t serialize(std::ostream &os) const override;
        size_t deserialize(std::istream &is) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

    private:
        std::string _name;
        std::string _iconPath;
        uint8_t _categoryIndex;
    };
}

#endif //ROLLANDPLAY_SKILL_HPP
