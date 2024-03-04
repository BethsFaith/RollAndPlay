//
// Created by BethsFaith on 04.03.2024.
//

#ifndef INC_1_BIN_BASEDATA_HPP
#define INC_1_BIN_BASEDATA_HPP

#include "AData.hpp"

namespace Data {
    class BaseData : public AData {
    public:
        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        void setId(unsigned int index) override;

        int getId() override;
        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;
        size_t serialized_size() const noexcept override;

    private:
        int id = -1;
    };
}

#endif    //INC_1_BIN_BASEDATA_HPP
