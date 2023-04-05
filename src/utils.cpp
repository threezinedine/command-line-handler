#include "utils.hpp"


namespace TTC {
    bool isFlagString(std::string flag) {
        return flag[0] == '-' && flag[1] == '-';
    }

    bool isShortFlagString(std::string flag) {
        return flag[0] == '-';
    }

    std::vector<std::string> convertCharArrayToVector(int size, char** charArray) {
        std::vector<std::string> result;
        for (int i = 0; i < size; ++i) {
            result.push_back(std::string(charArray[i]));
        }
        return result;
    }
}