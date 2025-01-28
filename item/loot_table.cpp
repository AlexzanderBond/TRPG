//
// Created by creep on 1/27/2025.
//

#include "loot_table.h"

void rpg::loot_table::calculate_total_weight() {
    int32_t total_weight = 0;
    for (auto &item : items) {
        total_weight += item.weight;
    }
    this->total_weight = total_weight;
}

rpg::loot_table::loot_table(const std::vector<loot_item> &items) {
    this->items = items;
    this->total_weight = 0;
    calculate_total_weight();
}

std::vector<rpg::itemstack> rpg::loot_table::get_random_items(std::random_device &rd, int32_t rolls) {
    std::vector<itemstack> rolledItems;

    if (this->items.empty() || rolls <= 0) {
        return rolledItems;
    }

    for (uint32_t i = 0; i < rolls; i++) {
        const uint32_t roll = rd() % total_weight;

        uint32_t weight_so_far = this->items[0].weight;
        uint32_t item_index = 0;
        while (weight_so_far < roll) {
            weight_so_far += this->items[item_index++].weight;
        }

        bool item_added = false;
        for (auto& item: rolledItems) {
            if (item.item == this->items[roll].item) {
                item.amount++;
                item_added = true;
                break;
            }
        }

        if (!item_added) {
            rolledItems.emplace_back(this->items[roll].item, 1);
        }
    }
    return rolledItems;
}

std::ostream & rpg::operator<<(std::ostream &os, const loot_table &loot_table) {
    os << "Loot Table{";
    //TODO: Finish implementing the loottable print method
    return os;
}
