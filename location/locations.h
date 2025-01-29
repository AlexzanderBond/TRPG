//
// Created by gameg on 1/20/2025.
//

#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <memory>

#include "location.h"
#include "../entity/entities.h"
#include "../game/registry.h"

namespace rpg {
    inline rpg::registry<std::string, std::shared_ptr<rpg::location>> location_registry;

    template<typename ...Args>
    std::shared_ptr<location> register_location(Args... args) {
        std::shared_ptr<location> new_item = std::make_shared<location>(args...);
        location_registry.register_item(new_item->get_name(), new_item);
        return new_item; // Return the newly created item
    }

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

    inline std::shared_ptr<location> FOREST_LOCATION = register_location("forest", "A forested area with many trees and wildlife.", std::vector<std::shared_ptr<rpg::action>>({}), pc({WOLF, TROLL}), loot_table{});
}

#endif //LOCATIONS_H
