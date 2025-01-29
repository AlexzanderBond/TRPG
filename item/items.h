//
// Created by creep on 1/27/2025.
//

#ifndef ITEMS_H
#define ITEMS_H
#include <memory>

#include "item.h"
#include "../game/registry.h"

namespace rpg {
    inline rpg::registry<std::string, std::shared_ptr<item>> item_registry;

    template<typename ...Args>
    std::shared_ptr<item> register_item(Args... args) {
        std::shared_ptr<item> new_item = std::make_shared<item>(args...);
        item_registry.register_item(new_item->get_name(), new_item);
        return new_item; // Return the newly created item
    }

    inline std::shared_ptr<item> WOLF_SKIN = register_item(1, "wolf skin");
}

#endif //ITEMS_H
