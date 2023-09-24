//
//  CppEngine.cpp
//  CppBridgeTest
//
//  Created by Changmook Chun on 2023-02-27.
//

#include "CppEngine.hpp"

#include <exception>

integer_buffer::integer_buffer (std::size_t sz, const std::string& name) {
    _buffer = std::vector<int>(sz, 0);
    _name = name;
}

std::string integer_buffer::name() const {
    return _name;
}

std::size_t integer_buffer::size() const {
    return _buffer.size();
}

int integer_buffer::at(const std::size_t i) const {
    if (0 <= i && i < _buffer.size())
        return _buffer[i];
    else
        throw std::runtime_error("Out of range");
}

void integer_buffer::set_value_at(const std::size_t i, const int& val) {
    if (0 <= i && i < _buffer.size())
        _buffer[i] = val;
    else
        throw std::runtime_error("Out of range");
}
