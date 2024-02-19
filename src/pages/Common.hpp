//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_PAGECOMMONVARS_HPP
#define ROLLANDPLAY_PAGECOMMONVARS_HPP

#include "../net/HttpSession.hpp"
#include "../data/AData.hpp"
#include "../data/Type.hpp"

namespace Pages {
    struct Common {
        Net::HttpSession::Ptr session;
        Data::User user;
        //        std::map<Data::Type, Data::AData::Ptr> vars;
    };
}

#endif    //ROLLANDPLAY_PAGECOMMONVARS_HPP
