//
// Created by VeraTag on 10.11.2023.
//

#include "Config.hpp"

#include <utility>

namespace Config {
    std::string getPath(Resource resource, const std::string& name) {
        std::string resourceKey;

        switch (resource) {
            case SHADERS:
                resourceKey = "shaders";
            case TEXTURES:
                resourceKey = "textures";
            case TEXT:
                resourceKey = "fonts";
        }

        auto directory = getValue<std::string>(std::vector<std::string>{"resources", resourceKey, "directory"});
        auto file = getValue<std::string>(std::vector<std::string>{"resources", resourceKey, "files",
                                                                   name});

        return splitToPath({projectPath, getResourceDirectory(), directory, file});
    }

    std::string getResourceDirectory() {
        return getValue<std::string>(std::vector<std::string>{"resources", "directory"});
    }

    std::string getDirectory(Resource resDirectory) {
        switch (resDirectory) {
            case SHADERS:
                return getValue<std::string>(std::vector<std::string>{"resources", "shaders", "directory"});
            case TEXTURES:
                return getValue<std::string>(std::vector<std::string>{"resources", "textures", "directory"});
            case TEXT:
                return getValue<std::string>(std::vector<std::string>{"resources", "fonts", "directory"});
        }
    }

    std::string splitToPath(std::vector<std::string> strings) {
        if (strings.empty()) return "";

        std::string path = strings.at(0);
        for (int i{1}; i < strings.size(); ++i) {
            path += separator + strings.at(i);
        }

        return path;
    }
}