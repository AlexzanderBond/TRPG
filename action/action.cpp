//
// Created by creep on 1/21/2025.
//

#include "action.h"

namespace rpg {
    action::action(const std::string &name, const std::string &description,
        const std::function<void(std::vector<std::string>)> &action_function) {
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

    void action::execute(const std::vector<std::string> &args) const {
        action_function(args);
    }

    void action::operator()(const std::vector<std::string> &args) const {
        execute(args);
    }
} // rpg