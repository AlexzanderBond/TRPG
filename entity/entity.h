//
// Created by creep on 1/18/2025.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <cstdint>
#include <string>

namespace rpg {

class entity {
protected:
    std::string name;
    std::string description;
    int32_t max_health;
    int32_t defense;

public:
    entity(const std::string &name, const std::string& description, int32_t max_health, int32_t defense);
    virtual ~entity();

    std::string get_name();
    std::string get_description();
    [[nodiscard]] int32_t get_max_health() const;
    [[nodiscard]] int32_t get_defense() const;
};

} // rpg

#endif //ENTITY_H
