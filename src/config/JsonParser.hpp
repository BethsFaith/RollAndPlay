//
// Created by BethsFaith on 09.02.2024.
//

#ifndef INC_1_BIN_JSONPARSER_HPP
#define INC_1_BIN_JSONPARSER_HPP

#include <fstream>
#include <iostream>
#include <json/reader.h>
#include <json/value.h>

namespace Config {
    class JsonParser {
    public:
        template<typename T>
        static T getValue(const std::string& filePath, const std::string& name) {
            std::ifstream ifstream(filePath, std::ifstream::binary);

            if (!ifstream.is_open()) {
                throw Json::Exception("File can't be open");
            }

            Json::Reader reader;
            Json::Value obj;
            reader.parse(ifstream, obj);    // reader can also read strings

            ifstream.close();

            return obj[name].as<T>();
        }

        template<typename T>
        static T getValue(const std::string& filePath, const std::vector<std::string>& path) {
            std::ifstream ifstream(filePath, std::ifstream::binary);

            if (!ifstream.is_open()) {
                throw Json::Exception("File can't be open");
            }

            Json::Reader reader;
            Json::Value obj;
            reader.parse(ifstream, obj);

            ifstream.close();

            Json::ValueIterator it = obj.begin();
            for (int i{0}; i < (int)path.size() - 1; ++i) {
                if (obj.isMember(path.at(i))) {
                    obj = obj[path.at(i)];
                }
            }

            return obj[path.back()].as<T>();
        }

        template<typename T>
        static std::vector<T> getValues(const std::string& filePath,
                                        const std::vector<std::string>& path,
                                        const std::vector<std::string>& keys) {
            std::ifstream ifstream(filePath, std::ifstream::binary);

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
    };
}    //namespace Config

#endif    //INC_1_BIN_JSONPARSER_HPP
