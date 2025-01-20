//
// Created by creep on 1/18/2025.
//

#ifndef CREATURE_H
#define CREATURE_H
#include "entity.h"


namespace rpg {
    class creature: public entity {

    public:
        creature(const std::string &name, int32_t max_health);
        [[nodiscard]] virtual bool is_hostile() const = 0;
    };
}


#endif //CREATURE_H
