//
// Created by creep on 1/18/2025.
//

#include "living_entity.h"

#include "entity.h"

namespace rpg {
    living_entity::living_entity(const std::shared_ptr<rpg::entity> &entity) {
        this->entity = entity;
        this->health = this->entity->get_max_health();
    }

    int32_t living_entity::get_health() const {
        return health;
    }

    bool living_entity::is_alive() const {
        return health > 0;
    }

    bool living_entity::is_dead() const {
        return health <= 0;
    }

    std::string living_entity::get_name() const {
        return this->entity->get_name();
    }

    std::string living_entity::get_description() const {
        return this->entity->get_description();
    }

    int32_t living_entity::get_max_health() const {
        return this->entity->get_max_health();
    }

    int32_t living_entity::get_defense() const {
        return this->entity->get_defense();
    }

    void living_entity::set_health(const int32_t health) {
        this->health = health;
    }

    void living_entity::take_damage(const int32_t damage) {
        health -= (damage - this->entity->get_defense());
    }
} // rpg