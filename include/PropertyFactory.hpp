#pragma once
#include <memory>
#include "IProperty.hpp"
#include "PropertyType.hpp"


namespace TTC {
    class PropertyFactory
    {
    public:
        std::shared_ptr<IProperty> create(
            PropertyType type,
            const std::string& name,
            const std::string& flag,
            const std::string& description
        );
    };
}
