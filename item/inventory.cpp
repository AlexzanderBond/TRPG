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

    void inventory::add_item(const std::shared_ptr<item> &item) {
        this->items.push_back({item, 1});
    }

    void inventory::remove_item(const std::shared_ptr<item> &item, const int32_t amount) {
        for (int32_t i = 0; i < this->items.size(); i++) {
            auto& is = this->items[i];

            if (is.item == item) {
                is.amount -= amount;

                if (is.amount <= 0) {
                    this->items.erase(this->items.begin() + i);
                }

                break;
            }
        }
    }

    void inventory::remove_item(const int32_t index, const int32_t amount) {
        this->items[index].amount -= amount;

        if (this->items[index].amount <= 0) {
            this->items.erase(this->items.begin() + index);
        }
    }


    itemstack inventory::get_item(const int32_t index) const {
        return this->items[index];
    }

    int32_t inventory::get_size() const {
        return this->size;
    }

    void inventory::print() {
        for (const auto &itemstack: this->items) {
            std::cout << itemstack << std::endl;
        }
    }

    std::ostream & operator<<(std::ostream &os, const itemstack &itemstack) {
        os << itemstack.amount << "x " << itemstack.item->get_name();
        return os;
    }

    std::ostream & operator<<(std::ostream &os, const inventory &inventory) {
        for (const auto &itemstack: inventory.items) {
            os << itemstack << std::endl;
        }

        return os;
    }
} // rpg