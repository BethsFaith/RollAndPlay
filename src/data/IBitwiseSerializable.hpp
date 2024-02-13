//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SERIALIZABLE_HPP
#define ROLLANDPLAY_SERIALIZABLE_HPP

#include <iostream>

#include "ISerializable.hpp"
#include "storage/StreamReader.hpp"
#include "storage/StreamWriter.hpp"

namespace Data {
    class IBitwiseSerializable {
    public:
        using Ptr = std::shared_ptr<IBitwiseSerializable>;

        IBitwiseSerializable() = default;
        virtual ~IBitwiseSerializable() = default;

        [[nodiscard]] virtual std::size_t serialize(Storage::StreamWriter& writer) const = 0;
        virtual std::size_t deserialize(Storage::StreamReader& reader) = 0;

        [[nodiscard]] virtual std::size_t serialized_size() const noexcept = 0;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SERIALIZABLE_HPP
