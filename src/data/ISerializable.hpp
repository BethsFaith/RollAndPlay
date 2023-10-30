//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SERIALIZABLE_HPP
#define ROLLANDPLAY_SERIALIZABLE_HPP

#include <iostream>
#include "storage/StreamWriter.hpp"
#include "storage/StreamReader.hpp"

namespace Data {
    class ISerializable {
    public:
        [[nodiscard]] virtual std::size_t serialize(Storage::StreamWriter &writer) const = 0;
        virtual std::size_t deserialize(Storage::StreamReader &reader) = 0;

        [[nodiscard]] virtual std::size_t serialized_size() const noexcept = 0;

    protected:
        ISerializable() = default;
        virtual ~ISerializable() = default;
    };
}


#endif //ROLLANDPLAY_SERIALIZABLE_HPP
