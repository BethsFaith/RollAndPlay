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

        SkillCategory() = default;
        ~SkillCategory() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        void setId(unsigned int index) override;

        Type getType() override;
        int getId() override;

        void setName(const std::u16string& name);
        void setName(const std::string& name);
        void setIconPath(const std::string& iconPath);
        void setUserId(unsigned int userId);
        void setUserName(const std::u16string& userName);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] const unsigned int& getUserId() const;
        [[nodiscard]] const std::u16string& getUserName() const;
    private:
        std::u16string _name;
        std::string _iconPath;
        unsigned int _userId;
        std::u16string _userName;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILLCATEGORY_HPP
