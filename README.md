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
#include "CommandLine.h"


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

Firstly, you need to include the `CommandLine.h` file.
```C++
#include "CommandLine.h"
```

Then, you need to define the `DEFINE_COMMANDLINE_DATA` macro.
```C++
DEFINE_COMMANDLINE_DATA(
    PROPERTY_3,
    argc,
    argv,
    int, money, "m", "Integer property", GET_INT_VAL,
    float, credit, "c", "Float property", GET_FLOAT_VAL,
    std::string, name, "n", "String property", GET_STRING_VAL,
)
```

The `PROPERTY_<NUMBER_OF_PROPERTY>` is defined to determine the recursive number of the property.

The `argc` and `argv` are the arguments of the `main` function.

The `int, money, "m", "Integer property", GET_INT_VAL` is the property definition.

- `int` is the type of the property.
- `money` is the name of the property(not string), which is sent in the command line with the syntax `-money`.
- `"m"` is the short name of the property which is sent in the commandline with the syntax `--m`.
- `"Integer property"` is the description of the property.
- `GET_INT_VAL` is the function which is used to get the value of the property (there are 3 options `GET_STRING_VAL`, `GET_INT_VAL`, `GET_FLOAT_VAL`, so on).

The data of the property is stored in the `DATA_VARIABLE` variable.

Then, you can use the property in the code.

```C++
std::cout << "Money: " << DATA_VARIABLE.money << std::endl;
```