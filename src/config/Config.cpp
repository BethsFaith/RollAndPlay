//
// Created by VeraTag on 10.11.2023.
//

#include "Config.hpp"

#include <utility>

namespace Config {
    std::string getPath(Resource resource, const std::vector<std::string>& name) {
        std::string resourceKey;

        switch (resource) {
            case SHADERS:
                resourceKey = "shaders";
                break;
            case TEXTURES:
                resourceKey = "textures";
                break;
            case TEXT:
                resourceKey = "fonts";
                break;
        }

        auto directory = getValue<std::string>(std::vector<std::string>{"resources", resourceKey, "directory"});

        std::vector<std::string> keys{"resources", resourceKey, "files"};
        keys.insert(keys.end(), name.begin(), name.end());

        auto file = getValue<std::string>(keys);

        return splitToPath({projectPath, getResourceDirectory(), directory, file});
    }

    std::vector<std::string> getPaths(Resource resource, const std::string &parentKey,
                                      const std::vector<std::string> &keys) {
        std::string resourceKey;

        switch (resource) {
            case SHADERS:
                resourceKey = "shaders";
                break;
            case TEXTURES:
                resourceKey = "textures";
                break;
            case TEXT:
                resourceKey = "fonts";
                break;
        }

        auto directory = getValue<std::string>(std::vector<std::string>{"resources", resourceKey, "directory"});

        auto files = getValues<std::string>({"resources", resourceKey, "files", parentKey}, keys);
        for (auto & file : files) {
            file = splitToPath({projectPath, getResourceDirectory(), directory, file});
        }

        return files;
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