//
// Created by VeraTag on 08.11.2023.
//

#ifndef ROLLANDPLAY_FILE_HPP
#define ROLLANDPLAY_FILE_HPP

#include <iostream>
#include <fstream>

#include <json/reader.h>
#include <json/value.h>

namespace Config {
    class File {
    public:
        enum Resource {
            SHADERS,
            TEXTURES,
            TEXT,
        };

        explicit File(const std::string& path);

        std::string getPath(Resource resource, const std::string& name);

        std::vector<std::string> getPaths(Resource resource, const std::string &parentKey,
                                          const std::vector<std::string>& keys);

        std::string getDirectory(Resource resDirectory);

        std::string getResourceDirectory();

    private:
        [[nodiscard]] std::string splitToPath(std::vector<std::string> strings) const;

        template<typename T>
        T getValue(const std::string& name) {
            std::ifstream ifstream(_filePath, std::ifstream::binary);

            if (!ifstream.is_open()) {
                throw Json::Exception("File can't be open");
            }

            Json::Reader reader;
            Json::Value obj;
            reader.parse(ifstream, obj); // reader can also read strings

            ifstream.close();

            return obj[name].as<T>();
        }

        template<typename T>
        T getValue(const std::vector<std::string>& path) {
            std::ifstream ifstream(_filePath, std::ifstream::binary);

            if (!ifstream.is_open()) {
                throw Json::Exception("File can't be open");
            }

            Json::Reader reader;
            Json::Value obj;
            reader.parse(ifstream, obj);

            ifstream.close();

            Json::ValueIterator it = obj.begin();
            for (int i{0}; i < (int)path.size()-1; ++i) {
                if (obj.isMember(path.at(i))) {
                    obj = obj[path.at(i)];
                }
            }

            return obj[path.back()].as<T>();
        }

        template<typename T>
        std::vector<T> getValues(const std::vector<std::string>& path, const std::vector<std::string>& keys) {
            std::ifstream ifstream(_filePath, std::ifstream::binary);

            if (!ifstream.is_open()) {
                throw Json::Exception("File can't be open");
            }

            Json::Reader reader;
            Json::Value obj;
            reader.parse(ifstream, obj);

            ifstream.close();

            Json::ValueIterator it = obj.begin();
            for (const auto& key : path) {
                if (obj.isMember(key)) {
                    obj = obj[key];
                }
            }

            std::vector<T> result{};
            for (const auto& key : keys) {
                if (obj.isMember(key)) {
                    result.push_back(obj[key].as<T>());
                }
            }

            return result;
        }

        std::string _filePath;
        std::string _projectPath;
        const char _separator = '\\';
    };
};

#endif    //ROLLANDPLAY_FILE_HPP
