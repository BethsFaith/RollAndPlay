//
// Created by VerOchka on 17.08.2023.
//
#include "RaiiBuffer.hpp"

namespace View::Buffers  {
    RaiiBuffer::RaiiBuffer(const int& priority) : _priority(priority) {}

    unsigned int RaiiBuffer::getPriority() const {
        return _priority;
    }
}