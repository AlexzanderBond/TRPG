//
// Created by creep on 1/18/2025.
//

#include "creature.h"

rpg::creature::creature(const std::string &name, const std::string& description, const int32_t max_health, const int32_t defense) : entity(name, description, max_health, defense) {
}
