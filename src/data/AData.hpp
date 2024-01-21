//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_ADATA_HPP
#define ROLLANDPLAY_ADATA_HPP

#include <iostream>

#include "Type.hpp"

namespace Data {
    class AData {
    public:
        using Ptr = std::shared_ptr<AData>;

        AData() = default;
        virtual ~AData() = default;

        virtual Type getType() = 0;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_ADATA_HPP
