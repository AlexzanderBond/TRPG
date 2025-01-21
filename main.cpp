#include <iostream>

#include "entity/entities.h"

int main() {
    rpg::register_entities();

    std::cout << rpg::WOLF->get_description() << std::endl;
    return 0;
}
