//
// Created by VerOchka on 31.10.2023.
//

#ifndef ROLLANDPLAY_DATASTORAGE_HPP
#define ROLLANDPLAY_DATASTORAGE_HPP

#include <vector>
#include <filesystem>

#include "IBitwiseSerializable.hpp"
#include "System.hpp"
#include "Race.hpp"
#include "CharacterClass.hpp"
#include "Action.hpp"
#include "Skill.hpp"
#include "SkillCategory.hpp"
#include "User.hpp"
#include "Type.hpp"

namespace Data {
    class DataStorage {
    public:
        static size_t save(const std::vector<IBitwiseSerializable::Ptr>& data, Type type);
        static size_t save(const IBitwiseSerializable::Ptr& data, Type type);
        static size_t load(std::vector<IBitwiseSerializable::Ptr> &container, Type type);

    private:
        static std::string getDirectory(Type type);
        static IBitwiseSerializable::Ptr create(Type type);
    };
}

#endif //ROLLANDPLAY_DATASTORAGE_HPP
