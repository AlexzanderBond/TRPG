//
// Created by gameg on 1/20/2025.
//

#ifndef LOCATION_H
#define LOCATION_H
#include <memory>
#include <string>
#include <vector>
#include <random>

#include "../entity/creature.h"

namespace rpg {

class location {
protected:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<rpg::creature>> possible_creatures;

public:
    location(const std::string &name, const std::string &description,
             std::vector<std::shared_ptr<rpg::creature>> possible_creatures);

    virtual ~location();

    [[nodiscard]] std::string get_name();
    [[nodiscard]] std::string get_description();
    [[nodiscard]] std::vector<std::shared_ptr<rpg::creature>> get_possible_creatures();

    [[nodiscard]] std::shared_ptr<rpg::creature> get_random_creature(std::random_device& rd);
};

} // rpg

#endif //LOCATION_H
