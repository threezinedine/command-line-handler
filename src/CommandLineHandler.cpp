#include <iostream>
#include <memory>
#include "utils.hpp"
#include "IProperty.hpp"
#include "CommandLineHandler.hpp"
#include "PropertyInclude.hpp"

namespace TTC {
    void CommandLineHandler::addProperty(std::shared_ptr<IProperty> property) {
        properties.push_back(property);
    }

    void CommandLineHandler::parse(int argc, std::vector<std::string> argv) {
        for (int i=1; i<argc; i++) {
            for (std::shared_ptr<IProperty> property : properties) {
                if (property->checkFlag(argv[i])) {
                    property->fromString(argv[i + 1]);
                }
            }
        }
    }

    void CommandLineHandler::parse(int argc, char** argv) {
        std::vector<std::string> args = convertCharArrayToVector(argc, argv);
        this->parse(argc, args);
    }

    std::shared_ptr<IProperty> CommandLineHandler::getProperty(std::string name) {
        for (std::shared_ptr<IProperty> property : properties) {
            if (property->getName() == name) {
                return property;
            }
        }
        throw std::invalid_argument("Property not found");
    }
}