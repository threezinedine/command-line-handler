#include <iostream>
#include "FloatProperty.hpp"


namespace TTC {
    void FloatProperty::fromString(std::string value) {
        try {
            this->value = std::stof(value);
        } catch (std::invalid_argument e) {
            this->value = 0;
        }
    }
}