//
// Created by creep on 1/18/2025.
//

#ifndef CREATURE_H
#define CREATURE_H
#include "entity.h"


namespace rpg {

    class creature: public entity {
    public:
        creature(const std::string &name, const std::string& description, int32_t max_health, int32_t defense);
        ~creature() override = default;
        [[nodiscard]] virtual bool is_hostile() const = 0;

        friend std::ostream &operator<<(std::ostream &os, const creature &creature);
    };

}


#endif //CREATURE_H
