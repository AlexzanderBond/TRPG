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
#include "../item/loot_table.h"

namespace rpg {
    class action;
}

namespace rpg {

class location {
protected:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<rpg::action>> possible_actions;
    std::vector<std::shared_ptr<rpg::creature>> possible_creatures;
    rpg::loot_table discoverable_items;

public:
    location(const std::string &name, const std::string &description,
             const std::vector<std::shared_ptr<rpg::action>> &possible_actions,
             std::vector<std::shared_ptr<rpg::creature>> possible_creatures,
             const rpg::loot_table &discoverable_items);

    virtual ~location();

    [[nodiscard]] std::string get_name();
    [[nodiscard]] std::string get_description();
    [[nodiscard]] std::vector<std::shared_ptr<rpg::creature>> get_possible_creatures();

    [[nodiscard]] std::shared_ptr<rpg::creature> get_random_creature(std::random_device& rd);

    std::vector<rpg::itemstack> discover_items(std::random_device &rd, int32_t rolls);

    virtual void get_possible_actions(std::vector<std::shared_ptr<rpg::action>> &vector);
};

} // rpg

#endif //LOCATION_H
