#define TEST_INT_NAME "money"
#define TEST_INT_FLAG "m"
#define TEST_INT_DESCRIPTION "The amount of money you have"
#define TEST_INT_VALUE 100

#define TEST_FLOAT_NAME "credit"
#define TEST_FLOAT_FLAG "c"
#define TEST_FLOAT_DESCRIPTION "The amount of credit you have"
#define TEST_FLOAT_VALUE 100.23f

#define TEST_WRONG_NAME "wrong"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>

#include "CommandLineHandler.hpp"
#include "PropertyFactory.hpp"
#include "IProperty.hpp"



std::vector<std::string> TEST_ARGV{
    "test.exe",
    std::string("--") + TEST_INT_FLAG,
    std::to_string(TEST_INT_VALUE),
    std::string("-") + TEST_FLOAT_NAME,
    std::to_string(TEST_FLOAT_VALUE),
};
int TEST_ARGC = TEST_ARGV.size();


class CommandLineHandlerTest : public ::testing::Test {
    protected:
        TTC::CommandLineHandler handler;

        void SetUp() override {
            handler.addProperty(TTC::PropertyFactory<int>().create(
                TEST_INT_NAME,
                TEST_INT_FLAG,
                TEST_INT_DESCRIPTION
            ));

            handler.addProperty(TTC::PropertyFactory<float>().create(
                TEST_FLOAT_NAME,
                TEST_FLOAT_FLAG,
                TEST_FLOAT_DESCRIPTION
            ));

            handler.parse(
                TEST_ARGC,
                TEST_ARGV
            );
        }
};


TEST_F(CommandLineHandlerTest, TestEmpty) {
    int intValue = GET_INT_VAL(handler, TEST_INT_NAME);
    float floatValue = GET_FLOAT_VAL(handler, TEST_FLOAT_NAME);
    EXPECT_EQ(intValue, TEST_INT_VALUE);
    EXPECT_EQ(floatValue, TEST_FLOAT_VALUE);
}


TEST_F(CommandLineHandlerTest, TestWrongName) {
    EXPECT_THROW(GET_INT_VAL(handler, TEST_WRONG_NAME), std::invalid_argument);
    EXPECT_THROW(GET_FLOAT_VAL(handler, TEST_WRONG_NAME), std::invalid_argument);
}


// TEST_F(CommandLineHandlerTest, TestWrongType) {
//     EXPECT_THROW(GET_INT_VAL(handler, TEST_FLOAT_NAME), std::invalid_argument);
//     EXPECT_THROW(GET_FLOAT_VAL(handler, TEST_INT_NAME), std::invalid_argument);
// }