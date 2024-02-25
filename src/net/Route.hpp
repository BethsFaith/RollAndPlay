//
// Created by BethsFaith on 09.02.2024.
//

#ifndef INC_1_BIN_ROUTE_HPP
#define INC_1_BIN_ROUTE_HPP

#include <iostream>
#include <map>

#include "../config/JsonParser.hpp"
#include "../data/Type.hpp"
#include "HttpMethods.hpp"

namespace Net {
    struct Route {
    public:
        explicit Route(const std::string& filePath);
        Route(Route& other);
        ~Route() = default;

        [[nodiscard]] const std::map<Data::Type, std::map<std::string, std::string_view>>& getPaths() const;

    private:
        struct Resource {
            std::string privatePath;
            std::string path;
        };

        void pull(Data::Type,
                  const std::string& filePath,
                  const std::string& resName,
                  const std::vector<std::string>& methods);

        static const char _separator = '/';

        std::string _privatePrefix;
        std::map<Data::Type, Resource> _resources;
        std::map<Data::Type, std::map<std::string, std::string_view>> _paths;
    };
}    //namespace Net

#endif    //INC_1_BIN_ROUTE_HPP
