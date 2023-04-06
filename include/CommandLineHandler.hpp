#pragma once 
#include <memory>
#include <vector>
#include <string>
#include "CommandLine.h"
#include "utils.hpp"
#include "IProperty.hpp"


namespace TTC {
    class CommandLineHandler
    {
        private:
            int argc;
            std::vector<std::string> argv;
            std::vector<std::shared_ptr<IProperty>> properties;

        public:
            void addProperty(std::shared_ptr<IProperty> property);
            void parse(int argc, std::vector<std::string> argv);
            void parse(int argc, char** argv);
            std::shared_ptr<IProperty> getProperty(std::string name);
    };

}


#define DATA_VARIABLE commandLineData
#define DEFINE_COMMANDLINE_DATA(PROPERTY_LENGTH, ARGC, ARGV, ...) \
    DEFINE_STRUCT(PROPERTY_LENGTH, __VA_ARGS__) \
    HANDLER(PROPERTY_LENGTH, ARGC, ARGV, __VA_ARGS__) \
    PROPERTY_LENGTH(ASSIGN_VALUE, __VA_ARGS__)

#define DEFINE_STRUCT(PROPERTY_LENGTH, ...) \
    struct CommandLineData { PROPERTY_LENGTH(PROPERTY, __VA_ARGS__) };

#define HANDLER(PROPERTY_LENGTH, ARGC, ARGV, ...) \
    CommandLineData DATA_VARIABLE; \
    TTC::CommandLineHandler commandLineHandler; \
    PROPERTY_LENGTH(DEFINE_PROPERTY, __VA_ARGS__) \
    commandLineHandler.parse(ARGC, ARGV); \


#define PROPERTY(type, name, shortName, description, get_func) type name;

#define DEFINE_PROPERTY(type, name, shortName, description, get_func) \
    commandLineHandler.addProperty( \
        TTC::PropertyFactory<type>().create( \
            std::string(#name), \
            std::string(shortName), \
            std::string(description) \
        ) \
    );

#define ASSIGN_VALUE(type, name, shortName, description, get_func) \
        DATA_VARIABLE.name = get_func(commandLineHandler, #name); 


#define PROPERTY_1(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func);
#define PROPERTY_2(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_1(macro, __VA_ARGS__);
#define PROPERTY_3(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_2(macro, __VA_ARGS__);
#define PROPERTY_4(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_3(macro, __VA_ARGS__);
#define PROPERTY_5(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_4(macro, __VA_ARGS__);
#define PROPERTY_6(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_5(macro, __VA_ARGS__);
#define PROPERTY_7(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_6(macro, __VA_ARGS__);
#define PROPERTY_8(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_7(macro, __VA_ARGS__);
#define PROPERTY_9(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_8(macro, __VA_ARGS__);
#define PROPERTY_10(macro, type, name, shortName, description, get_func, ...) macro(type, name, shortName, description, get_func) PROPERTY_9(macro, __VA_ARGS__);