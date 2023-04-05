#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "constants.hpp"
#include "IntegerProperty.hpp"


const std::string TEST_NAME = "money";
const std::string TEST_FLAG = "m";
const std::string WRONG_NAME = "wall";
const std::string WRONG_FLAG = "w";
const std::string TEST_DESCRIPTION = "The amount of money you have";
const int TEST_VALUE = 0;
const int TEST_VALUE_FROM_STRING = 100;
const std::string EMPTY_STRING = " ";
const std::string CHARACTER_STRING = "a";

const std::string FLAG_PREFIX = std::string(1, TTC::FLAG_PREFIX);
const std::string FLAG_PREFIX_SHORT = 
            std::string(1, TTC::FLAG_PREFIX) + std::string(1, TTC::FLAG_PREFIX);


class IntegerPropertyTest : public ::testing::Test {
    protected:
        TTC::IntegerProperty property{
            TEST_NAME,
            TEST_FLAG,
            TEST_DESCRIPTION,
        };

        void SetUp() override {
        }
};


TEST(PropertyTest, TestHelpPrefix) {
    EXPECT_THROW(TTC::IntegerProperty property(
        TEST_NAME,
        TTC::HELP_FLAG,
        TEST_DESCRIPTION
    ), std::invalid_argument);
}

TEST(PropertyTest, TestHelpName) {
    EXPECT_THROW(TTC::IntegerProperty property(
        TTC::HELP_NAME,
        TEST_FLAG,
        TEST_DESCRIPTION
    ), std::invalid_argument);
}


TEST_F(IntegerPropertyTest, TestGetName) {
    EXPECT_EQ(property.getName(), TEST_NAME);
}

TEST_F(IntegerPropertyTest, TestCheckFlag) {
    EXPECT_EQ(property.checkFlag(FLAG_PREFIX + TEST_NAME), true);
    EXPECT_EQ(property.checkFlag(FLAG_PREFIX_SHORT + TEST_FLAG), true);
}

TEST_F(IntegerPropertyTest, TestWrongFlag) {
    EXPECT_EQ(property.checkFlag(FLAG_PREFIX + WRONG_NAME), false);
    EXPECT_EQ(property.checkFlag(FLAG_PREFIX_SHORT + WRONG_FLAG), false);
}

TEST_F(IntegerPropertyTest, TestSetValueFromAString) {
    property.fromString(std::to_string(TEST_VALUE_FROM_STRING));
    EXPECT_EQ(property.getValue(), TEST_VALUE_FROM_STRING);
}


TEST_F(IntegerPropertyTest, TestSetValueFromAStringWithSpaces) {
    property.fromString(EMPTY_STRING + std::to_string(TEST_VALUE_FROM_STRING) + EMPTY_STRING);
    EXPECT_EQ(property.getValue(), TEST_VALUE_FROM_STRING);
}

TEST_F(IntegerPropertyTest, TestSetValueFromAStringWithLetters) {
    property.fromString(EMPTY_STRING + std::to_string(TEST_VALUE_FROM_STRING) + CHARACTER_STRING);
    EXPECT_EQ(property.getValue(), TEST_VALUE_FROM_STRING);
}


TEST_F(IntegerPropertyTest, TestSetValueFromAStringStartWithLetters) {
    property.fromString(CHARACTER_STRING + std::to_string(TEST_VALUE_FROM_STRING));
    EXPECT_EQ(property.getValue(), 0);
}