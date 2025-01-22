//
// Created by creep on 1/21/2025.
//

#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "action.h"

namespace rpg {
    std::shared_ptr<rpg::action> EXPLORE;

    inline void register_actions() {
        EXPLORE = std::make_shared<rpg::action>("Explore", "Explore the world.", [](const std::vector<std::string>&) {
            std::cout << "You explore the world." << std::endl;
        });
    }
}

#endif //ACTIONS_H
