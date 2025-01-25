//
// Created by creep on 1/24/2025.
//

#include "item.h"

namespace rpg {
    item::item(const int32_t id, const std::string &name) {
        this->id = id;
        this->name = name;
    }

    item::~item() = default;

    bool item::operator==(const item &other) const {
        return this->id == other.id;
    }
} // rpg