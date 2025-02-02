//
// Created by creep on 1/27/2025.
//

#ifndef LOOT_TABLE_H
#define LOOT_TABLE_H
#include <cstdint>
#include <memory>
#include <vector>
#include <random>

#include "inventory.h"
#include "item.h"


namespace rpg {
    struct loot_item {
        uint32_t weight;
        std::shared_ptr<item> item;
    };

    class loot_table {
    protected:
        std::vector<loot_item> items;
        uint32_t total_weight = 0;

        void calculate_total_weight();

    public:
        loot_table() = default;
        explicit loot_table(const std::vector<loot_item> &items);
        [[nodiscard]] std::vector<rpg::itemstack> get_random_items(std::random_device& rd, int32_t rolls);

        friend std::ostream& operator<<(std::ostream& os, const loot_table& loot_table);
    };
}



#endif //LOOT_TABLE_H
