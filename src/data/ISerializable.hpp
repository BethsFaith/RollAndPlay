//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SERIALIZABLE_HPP
#define ROLLANDPLAY_SERIALIZABLE_HPP

#include <iostream>

namespace Data {
    class ISerializable {
    public:
        virtual std::size_t serialize(std::ostream& os) const = 0;
        virtual std::size_t deserialize(std::istream& is) = 0;

        [[nodiscard]] virtual std::size_t serialized_size() const noexcept = 0;

    protected:
        ISerializable() = default;
        virtual ~ISerializable() = default;
    };
}


#endif //ROLLANDPLAY_SERIALIZABLE_HPP
