//
// Created by VeraTag on 08.11.2023.
//

#ifndef ROLLANDPLAY_CONFIG_HPP
#define ROLLANDPLAY_CONFIG_HPP

#include <iostream>
#include <fstream>

#include <json/reader.h>
#include <json/value.h>
#include <wtypes.h>

namespace Config {
    enum Resource {
        SHADERS,
        TEXTURES,
        TEXT,
    };

    std::string getPath(Resource resource, const std::string& name);

    std::string getDirectory(Resource resDirectory);

    std::string getResourceDirectory();

    std::string splitToPath(std::vector<std::string> strings);

    template<typename T>
    static T getValue(const std::string& name) {
        std::ifstream ifstream("../../config.json", std::ifstream::binary);

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
    static T getValue(const std::vector<std::string>& path) {
        std::ifstream ifstream("../../config.json", std::ifstream::binary);

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

    static void pullDesktopResolution(int& horizontal, int& vertical)
    {
        RECT desktop;

        const HWND hDesktop = GetDesktopWindow();

        GetWindowRect(hDesktop, &desktop);

        horizontal = desktop.right;
        vertical = desktop.bottom;
    }

    static std::string projectPath = getValue<std::string>("path");

    static char separator = '\\';
};

#endif    //ROLLANDPLAY_CONFIG_HPP
