//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_ADATA_HPP
#define ROLLANDPLAY_ADATA_HPP

#include <iostream>

#include "Type.hpp"
#include "IJsonSerializable.hpp"
#include "IBitwiseSerializable.hpp"

namespace Data {
    class AData : public IJsonSerializable, public IBitwiseSerializable {
    public:
        using Ptr = std::shared_ptr<AData>;

        AData() = default;
        ~AData() override = default;

        virtual Type getType() = 0;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_ADATA_HPP
