#pragma once 
#include <string>
#include "IProperty.hpp"


namespace TTC
{
    class Property: public IProperty {
        private:
            std::string name;
            std::string flag;
            std::string description;

        public:
            Property(
                std::string name,
                std::string flag,
                std::string description
            );
            std::string getName() override { return name; }
            bool checkFlag(std::string flag) override;
            virtual void fromString(std::string value) = 0;
    };
}