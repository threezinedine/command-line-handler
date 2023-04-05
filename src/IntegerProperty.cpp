#include <iostream>
#include "IntegerProperty.hpp"


namespace TTC
{
    void IntegerProperty::fromString(std::string value)
    {
        try {
            this->value = std::stoi(value);
        }
        catch (std::invalid_argument& e){
            this->value = 0;
        }
    }
} 
