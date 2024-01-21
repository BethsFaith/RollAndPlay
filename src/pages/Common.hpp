//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_PAGECOMMONVARS_HPP
#define ROLLANDPLAY_PAGECOMMONVARS_HPP

#include "../data/AData.hpp"
#include "../data/Type.hpp"
#include "../net/HttpSession.hpp"

namespace Pages {
    struct Common {
        Net::HttpSession::Ptr session;
        //        std::map<Data::Type, Data::AData::Ptr> vars;
    };
}

#endif    //ROLLANDPLAY_PAGECOMMONVARS_HPP
