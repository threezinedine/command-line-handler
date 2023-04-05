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