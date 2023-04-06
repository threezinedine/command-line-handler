#pragma once

#include "Property.hpp"


namespace TTC {
    class FloatProperty: public Property {
        private:
            float value;

        public:
            FloatProperty(
                std::string name,
                std::string flag,
                std::string description
            )
                : Property(name, flag, description) {};
            float getValue() { return value; }
            void fromString(std::string value) override;
    };
}


#define GET_FLOAT_VAL(handler, name) (std::dynamic_pointer_cast<TTC::FloatProperty>(handler.getProperty(std::string(name))))->getValue()