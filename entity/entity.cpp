//
// Created by creep on 1/18/2025.
//

#include "entity.h"
#include <iostream>

namespace rpg {
    entity::entity(const std::string &name, const std::string& description, const int32_t max_health, const int32_t defense) {
        this->name = name;
        this->description = description;
        this->max_health = max_health;
        this->defense = defense;
    }

    entity::~entity() = default;

    std::string entity::get_name() {
        return name;
    }

    std::string entity::get_description() {
        return description;
    }

    int32_t entity::get_max_health() const {
        return max_health;
    }

    int32_t entity::get_defense() const {
        return defense;
    }

    std::ostream & operator<<(std::ostream &os, const entity &entity) {
        os << "Entity{Name=" << entity.name << ", Description=" << entity.description << ", Max Health=" << entity.max_health << ", Defense=" << entity.defense << "}";

        return os;
    }
} // rpg