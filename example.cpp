#include <iostream>
#include <string>
#include "PropertyFactory.hpp"
#include "PropertyType.hpp"
#include "CommandLineHandler.hpp"


int main(int argc, char** argv) {
    std::cout << "CommandLine Hanlder Version: " << COMMANDLINE_VERSION_MAJOR << "." << COMMANDLINE_VERSION_MINOR << "." << COMMANDLINE_VERSION_PATCH << std::endl;
    TTC::CommandLineHandler handler(argc, argv);
    handler.addProperty(TTC::PropertyFactory().create(TTC::PropertyType::INTEGER, "money", "m", "Integer property"));
    handler.addProperty(TTC::PropertyFactory().create(TTC::PropertyType::FLOAT, "credit", "c", "Float property"));
    handler.addProperty(TTC::PropertyFactory().create(TTC::PropertyType::STRING, "name", "n", "String property"));
    handler.parse();
    std::cout << "Money: " << handler.getIntegerPropertyValue("money") << std::endl;
    std::cout << "Credit: " << handler.getFloatPropertyValue("credit") << std::endl;
    std::cout << "Name: " << handler.getStringPropertyValue("name") << std::endl;
    return 0;
}