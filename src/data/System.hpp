//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEM_HPP
#define ROLLANDPLAY_SYSTEM_HPP

#include <map>

#include "Race.hpp"
#include "Skill.hpp"
#include "CharacterClass.hpp"
#include "Action.hpp"

namespace Data {
    class System : public ISerializable {
    public:
        using Ptr = std::shared_ptr<System>;

        System() = default;
        ~System() override = default;

        size_t serialize(Storage::StreamWriter &writer) const override;
        size_t deserialize(Storage::StreamReader &reader) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        void setName(const std::u16string &name);
        void setImage(const std::u16string &image);
        void setRaces(const std::vector<Race> &races);

        void addAction(const Action &actions);
        void addClass(CharacterClass &characterClass);
        void addClass(Skill &skill);

        unsigned int getIndex() override;

        const std::u16string &getName() const;

        const std::u16string &getImage() const;

    private:
        std::u16string _name;
        std::u16string _image;

        std::vector<Race> _races;
        std::vector<Action> _actions;
        std::vector<CharacterClass> _classes;
        std::vector<Skill> _skills;
    };
}


#endif //ROLLANDPLAY_SYSTEM_HPP
