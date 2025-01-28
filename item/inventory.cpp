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

    bool inventory::add_item(const std::shared_ptr<item> &item) {
        size_t last_empty_slot = size;

        for (int i = 0; i < this->items.size(); i++) {
            if (!this->items[i].is_valid() && i < last_empty_slot) {
                last_empty_slot = i;
            } else if (this->items[i].item == item) {
                this->items[i].amount++;
                return true;
            }
        }

        if (last_empty_slot >= size) {
            return false;
        }

        this->items[last_empty_slot].item = item;
        this->items[last_empty_slot].amount = 1;
        return true;
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
        if (itemstack.is_valid())
            os << itemstack.amount << "x " << itemstack.item->get_name();
        return os;
    }

    std::ostream & operator<<(std::ostream &os, const inventory &inventory) {
        for(size_t i = 0; i < inventory.items.size(); i++) {
            os << (i+1) << ": ";

            if (inventory.items[i].is_valid()) {
                os << inventory.items[i];
            } else {
                os << "Empty";
            }

            os << std::endl;
        }

        return os;
    }
} // rpg