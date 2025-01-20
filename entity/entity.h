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
    int32_t max_health;

public:
    entity(const std::string &name, int32_t max_health);
    virtual ~entity();

    std::string get_name();
    int32_t get_max_health() const;
};

} // rpg

#endif //ENTITY_H
