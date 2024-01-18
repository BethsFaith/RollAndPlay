//
// Created by VerOchka on 18.01.2024.
//

#ifndef ROLLANDPLAY_NETCONFIG_HPP
#define ROLLANDPLAY_NETCONFIG_HPP

#include "../net/ApiClient.hpp"

namespace Pages {
    struct NetConfig {
        Net::ApiClient::Ptr client;
        std::string domain;
    };
}

#endif //ROLLANDPLAY_NETCONFIG_HPP
