//
// Created by creep on 1/21/2025.
//

#ifndef ACTIONS_H
#define ACTIONS_H

#include <format>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <cstring>

#include "action.h"
#include "../location/locations.h"

namespace rpg {
    inline const std::vector<std::string> EXPLORE_TEMPLATES = {
        "You stumble into a %s, and look around to your surroundings. %s"
    };
    std::shared_ptr<rpg::action> EXPLORE;

    inline void register_actions() {
        EXPLORE = std::make_shared<rpg::action>(
            "Explore",
            "Explore the world.",
            [](std::shared_ptr<game_state> gs, const std::vector<std::string>&) {
                gs->update_location(FOREST_LOCATION);

                const auto& templates = EXPLORE_TEMPLATES;

                uint32_t random_index = gs->get_random_number(0, static_cast<uint32_t>(templates.size() - 1));

                char buffer[1024];
                std::sprintf(buffer, templates[random_index].c_str(),
                    FOREST_LOCATION->get_name().c_str(),
                    FOREST_LOCATION->get_description().c_str());
                std::cout << buffer << std::endl;
            });
    }
}

#endif //ACTIONS_H
