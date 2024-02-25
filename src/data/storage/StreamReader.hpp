//
// Created by VerOchka on 31.10.2023.
//

#ifndef ROLLANDPLAY_STREAMREADER_HPP
#define ROLLANDPLAY_STREAMREADER_HPP

#include <fstream>
#include <iostream>
#include <utility>

namespace Data::Storage {
    class StreamReader {
    public:
        explicit StreamReader(std::string fileName);
        ~StreamReader() = default;

        size_t read(std::u16string& container);
        size_t read(uint32_t& container);

        void setFileName(const std::string& fileName);

    private:
        std::string _fileName;

    public:
        const std::string& getFileName() const;
    };
}    //namespace Data::Storage

#endif    //ROLLANDPLAY_STREAMREADER_HPP
