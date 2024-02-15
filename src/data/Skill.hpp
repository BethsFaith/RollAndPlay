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

        Skill() = default;
        ~Skill() override = default;

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
        void setCategory(const uint8_t& index);
        void setUserId(unsigned int userId);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] int getCategoryIndex() const;
        [[nodiscard]] const unsigned int& getUserId() const;
    private:
        std::u16string _name;
        std::string _iconPath;
        int _categoryId = -1;
        unsigned int _userId;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILL_HPP
