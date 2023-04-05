#include <memory>
#include "IProperty.hpp"
#include "PropertyType.hpp"
#include "PropertyFactory.hpp"
#include "IntegerProperty.hpp"
#include "FloatProperty.hpp"
#include "StringProperty.hpp"


namespace TTC {
    std::shared_ptr<IProperty> PropertyFactory::create(
        PropertyType type,
        const std::string& name,
        const std::string& flag,
        const std::string& description
    ) {
        switch (type) {
            case PropertyType::INTEGER:
                return std::make_shared<IntegerProperty>(name, flag, description);
            case PropertyType::STRING:
                return std::make_shared<StringProperty>(name, flag, description);
            default:
                return std::make_shared<FloatProperty>(name, flag, description);
        }
    }
}