//
// Created by VerOchka on 18.01.2024.
//

#ifndef ROLLANDPLAY_NETCONFIG_HPP
#define ROLLANDPLAY_NETCONFIG_HPP
//
//#include "../net/ApiClient.hpp"
#include <iostream>

namespace Pages {
    struct NetConfig {
        /*Net::ApiClient& client;*/
        std::string host;
        std::string port;
        std::string domain;
    };
}

#endif //ROLLANDPLAY_NETCONFIG_HPP
