#include <iostream>
#include "Property.hpp"
#include "utils.hpp"
#include "constants.hpp"


namespace TTC {
    Property::Property(
        std::string name,
        std::string flag,
        std::string description
    )
        : description(description) {
            if (flag != HELP_FLAG) {
                this->flag = flag;
            } else {
                throw std::invalid_argument("Flag cannot be -h");
            }

            if (name != HELP_NAME) {
                this->name = name;
            } else {
                throw std::invalid_argument("Name cannot be help");
            }
        };

    bool Property::checkFlag(std::string flag) {
        if (isFlagString(flag))
            return flag.substr(2) == this->flag;
        else if (isShortFlagString(flag)) {
            return flag.substr(1) == this->name;
        } else {
            return false;
        }
    }
}