//
// Created by creep on 1/18/2025.
//

#include "entity.h"

namespace rpg {
    entity::entity(const std::string &name, const int32_t max_health) {
        this->name = name;
        this->max_health = max_health;
    }

    entity::~entity() = default;

    std::string entity::get_name() {
        return name;
    }

    int32_t entity::get_max_health() const {
        return max_health;
    }
} // rpg