//
// Created by creep on 1/18/2025.
//

#ifndef LIVING_ENTITY_H
#define LIVING_ENTITY_H
#include <memory>

#include "entity.h"
#include "../item/inventory.h"

namespace rpg {

class living_entity {
protected:
    std::shared_ptr<entity> entity;
    int32_t health;
    std::unique_ptr<inventory> inv;

public:
    explicit living_entity(const std::shared_ptr<rpg::entity> &entity);

    virtual ~living_entity() = default;

    [[nodiscard]] int32_t get_health() const;
    [[nodiscard]] bool is_alive() const;
    [[nodiscard]] bool is_dead() const;
    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] std::string get_description() const;
    [[nodiscard]] int32_t get_max_health() const;
    [[nodiscard]] int32_t get_defense() const;
    [[nodiscard]] inventory& get_inventory() const;
    void set_health(int32_t health);

    virtual void take_damage(int32_t damage);
};

} // rpg

#endif //LIVING_ENTITY_H
