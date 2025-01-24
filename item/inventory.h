//
// Created by creep on 1/24/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include <cstdint>
#include <vector>

#include "item.h"

namespace rpg {

class inventory {
protected:
    std::vector<item> items;
    int32_t size;

public:
    inventory(int32_t size);

    void add_item(item item);
    void remove_item(item item);
    void remove_item(int32_t index);
    [[nodiscard]] item get_item(int32_t index) const;
    [[nodiscard]] int32_t get_size() const;
    void print();
};

} // rpg

#endif //INVENTORY_H
