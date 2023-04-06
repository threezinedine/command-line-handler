#pragma once
#include <memory>
#include "IProperty.hpp"
#include "PropertyInclude.hpp"


namespace TTC {
    template <typename T>
    class PropertyFactory
    {
    public:
        std::shared_ptr<IProperty> create(
            const std::string& name,
            const std::string& flag,
            const std::string& description
        ){
            if (std::is_same<T, int>::value) {
                return std::make_shared<IntegerProperty>(name, flag, description);
            } else if (std::is_same<T, float>::value) {
                return std::make_shared<FloatProperty>(name, flag, description);
            } else if (std::is_same<T, std::string>::value) {
                return std::make_shared<StringProperty>(name, flag, description);
            } else {
                throw std::invalid_argument("Invalid property type");
            }
        }
    };
}