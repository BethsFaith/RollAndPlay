//
// Created by VeraTag on 10.11.2023.
//

#include "File.hpp"

#include <utility>

namespace Config {
    File::File(const std::string& path) {
        _filePath = path;
        _projectPath = getValue<std::string>("path");
    }

    std::string File::getPath(Resource resource, const std::string& name) {
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

        auto file = getValue<std::string>({"resources", resourceKey, "files", name});

        return splitToPath({_projectPath, getResourceDirectory(), directory, file});
    }

    std::vector<std::string> File::getPaths(Resource resource, const std::string &parentKey,
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
            file = splitToPath({_projectPath, getResourceDirectory(), directory, file});
        }

        return files;
    }

    std::string File::getResourceDirectory() {
        return getValue<std::string>(std::vector<std::string>{"resources", "directory"});
    }

    std::string File::getDirectory(Resource resDirectory) {
        switch (resDirectory) {
            case SHADERS:
                return getValue<std::string>(std::vector<std::string>{"resources", "shaders", "directory"});
            case TEXTURES:
                return getValue<std::string>(std::vector<std::string>{"resources", "textures", "directory"});
            case TEXT:
                return getValue<std::string>(std::vector<std::string>{"resources", "fonts", "directory"});
        }
    }

    std::string File::splitToPath(std::vector<std::string> strings) const {
        if (strings.empty()) return "";

        std::string path = strings.at(0);
        for (int i{1}; i < strings.size(); ++i) {
            path += _separator + strings.at(i);
        }

        return path;
    }
}