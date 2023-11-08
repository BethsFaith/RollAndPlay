//
// Created by VerOchka on 31.10.2023.
//

#ifndef ROLLANDPLAY_STREAMWRITER_HPP
#define ROLLANDPLAY_STREAMWRITER_HPP

#include <iostream>
#include <fstream>
#include <utility>

namespace Data::Storage {
    class StreamWriter {
    public:
        explicit StreamWriter(std::string fileName);
        ~StreamWriter() = default;

        size_t write(std::uint32_t data);
        size_t write(int data);
        size_t write(std::u16string data);

        void setFileName(const std::string &fileName);

    private:
        std::string _fileName;
    };
}

#endif //ROLLANDPLAY_STREAMWRITER_HPP
