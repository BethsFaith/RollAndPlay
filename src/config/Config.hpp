//
// Created by VerOchka on 08.01.2024.
//

#ifndef ROLLANDPLAY_CONFIG_HPP
#define ROLLANDPLAY_CONFIG_HPP

#include <iostream>
#include <map>
#include <wtypes.h>

#include "Parser.hpp"

namespace Config {
    class Config {
    public:
        struct ShaderPath {
            std::string vertex;
            std::string fragment;
        };

        Config(const std::string &filePath);

        ShaderPath getShaderPath(const std::string& name);
        std::string getFontPath(const std::string& name);
        std::string getTexturePath(const std::string& name);
        std::string getNetValue(const std::string& name);

    private:
        std::map<std::string, ShaderPath> _shadersPaths;
        std::map<std::string, std::string> _texturesPaths;
        std::map<std::string, std::string> _fontPaths;
        std::map<std::string, std::string> _net;
    };

    void pullDesktopResolution(int& horizontal, int& vertical);
}

#endif //ROLLANDPLAY_CONFIG_HPP
