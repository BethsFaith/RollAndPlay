//
// Created by VerOchka on 31.10.2023.
//

#ifndef ROLLANDPLAY_DATASTORAGE_HPP
#define ROLLANDPLAY_DATASTORAGE_HPP

#include <filesystem>
#include <vector>

#include "Action.hpp"
#include "CharacterClass.hpp"
#include "IBitwiseSerializable.hpp"
#include "Race.hpp"
#include "Skill.hpp"
#include "SkillCategory.hpp"
#include "System.hpp"
#include "Type.hpp"
#include "User.hpp"

namespace Data {
    class DataStorage {
    public:
        static size_t save(const std::vector<IBitwiseSerializable::Ptr>& data, Type type);
        static size_t save(const IBitwiseSerializable::Ptr& data, Type type);
        static size_t load(std::vector<IBitwiseSerializable::Ptr>& container, Type type);

    private:
        static std::string getDirectory(Type type);
        static IBitwiseSerializable::Ptr create(Type type);
    };
}    //namespace Data

#endif    //ROLLANDPLAY_DATASTORAGE_HPP
