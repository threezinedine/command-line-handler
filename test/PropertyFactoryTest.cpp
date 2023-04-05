#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "IProperty.hpp"
#include "PropertyFactory.hpp"
#include "PropertyType.hpp"
#include "IntegerProperty.hpp"
#include "FloatProperty.hpp"


const std::string TEST_NAME = "money";
const std::string TEST_FLAG = "m";
const std::string TEST_DESCRIPTION = "The amount of money you have";
const int TEST_INT_VALUE = 100;
const int TEST_FLOAT_VALUE = 100.0f;


class PropertyFactoryTest : public ::testing::Test {
    protected:
        TTC::PropertyFactory factory;

        void SetUp() override {
        }
};


TEST_F(PropertyFactoryTest, GenerateIntegerProperty) {
    std::shared_ptr<TTC::IProperty> property = factory.create(
        TTC::PropertyType::INTEGER,
        TEST_NAME,
        TEST_FLAG,
        TEST_DESCRIPTION
    );

    EXPECT_EQ(property->getName(), TEST_NAME);
    property->fromString(std::to_string(TEST_INT_VALUE));
    std::shared_ptr<TTC::IntegerProperty> intProperty = 
        std::static_pointer_cast<TTC::IntegerProperty>(property);
    EXPECT_EQ(intProperty->getValue(), TEST_INT_VALUE);
}


TEST_F(PropertyFactoryTest, GenerateFloatProperty) {
    std::shared_ptr<TTC::IProperty> property = factory.create(
        TTC::PropertyType::FLOAT,
        TEST_NAME,
        TEST_FLAG,
        TEST_DESCRIPTION
    );

    EXPECT_EQ(property->getName(), TEST_NAME);
    property->fromString(std::to_string(TEST_FLOAT_VALUE));
    std::shared_ptr<TTC::FloatProperty> floatProperty = 
        std::static_pointer_cast<TTC::FloatProperty>(property);
    EXPECT_EQ(floatProperty->getValue(), TEST_FLOAT_VALUE);
}