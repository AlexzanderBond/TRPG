//
// Created by gameg on 1/20/2025.
//

#include "location.h"

#include "../action/actions.h"

namespace rpg {
    location::location(const std::string &name, const std::string &description, std::vector<std::shared_ptr<rpg::creature>> possible_creatures) {
        this->name = name;
        this->description = description;
        this->possible_creatures = std::move(possible_creatures);
    }


    location::~location() = default;

    std::string location::get_name() {
        return name;
    }

    std::string location::get_description() {
        return description;
    }

    std::vector<std::shared_ptr<rpg::creature>> location::get_possible_creatures() {
        return this->possible_creatures;
    }

    std::shared_ptr<rpg::creature> location::get_random_creature(std::random_device& rd) {
        return possible_creatures[rd() % possible_creatures.size()];
    }

    void location::get_possible_actions(std::vector<std::shared_ptr<rpg::action>> &vector) {
        vector.push_back(INVESTIGATE);
    }
} // rpg