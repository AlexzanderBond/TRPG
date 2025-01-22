//
// Created by creep on 1/18/2025.
//

#include "creature.h"
#include <iostream>

rpg::creature::creature(const std::string &name, const std::string& description, const int32_t max_health, const int32_t defense) : entity(name, description, max_health, defense) {
}

std::ostream & rpg::operator<<(std::ostream &os, const creature &creature) {
    os << "Creature{Name=" << creature.name << ", Description=" << creature.description << ", Max Health=" << creature.max_health << ", Defense=" << creature.defense << "}";
    return os;
}
