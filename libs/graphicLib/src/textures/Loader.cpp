//
// Created by VerOchka on 19.08.2023.
//

#include "../../headers/GraphicLib/Textures/Loader.hpp"

#include <utility>

namespace GraphicLib::Textures {
    bool load2d(Texture& texture, const std::vector<Param>& params) {
        bool res = false;

        int width, height, nrChannels;
        unsigned char* data = stbi_load(texture.getPath().c_str(), &width, &height, &nrChannels, 0);

        if (data) {
            GLenum format;
            if (nrChannels == 1) {
                format = GL_RED;
            } else if (nrChannels == 3) {
                format = GL_RGB;
            } else if (nrChannels == 4) {
                format = GL_RGBA;
            }

            texture.bind();
            texture.setImage(format, 0, width, height, 0, data);

            glGenerateMipmap(GL_TEXTURE_2D);

            for (const auto& param : params) {
                glTexParameteri(GL_TEXTURE_2D, param.name, param.value);
            }

            res = true;
        } else {
            std::cout << "Failed to load texture\n" << std::endl;
        }

        stbi_image_free(data);
        texture.unbind();

        return res;
    }

    bool loadCubeMap2d(Texture& texture,
                       std::vector<std::string> textureFacesPath,
                       const std::vector<Param>& params) {
        bool res = false;

        texture.bind();

        int width, height, nrChannels;
        unsigned char* data;

        for (int i = 0; i < textureFacesPath.size(); i++) {
            data = stbi_load((texture.getPath() + textureFacesPath.at(i)).c_str(),
                             &width, &height, &nrChannels, 0);

            if (data) {
                GLenum format;
                if (nrChannels == 1) {
                    format = GL_RED;
                } else if (nrChannels == 3) {
                    format = GL_RGB;
                } else if (nrChannels == 4) {
                    format = GL_RGBA;
                }

                texture.setImage(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                                 format, 0,
                                 width,
                                 height, 0,
                                 data);

                res = true;

            } else {
                std::cout << "Failed to load texture\n" << std::endl;
            }

            stbi_image_free(data);
        }

        for (const auto& param : params) {
            glTexParameteri(GL_TEXTURE_CUBE_MAP, param.name, param.value);
        }

        texture.unbind();

        return res;
    }
}    //namespace Tools::Objects::Textures::Loader
