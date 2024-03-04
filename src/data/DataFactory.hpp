//
// Created by BethsFaith on 09.02.2024.
//

#ifndef INC_1_BIN_DATAFACTORY_HPP
#define INC_1_BIN_DATAFACTORY_HPP

#include "AData.hpp"
#include "Type.hpp"
#include "Race.hpp"
#include "Skill.hpp"
#include "SkillCategory.hpp"
#include "System.hpp"
#include "Type.hpp"
#include "User.hpp"
#include "Action.hpp"
#include "CharacterClass.hpp"
#include "Characteristic.hpp"

namespace Data {
    class DataFactory {
    public:
        static AData::Ptr create(Type type);
    };
}

#endif    //INC_1_BIN_DATAFACTORY_HPP
