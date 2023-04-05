#include <gtest/gtest.h>
#include "StringProperty.hpp"


const std::string TEST_NAME = "name";
const std::string TEST_FLAG = "n";
const std::string TEST_DESCRIPTION = "The name of the person";
const std::string TEST_VALUE = "John Doe";

class StringPropertyTest : public ::testing::Test {
    protected:
        TTC::StringProperty property{
            TEST_NAME,
            TEST_FLAG,
            TEST_DESCRIPTION,
        };

        void SetUp() override {
        }
};


TEST_F(StringPropertyTest, TestGetName) {
    EXPECT_EQ(property.getName(), TEST_NAME);
}

TEST_F(StringPropertyTest, TestGetValue) {
    property.fromString(TEST_VALUE);
    EXPECT_EQ(property.getValue(), TEST_VALUE);
}