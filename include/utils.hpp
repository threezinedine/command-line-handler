#include <string>
#include <vector>

namespace TTC {
    bool isFlagString(std::string flag);
    bool isShortFlagString(std::string flag);
    std::vector<std::string> convertCharArrayToVector(int argc, char** argv);
}