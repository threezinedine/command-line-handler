#include "utils.hpp"


namespace TTC {
    bool isFlagString(std::string flag) {
        return flag[0] == '-' && flag[1] == '-';
    }

    bool isShortFlagString(std::string flag) {
        return flag[0] == '-';
    }
}