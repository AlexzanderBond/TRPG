//
// Created by creep on 1/24/2025.
//

#include "inventory.h"

#include <iostream>
#include <ostream>

namespace rpg {
    inventory::inventory(const int32_t size) {
        this->size = size;
        this->items.resize(size);
    }

    void inventory::add_item(const item item) {
        this->items.push_back(item);
    }

    void inventory::remove_item(const item item) {
        for (int32_t i = 0; i < this->items.size(); i++) {
            if (this->items[i] == item) {
                this->items.erase(this->items.begin() + i);
            }
        }
    }

    void inventory::remove_item(const int32_t index) {
        this->items.erase(this->items.begin() + index);
    }

    item inventory::get_item(const int32_t index) const {
        return this->items[index];
    }

    int32_t inventory::get_size() const {
        return this->size;
    }

    void inventory::print() {
        for (const auto &item: this->items) {
            std::cout << item << std::endl;
        }
    }
} // rpg