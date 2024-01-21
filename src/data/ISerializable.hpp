//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_ISERIALIZABLE_HPP
#define ROLLANDPLAY_ISERIALIZABLE_HPP

namespace Data {
    class ISerializable {
    public:
        using Ptr = std::shared_ptr<ISerializable>;
        ISerializable() = default;
        virtual ~ISerializable() = default;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_ISERIALIZABLE_HPP
