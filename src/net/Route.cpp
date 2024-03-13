//
// Created by BethsFaith on 09.02.2024.
//

#include "Route.hpp"

namespace Net {
    Route::Route(Route& other) {
        _resources = other._resources;
        _privatePrefix = other._privatePrefix;
        _paths = other._paths;
    }

    Route::Route(const std::string& filePath) {
        _privatePrefix = Config::JsonParser::getValue<std::string>(filePath, "private");

        std::vector<std::string> methods{Http::MethodGet, Http::MethodPost, Http::MethodPut, Http::MethodDelete};

        pull(Data::SKILL, filePath, "skill", methods);
        pull(Data::USER, filePath, "user", methods);
        pull(Data::SKILL_CATEGORY, filePath, "category", methods);
        pull(Data::ACTION, filePath, "action", methods);
        pull(Data::SKILL, filePath, "skill", methods);
        pull(Data::SESSION, filePath, "session", methods);
        pull(Data::CHARACTERISTIC, filePath, "characteristic", methods);
        pull(Data::ITEM, filePath, "item", methods);
        pull(Data::ITEM_TYPE, filePath, "itemType", methods);
    }

    void Route::pull(Data::Type type,
                     const std::string& filePath,
                     const std::string& resName,
                     const std::vector<std::string>& methods) {
        _resources[type] = {};
        _resources[type].path = Config::JsonParser::getValue<std::string>(filePath, {resName, "path"});
        _resources[type].privatePath = _privatePrefix + _resources[type].path;

        _paths[type] = {};
        for (const auto& method : methods) {
            if (Config::JsonParser::getValue<bool>(filePath, {resName, method, "private"})) {
                _paths[type][method] = _resources[type].privatePath;
            } else {
                _paths[type][method] = _resources[type].path;
            }
        }
    }

    const std::map<Data::Type, std::map<std::string, std::string_view>>& Route::getPaths() const {
        return _paths;
    }
}    //namespace Net
