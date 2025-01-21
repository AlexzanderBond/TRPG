//
// Created by gameg on 1/20/2025.
//

#ifndef HOSTILE_CREATURE_H
#define HOSTILE_CREATURE_H
#include "creature.h"

namespace rpg {

class hostile_creature: public creature {
public:
    hostile_creature(const std::string &name, const std::string &description, int32_t max_health, int32_t defense)
        : creature(name, description, max_health, defense) {
    }

    ~hostile_creature() override = default;

    [[nodiscard]] bool is_hostile() const override { return true; }
};

} // rpg

#endif //HOSTILE_CREATURE_H
