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
#include "../game/registries.h"
#include "../game/registry.h"
#include "../utility/format.h"

namespace rpg {
    template<typename ...Args>
    std::shared_ptr<rpg::action> register_action(Args... args) {
        std::shared_ptr<rpg::action> new_action = std::make_shared<rpg::action>(args...);
        action_registry.register_item(new_action->get_name(), new_action);
        return new_action; // Return the newly created action
    }

    inline const std::vector<std::string> EXPLORE_TEMPLATES = {
        "You stumble into a {}, and look around to your surroundings. {}",
        "You walk along and find a {}. After a moment you take in your surroundings. {}",
        "After wandering for a while you see a {}. You decide to go in and see what you can find. {}"
    };

    inline std::shared_ptr<rpg::action> EXPLORE = register_action("explore",
            "Explore the world.",
            [](const std::shared_ptr<game_state> &gs, const std::vector<std::string>&) {
                gs->update_location(location_registry.get("forest"));

                const auto& templates = EXPLORE_TEMPLATES;

                const uint32_t random_index = gs->get_random_number(0, static_cast<uint32_t>(templates.size() - 1));

                std::cout << rpg::format(templates[random_index], gs->get_current_location()->get_name(), gs->get_current_location()->get_description()) << std::endl;
            });

    inline std::shared_ptr<rpg::action> INVESTIGATE = register_action("investigate",
            "Investigate the world.",
            [](const std::shared_ptr<game_state> &gs, const std::vector<std::string>&) {
                std::cout << "Investigate" << std::endl;
            });

    inline std::shared_ptr<rpg::action> VIEW = register_action("view", "Look at something.", [](const std::shared_ptr<game_state> &gs, const std::vector<std::string>& args) {
                if (args.size() != 1) {
                    if (args[1] == "inventory") {
                        std::cout << std::endl << "Player Inventory:" << std::endl << *gs->get_player().get_inventory() << std::endl;
                    }
                } else {
                    std::cout << "What would you like to view?" << std::endl;
                }
            });
}

#endif //ACTIONS_H
