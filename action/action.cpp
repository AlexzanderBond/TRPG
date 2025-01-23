//
// Created by creep on 1/21/2025.
//

#include "action.h"

#include <utility>

namespace rpg {
    action::action(const std::string &name, const std::string &description,
        const std::function<void(std::shared_ptr<game_state>, std::vector<std::string>)> &action_function) {
        this->name = name;
        this->description = description;
        this->action_function = action_function;
    }

    action::~action() = default;

    std::string action::get_name() const {
        return name;
    }

    std::string action::get_description() const {
        return description;
    }

    void action::execute(std::shared_ptr<game_state> gs, const std::vector<std::string> &args) const {
        action_function(std::move(gs), args);
    }

    void action::operator()(std::shared_ptr<game_state> gs, const std::vector<std::string> &args) const {
        execute(std::move(gs), args);
    }
} // rpg