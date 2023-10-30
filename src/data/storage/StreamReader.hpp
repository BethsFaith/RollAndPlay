//
// Created by VerOchka on 31.10.2023.
//

#ifndef ROLLANDPLAY_STREAMREADER_HPP
#define ROLLANDPLAY_STREAMREADER_HPP

#include <iostream>
#include <fstream>
#include <utility>

namespace Data::Storage {
    class StreamReader {
    public:
        explicit StreamReader(std::string fileName);
        ~StreamReader() = default;

        size_t read(std::u16string &container);

    private:
        std::string _fileName;
    };
}


#endif //ROLLANDPLAY_STREAMREADER_HPP
