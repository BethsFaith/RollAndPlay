//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEM_HPP
#define ROLLANDPLAY_SYSTEM_HPP

#include <map>

#include "Action.hpp"
#include "CharacterClass.hpp"
#include "Race.hpp"
#include "Skill.hpp"
#include "IJsonSerializable.hpp"

namespace Data {
    class System : public IBitwiseSerializable, public IJsonSerializable {
    public:
        using Ptr = std::shared_ptr<System>;

        System() = default;
        ~System() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;
        void setName(const std::u16string& name);

        void setImage(const std::u16string& image);
        void setRaces(const std::vector<Race>& races);
        void addAction(const Action& actions);

        void addClass(CharacterClass& characterClass);

        void addClass(Skill& skill);

        const std::u16string& getName() const;
        const std::u16string& getImage() const;

    private:
        std::u16string _name;
        std::u16string _image;

        std::vector<Race> _races;
        std::vector<Action> _actions;
        std::vector<CharacterClass> _classes;
        std::vector<Skill> _skills;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SYSTEM_HPP
