# command-line-handler
The command-line handler library for handling the command-line argument for the C++ project.


## How to use

Firstly, install the library from the github repository.

```bash
git clone https://github.com/threezinedine/command-line-handler.git
```

Then, for building the library, you can use the CMakeLists.txt file.

```bash
cd command-line-handler
mkdir build
cd build
```

### For Linux

```bash
cmake -S ..
```

### For Windows

```commandline
cmake -S .. -G <Your makefile>
```

##### Example

```commandline
cmake -S .. -G "MinGW Makefiles"
```

Then, you can build the library.

```bash
make
```

The output of the library is `libCommandLine.a`


# Example
    
```c++
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
```