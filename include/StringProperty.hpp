#pragma once 

#include <string>
#include "Property.hpp"


namespace TTC {
    class StringProperty: public Property {
        private:
            std::string value;

        public:
            StringProperty(
                std::string name,
                std::string flag,
                std::string description
            )
                : Property(name, flag, description) {};
            void fromString(std::string value) override { this->value = value; };
            std::string getValue() { return value; }
    };
}


#define GET_STRING_VAL(handler, name) (std::dynamic_pointer_cast<TTC::StringProperty>(handler.getProperty(std::string(name))))->getValue()