#pragma once

#include <string>

#include "Property.hpp"


namespace TTC {
    class IntegerProperty : public Property {
        private:
            int value;

        public:
            IntegerProperty(
                std::string name,
                std::string flag,
                std::string description
            )
                : Property(name, flag, description){};
            void fromString(std::string value) override;
            int getValue() { return value; }
    };
}