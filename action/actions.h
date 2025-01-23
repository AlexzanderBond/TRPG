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
#include "../utility/format.h"

namespace rpg {
    inline const std::vector<std::string> EXPLORE_TEMPLATES = {
        "You stumble into a {}, and look around to your surroundings. {}",
        "You walk along and find a {}. After a moment you take in your surroundings. {}",
        "After wandering for a while you see a {}. You decide to go in and see what you can find. {}"
    };
    inline std::shared_ptr<rpg::action> EXPLORE;
    inline std::shared_ptr<rpg::action> INVESTIGATE;

    inline void register_actions() {
        EXPLORE = std::make_shared<rpg::action>(
            "Explore",
            "Explore the world.",
            [](const std::shared_ptr<game_state> &gs, const std::vector<std::string>&) {
                gs->update_location(FOREST_LOCATION);

                const auto& templates = EXPLORE_TEMPLATES;

                uint32_t random_index = gs->get_random_number(0, static_cast<uint32_t>(templates.size() - 1));

                std::cout << rpg::format(templates[random_index], gs->get_current_location()->get_name(), gs->get_current_location()->get_description()) << std::endl;
            });

        INVESTIGATE = std::make_shared<rpg::action>(
            "Investigate",
            "Investigate the world.",
            [](const std::shared_ptr<game_state> &gs, const std::vector<std::string>&) {
                std::cout << "Investigate" << std::endl;
            });
    }
}

#endif //ACTIONS_H
