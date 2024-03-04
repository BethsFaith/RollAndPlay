//
// Created by BethsFaith on 04.03.2024.
//

#include "BaseData.hpp"

namespace Data {
    void BaseData::serialize(Json::Value& jsonValue) {
        if (id != -1) {
            jsonValue["id"] = id;
        }
    }

    void BaseData::deserialize(const Json::Value& jsonValue) {
        id = jsonValue["id"].asInt();
    }

    size_t BaseData::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t BaseData::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    void BaseData::setId(unsigned int index) {
        id = (int)index;
    }

    int BaseData::getId() {
        return id;
    }

    size_t BaseData::serialized_size() const noexcept {
        return 0;
    }
}