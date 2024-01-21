//
// Created by VerOchka on 17.01.2024.
//

#ifndef ROLLANDPLAY_IJSONSERIALIZABLE_HPP
#define ROLLANDPLAY_IJSONSERIALIZABLE_HPP

#include <json/json.h>

#include "ISerializable.hpp"

namespace Data {
    class IJsonSerializable {
    public:
        using Ptr = std::shared_ptr<IJsonSerializable>;

        IJsonSerializable() = default;
        virtual ~IJsonSerializable() = default;

        virtual void serialize(Json::Value& jsonValue) = 0;
        virtual void deserialize(const Json::Value& jsonValue) = 0;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_IJSONSERIALIZABLE_HPP
