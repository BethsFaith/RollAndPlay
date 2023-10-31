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
        using Ptr = std::shared_ptr<ISerializable>;

        ISerializable() = default;
        virtual ~ISerializable() = default;

        [[nodiscard]] virtual std::size_t serialize(Storage::StreamWriter &writer) const = 0;
        virtual std::size_t deserialize(Storage::StreamReader &reader) = 0;

        [[nodiscard]] virtual std::size_t serialized_size() const noexcept = 0;

        virtual unsigned int getIndex() = 0;
    };
}


#endif //ROLLANDPLAY_SERIALIZABLE_HPP
