//
// Created by VerOchka on 17.08.2023.
//
#include "../../headers/GraphicLib/Buffers/RaiiBuffer.hpp"

namespace GraphicLib::Buffers {
    RaiiBuffer::RaiiBuffer(const int &priority) : _priority(priority) {}

    unsigned int RaiiBuffer::getPriority() const {
        return _priority;
    }
}