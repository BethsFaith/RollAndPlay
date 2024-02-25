//
// Created by VeraTag on 08.11.2023.
//

#ifndef ROLLANDPLAY_FILE_HPP
#define ROLLANDPLAY_FILE_HPP

#include <iostream>
#include <fstream>

#include "JsonParser.hpp"

namespace Config {
    class Parser {
    public:
        enum Resource {
            SHADERS,
            TEXTURES,
            TEXT,
        };

        explicit Parser(const std::string& path);

        std::string getPath(Resource resource, const std::string& name);

        std::vector<std::string> getPaths(Resource resource, const std::string &parentKey,
                                          const std::vector<std::string>& keys);

        std::string getDirectory(Resource resDirectory);

        std::string getResourceDirectory();

        template<typename T>
        T getValue(const std::string& name) {
            return JsonParser::getValue<T>(_filePath, name);
        }

        template<typename T>
        T getValue(const std::vector<std::string>& path) {
            return JsonParser::getValue<T>(_filePath, path);
        }

        template<typename T>
        std::vector<T> getValues(const std::vector<std::string>& path, const std::vector<std::string>& keys) {
            return JsonParser::getValues<T>(_filePath, path, keys);
        }
    private:
        [[nodiscard]] std::string splitToPath(std::vector<std::string> strings) const;

        std::string _filePath;
        std::string _projectPath;
        const char _separator = '\\';
    };
};

#endif    //ROLLANDPLAY_FILE_HPP
