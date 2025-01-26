//
// Created by creep on 1/24/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include <cstdint>
#include <memory>
#include <vector>

#include "item.h"

namespace rpg {

    struct itemstack {
        std::shared_ptr<item> item;
        int32_t amount;

        friend std::ostream& operator<<(std::ostream& os, const itemstack& itemstack);
    };

class inventory {
protected:
    std::vector<itemstack> items;
    int32_t size;

public:
    explicit inventory(int32_t size);

    void add_item(const std::shared_ptr<item> &item);
    void remove_item(const std::shared_ptr<item>& item, int32_t amount = -1);
    void remove_item(int32_t index, int32_t amount = -1);
    [[nodiscard]] itemstack get_item(int32_t index) const;
    [[nodiscard]] int32_t get_size() const;
    void print();

    friend std::ostream& operator<<(std::ostream& os, const inventory& inventory);
};

} // rpg

#endif //INVENTORY_H
