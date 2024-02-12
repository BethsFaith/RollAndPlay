//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_SKILL_HPP
#define ROLLANDPLAY_SKILL_HPP

#include <iostream>
#include <utility>

#include "AData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class Skill : public AData {
    public:
        using Ptr = std::shared_ptr<Skill>;

        ~Skill() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        Type getType() override;
        unsigned int getIndex() override;

        void setName(const std::u16string& name);
        void setName(const std::string& name);
        void setIconPath(const std::string& iconPath);
        void setCategory(const uint8_t& index);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] uint8_t getCategoryIndex() const;

    private:
        std::u16string _name;
        std::string _iconPath;
        uint8_t _categoryIndex = -1;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILL_HPP
