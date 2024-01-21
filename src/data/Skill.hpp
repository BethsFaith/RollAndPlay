//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_SKILL_HPP
#define ROLLANDPLAY_SKILL_HPP

#include <iostream>
#include <utility>

#include "IBitwiseSerializable.hpp"

namespace Data {
    class Skill : IBitwiseSerializable {
    public:
        using Ptr = std::shared_ptr<Skill>;

        ~Skill() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

    private:
        std::string _name;
        std::string _iconPath;
        uint8_t _categoryIndex;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILL_HPP
