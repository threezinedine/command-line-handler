#pragma once 
#include <memory>
#include <vector>
#include <string>
#include "IProperty.hpp"
#include "PropertyType.hpp"


namespace TTC {
    class CommandLineHandler
    {
        private:
            int argc;
            std::vector<std::string> argv;
            std::vector<std::shared_ptr<IProperty>> properties;

        public:
            CommandLineHandler(int argc, std::vector<std::string> argv)
                : argc(argc), argv(argv) {};
            void addProperty(std::shared_ptr<IProperty> property);
            PropertyType getPropertyType(std::string name);
            void parse();
            int getIntegerPropertyValue(std::string name);
            float getFloatPropertyValue(std::string name);
            std::string getStringPropertyValue(std::string name);
    };
}