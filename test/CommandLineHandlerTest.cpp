#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "CommandLineHandler.hpp"
#include "PropertyFactory.hpp"
#include "IProperty.hpp"


const std::string TEST_INT_NAME = "money";
const std::string TEST_INT_FLAG = "m";
const std::string TEST_INT_DESCRIPTION = "The amount of money you have";
const int TEST_INT_VALUE = 100;

const std::string TEST_FLOAT_NAME = "credit";
const std::string TEST_FLOAT_FLAG = "c";
const std::string TEST_FLOAT_DESCRIPTION = "The amount of credit you have";
const float TEST_FLOAT_VALUE = 100.23f;

const std::string TEST_WRONG_NAME = "wrong";

std::vector<std::string> TEST_ARGV{
    "test.exe",
    "--" + TEST_INT_FLAG,
    std::to_string(TEST_INT_VALUE),
    "-" + TEST_FLOAT_NAME,
    std::to_string(TEST_FLOAT_VALUE),
};
int TEST_ARGC = TEST_ARGV.size();


class CommandLineHandlerTest : public ::testing::Test {
    protected:
        TTC::CommandLineHandler handler{
            TEST_ARGC,
            TEST_ARGV,
        };

        TTC::PropertyFactory factory;

        void SetUp() override {
            handler.addProperty(factory.create(
                TTC::PropertyType::INTEGER,
                TEST_INT_NAME,
                TEST_INT_FLAG,
                TEST_INT_DESCRIPTION
            ));

            handler.addProperty(factory.create(
                TTC::PropertyType::FLOAT,
                TEST_FLOAT_NAME,
                TEST_FLOAT_FLAG,
                TEST_FLOAT_DESCRIPTION
            ));

            handler.parse();
        }
};


TEST_F(CommandLineHandlerTest, TestEmpty) {
    EXPECT_EQ(handler.getIntegerPropertyValue(TEST_INT_NAME), TEST_INT_VALUE);
    EXPECT_EQ(handler.getFloatPropertyValue(TEST_FLOAT_NAME), TEST_FLOAT_VALUE);
}


TEST_F(CommandLineHandlerTest, TestWrongName) {
    EXPECT_EQ(handler.getPropertyType(TEST_WRONG_NAME), TTC::PropertyType::NONE);
    EXPECT_THROW(handler.getIntegerPropertyValue(TEST_WRONG_NAME), std::invalid_argument);
    EXPECT_THROW(handler.getFloatPropertyValue(TEST_WRONG_NAME), std::invalid_argument);
}


TEST_F(CommandLineHandlerTest, TestWrongType) {
    EXPECT_THROW(handler.getIntegerPropertyValue(TEST_FLOAT_NAME), std::invalid_argument);
    EXPECT_THROW(handler.getFloatPropertyValue(TEST_INT_NAME), std::invalid_argument);
}