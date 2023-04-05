#pragma once
#include <string>
#include "PropertyType.hpp"


namespace TTC {
    class IProperty {
        public:
            virtual std::string getName() = 0;
            virtual void fromString(std::string value) = 0;
            virtual bool checkFlag(std::string flag) = 0;
            virtual PropertyType getType() = 0;
    };
}