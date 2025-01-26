#include <iostream>

#include "action/actions.h"
#include "entity/entities.h"
#include "location/locations.h"
#include "utility/string.h"

int main() {
    rpg::register_entities();
    rpg::register_locations();
    rpg::register_actions();

    std::shared_ptr<rpg::game_state> gs = std::make_shared<rpg::game_state>();

    std::vector<std::shared_ptr<rpg::action>> possible_actions;

    std::vector default_actions = {rpg::EXPLORE, rpg::VIEW};

    possible_actions.insert(possible_actions.end(), default_actions.begin(), default_actions.end());

    while (true) {
        std::string input;

        std::cin >> input;

        std::vector<std::string> inputArgs = split(input, ' ');

        if (!inputArgs.empty()) {
            for (const auto& action : possible_actions) {
                if (action->get_name() == inputArgs[0]) {
                    action->execute(gs, inputArgs);
                }
            }
        }

        possible_actions.clear();
        possible_actions.insert(possible_actions.end(), default_actions.begin(), default_actions.end());
        gs->get_possible_actions(possible_actions);
    }

    return 0;
}
