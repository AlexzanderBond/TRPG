//
// Created by gameg on 1/20/2025.
//

#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <memory>

#include "location.h"
#include "../entity/entities.h"

namespace rpg {
    inline std::shared_ptr<location> FOREST_LOCATION;

    inline void register_locations() {
        std::vector<std::shared_ptr<rpg::creature>> possible_creatures = {WOLF, TROLL};

        FOREST_LOCATION = std::make_shared<rpg::location>("Forest", "A dense and mysterious forest", possible_creatures);
    }
}

#endif //LOCATIONS_H
