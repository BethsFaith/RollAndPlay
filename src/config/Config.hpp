//
// Created by VerOchka on 08.01.2024.
//

#ifndef ROLLANDPLAY_CONFIG_HPP
#define ROLLANDPLAY_CONFIG_HPP

#include <iostream>
#include <map>
#include <wtypes.h>

#include "File.hpp"

namespace Config {
    class Config {
    public:
        struct ShaderPath {
            std::string vertex;
            std::string fragment;
        };

        static Config* get();

        static void init(const std::string& filePath);
        static void free();

        ShaderPath getShaderPath(const std::string& name);
        std::string getFontPath(const std::string& name);
        std::string getTexturePath(const std::string& name);

    private:
        explicit Config(const std::string& filePath);

        static Config* _instance;

        std::map<std::string, ShaderPath> _shadersPaths;
        std::map<std::string, std::string> _texturesPaths;
        std::map<std::string, std::string> _fontPaths;
    };

    void pullDesktopResolution(int& horizontal, int& vertical);
}

#endif //ROLLANDPLAY_CONFIG_HPP
