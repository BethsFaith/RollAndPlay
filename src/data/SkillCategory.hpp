//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLCATEGORY_HPP
#define ROLLANDPLAY_SKILLCATEGORY_HPP

#include <iostream>
#include <utility>
#include <vector>

#include "AData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class SkillCategory : public AData {
    public:
        using Ptr = std::shared_ptr<SkillCategory>;

        SkillCategory();
        ~SkillCategory() override = default;

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

        [[nodiscard]] uint8_t getIndex() const;
        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;

    private:
        uint8_t _index;
        std::u16string _name;
        std::string _iconPath;

        static uint8_t index;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILLCATEGORY_HPP
