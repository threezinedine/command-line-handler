#include <iostream>
#include <string>
#include "PropertyFactory.hpp"
#include "PropertyInclude.hpp"
#include "CommandLineHandler.hpp"


int main(int argc, char** argv) {
    DEFINE_COMMANDLINE_DATA(
        PROPERTY_3,
        argc,
        argv,
        int, money, "m", "Integer property", GET_INT_VAL,
        float, credit, "c", "Float property", GET_FLOAT_VAL,
        std::string, name, "n", "String property", GET_STRING_VAL,
    )

    std::cout << "Money: " << DATA_VARIABLE.money << std::endl;
    std::cout << "Credit: " << DATA_VARIABLE.credit << std::endl;
    std::cout << "Name: " << DATA_VARIABLE.name << std::endl;
    return 0;
}