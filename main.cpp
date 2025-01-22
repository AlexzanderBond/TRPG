#include <iostream>

#include "action/actions.h"
#include "entity/entities.h"
#include "location/locations.h"

int main() {
    rpg::register_entities();
    rpg::register_locations();
    rpg::register_actions();

    std::random_device rd;

    std::cout << *rpg::FOREST_LOCATION->get_random_creature(rd) << std::endl;

    (*rpg::EXPLORE)({});

    return 0;
}
