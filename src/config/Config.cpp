//
// Created by VerOchka on 08.01.2024.
//

#include "Config.hpp"

namespace Config {
    void pullDesktopResolution(int &horizontal, int &vertical) {
        RECT desktop;

        HWND hDesktop = GetDesktopWindow();

        GetWindowRect(hDesktop, &desktop);

        horizontal = desktop.right;
        vertical = desktop.bottom;
    }

    Config *Config::_instance = nullptr;

    Config::Config(const std::string &filePath) {
        File file(filePath);

        auto guiPaths = file.getPaths(File::Resource::SHADERS, "gui",
                                         {"vertex", "fragment"});
        auto selectablePaths = file.getPaths(File::Resource::SHADERS, "selectable",
                                                {"vertex", "fragment"});
        auto textPaths = file.getPaths(File::Resource::SHADERS, "text",
                                          {"vertex", "fragment"});
        auto texturePaths = file.getPaths(File::Resource::SHADERS, "texture_gui",
                                             {"vertex", "fragment"});
        auto net = file.getValues<std::string>({"net"}, {"host", "port", "domain"});

        _shadersPaths["gui"] = {.vertex = guiPaths.front(), .fragment = guiPaths.back()};
        _shadersPaths["selectable"] = {.vertex = selectablePaths.front(), .fragment = selectablePaths.back()};
        _shadersPaths["text"] = {.vertex = textPaths.front(), .fragment = textPaths.back()};
        _shadersPaths["texture"] = {.vertex = texturePaths.front(), .fragment = texturePaths.back()};

        _texturesPaths["default"] = file.getPath(File::Resource::TEXTURES, "default");

        _fontPaths["gui"] = file.getPath(File::Resource::TEXT, "gui");

        if (net.size() >= 3) {
            _net["host"] = net[0];
            _net["port"] = net[1];
            _net["domain"] = net[2];
        }
    }

    Config* Config::get() {
        return _instance;
    }

    void Config::init(const std::string& filePath) {
        _instance = new Config(filePath);
    }

    void Config::free() {
        delete _instance;
    }

    Config::ShaderPath Config::getShaderPath(const std::string &name) {
        if (_shadersPaths.contains(name)) {
            return _shadersPaths[name];
        } else {
            return {};
        }
    }

    std::string Config::getFontPath(const std::string &name) {
        if (_fontPaths.contains(name)) {
            return _fontPaths[name];
        } else {
            return "";
        }
    }

    std::string Config::getTexturePath(const std::string &name) {
        if (_texturesPaths.contains(name)) {
            return _texturesPaths[name];
        } else {
            return "";
        }
    }

    std::string Config::getNetValue(const std::string &name) {
        if (_net.contains(name)) {
            return _net[name];
        } else {
            return "";
        }
    }
}
