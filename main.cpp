#include <iostream>

#include "action/actions.h"
#include "entity/entities.h"
#include "location/locations.h"

int main() {
    rpg::register_entities();
    rpg::register_locations();
    rpg::register_actions();

    std::shared_ptr<rpg::game_state> gs = std::make_shared<rpg::game_state>();

    (*rpg::EXPLORE)(gs, {});

    return 0;
}
