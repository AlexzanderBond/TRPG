//
// Created by creep on 1/21/2025.
//

#include "game_state.h"
#include "../action/action.h"
#include "../location/location.h"
#include <random>

#include "../entity/player.h"

rpg::game_state::game_state() {
    current_location = nullptr;
    previous_locations = std::stack<std::shared_ptr<rpg::location> >();
    this->rd = std::make_unique<std::random_device>();
    this->player = std::make_shared<rpg::living_entity>(std::make_shared<rpg::player>(100, 5));
}

void rpg::game_state::update_location(const std::shared_ptr<rpg::location> &location) {
    current_location = location;
}

void rpg::game_state::get_possible_actions(std::vector<std::shared_ptr<rpg::action>> &actions) const {
    if (this->current_location != nullptr)
        this->current_location->get_possible_actions(actions);
}

std::shared_ptr<rpg::location> rpg::game_state::get_current_location() const {
    return current_location;
}

std::shared_ptr<rpg::location> rpg::game_state::get_previous_location() const {
    if (previous_locations.empty()) {
        return nullptr;
    }

    return previous_locations.top();
}

uint32_t rpg::game_state::get_random_number(const uint32_t min, const uint32_t max) const {
    return (*rd)() % (max - min + 1) + min;
}

rpg::living_entity & rpg::game_state::get_player() const {
    return *this->player;
}
