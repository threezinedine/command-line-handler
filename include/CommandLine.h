#pragma once

#define COMMANDLINE_VERSION_MAJOR 1
#define COMMANDLINE_VERSION_MINOR 1
#define COMMANDLINE_VERSION_PATCH 0

#define VERSION COMMANDLINE_VERSION_MAJOR << "." << COMMANDLINE_VERSION_MINOR << "." << COMMANDLINE_VERSION_PATCH

#include "IProperty.hpp"
#include "PropertyFactory.hpp"
#include "PropertyInclude.hpp"
#include "CommandLineHandler.hpp"
