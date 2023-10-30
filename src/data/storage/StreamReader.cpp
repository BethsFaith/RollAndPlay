//
// Created by VerOchka on 31.10.2023.
//

#include "StreamReader.hpp"

namespace Data::Storage {
    StreamReader::StreamReader(std::string fileName) : _fileName(std::move(fileName)) {

    }

    size_t StreamReader::read(std::u16string &container) {
        std::ifstream ifstream;

        ifstream.open(_fileName, std::ios::binary);

        const auto pos = ifstream.tellg();
        auto size = static_cast<std::size_t>(ifstream.tellg() - pos);

        std::uint32_t length = 0;
        auto char16Size = sizeof(char16_t);

        ifstream.read((char*)(&length), sizeof(length));
        if (length != 0) {
            ifstream.read((char*)(&container), char16Size * length);
        }

        return size;
    }
}