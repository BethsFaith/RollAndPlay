//
// Created by BethsFaith on 09.02.2024.
//

#include "DataFactory.hpp"

Data::AData::Ptr Data::DataFactory::create(Data::Type type) {
    Data::AData::Ptr res;

    switch (type) {
        case SYSTEM:
            break;
        case RACE:
            break;
        case SKILL:
            res = std::make_shared<Skill>();
            break;
        case SKILL_CATEGORY:
            res = std::make_shared<SkillCategory>();
            break;
        case ACTION:
            res = std::make_shared<Action>();
            break;
        case CLASS:
            break;
        case USER:
            res = std::make_shared<User>();
            break;
        case SESSION:
            break;
    }

    return res;
}
