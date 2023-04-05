#include <iostream>
#include <memory>
#include "IProperty.hpp"
#include "IntegerProperty.hpp"
#include "FloatProperty.hpp"
#include "StringProperty.hpp"
#include "PropertyType.hpp"
#include "CommandLineHandler.hpp"

namespace TTC {
    void CommandLineHandler::addProperty(std::shared_ptr<IProperty> property) {
        properties.push_back(property);
    }

    PropertyType CommandLineHandler::getPropertyType(std::string name) {
        for (std::shared_ptr<IProperty> property : properties) {
            if (property->getName() == name) {
                return property->getType();
            }
        }
        return PropertyType::NONE;
    }

    int CommandLineHandler::getIntegerPropertyValue(std::string name) {
        for (std::shared_ptr<IProperty> property : properties) {
            if (property->getName() == name) {
                if (property->getType() != PropertyType::INTEGER) {
                    throw std::invalid_argument("Property is not an integer");
                }
                std::shared_ptr<IntegerProperty> integerProperty = 
                    std::dynamic_pointer_cast<IntegerProperty>(property);
                return integerProperty->getValue();
            }
        }
        throw std::invalid_argument("Property not found");
    }

    float CommandLineHandler::getFloatPropertyValue(std::string name) {
        for (std::shared_ptr<IProperty> property : properties) {
            if (property->getName() == name) {
                if (property->getType() != PropertyType::FLOAT) {
                    throw std::invalid_argument("Property is not a float");
                }
                std::shared_ptr<FloatProperty> floatProperty = 
                    std::dynamic_pointer_cast<FloatProperty>(property);
                return floatProperty->getValue();
            }
        }
        throw std::invalid_argument("Property not found");
    }

    std::string CommandLineHandler::getStringPropertyValue(std::string name) {
        for (std::shared_ptr<IProperty> property : properties) {
            if (property->getName() == name) {
                if (property->getType() != PropertyType::STRING) {
                    throw std::invalid_argument("Property is not a string");
                }
                std::shared_ptr<StringProperty> stringProperty = 
                    std::dynamic_pointer_cast<StringProperty>(property);
                return stringProperty->getValue();
            }
        }
        throw std::invalid_argument("Property not found");
    }

    void CommandLineHandler::parse() {
        for (int i=1; i<argc; i++) {
            for (std::shared_ptr<IProperty> property : properties) {
                if (property->checkFlag(argv[i])) {
                    property->fromString(argv[i + 1]);
                }
            }
        }
    }
}