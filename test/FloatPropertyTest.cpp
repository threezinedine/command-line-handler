#include <gtest/gtest.h>
#include "FloatProperty.hpp"


const std::string TEST_NAME = "temperature";
const std::string TEST_FLAG = "t";
const std::string TEST_DESCRIPTION = "temperature in degrees celsius";
const float TEST_VALUE = 100.23f;
const std::string EMPTY_STRING = " ";
const std::string CHARACTER_STRING = "a";


class FloatPropertyTest : public ::testing::Test {
    protected:
        TTC::FloatProperty property{
            TEST_NAME,
            TEST_FLAG,
            TEST_DESCRIPTION,
        };

        void SetUp() override {
        }
};


TEST_F(FloatPropertyTest, TestGetValueFromAString) {
    property.fromString(std::to_string(TEST_VALUE));
    EXPECT_EQ(property.getValue(), TEST_VALUE);
}


TEST_F(FloatPropertyTest, TestGetValueFromAStringWithSpaces) {
    property.fromString(EMPTY_STRING + std::to_string(TEST_VALUE) + EMPTY_STRING);
    EXPECT_EQ(property.getValue(), TEST_VALUE);
}


TEST_F(FloatPropertyTest, TestGetValueFromAStringWithCharacters) {
    property.fromString(CHARACTER_STRING + std::to_string(TEST_VALUE) + CHARACTER_STRING);
    EXPECT_EQ(property.getValue(), 0);
}