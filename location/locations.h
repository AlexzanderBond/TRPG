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

    /**
     * PC stands for possible_creatures
     * Returns a vector containing shared pointers to creatures.
     * This is a helper method to remove ambiguity for an array initializer.
     *
     * @param creatures A vector of shared pointers to rpg::creature objects.
     * @return A vector of shared pointers to rpg::creature objects.
     */
    inline std::vector<std::shared_ptr<rpg::creature>> pc(const std::vector<std::shared_ptr<rpg::creature>>& creatures) {
        return creatures;
    }

    inline void register_locations() {
        FOREST_LOCATION = std::make_shared<rpg::location>("forest", "You see a dense and mysterious forest, enthralled with life. You hear some rustling around you. Do you want to investigate or will you leave it a mystery.", pc({WOLF, TROLL}));
    }
}

#endif //LOCATIONS_H
