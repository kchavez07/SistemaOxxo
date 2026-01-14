#pragma once
#include "Prerequisites.h"

class OxxoException : public std::runtime_error {
public:
    explicit OxxoException(const std::string& msg) : std::runtime_error(msg) {}
};
