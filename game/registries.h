//
// Created by gameg on 1/28/2025.
//

#ifndef REGISTRIES_H
#define REGISTRIES_H
#include <memory>

#include "registry.h"
#include "../location/location.h"

namespace rpg {
    inline rpg::registry<std::string, std::shared_ptr<rpg::location>> location_registry;
    inline rpg::registry<std::string, std::shared_ptr<rpg::action>> action_registry;
    inline rpg::registry<std::string, std::shared_ptr<item>> item_registry;
}

#endif //REGISTRIES_H
