//
// Created by gameg on 1/20/2025.
//

#ifndef ENTITIES_H
#define ENTITIES_H
#include <memory>

#include "creature.h"
#include "hostile_creature.h"

namespace rpg {
    inline std::shared_ptr<rpg::creature> WOLF;
    inline std::shared_ptr<rpg::creature> TROLL;

    inline void register_entities() {
        WOLF = std::make_shared<rpg::hostile_creature>("wolf", "A cunning and ferocious predator, its piercing eyes and sharp fangs reveal its relentless instinct to hunt. Agile and primal, it prowls with deadly intent.", 100, 10);
        TROLL = std::make_shared<rpg::hostile_creature>("troll", "A massive, hulking brute of monstrous strength, with rugged skin like living stone. It's slow-witted but fiercely territorial, smashing anything that dares enter its domain.", 200, 20);
    }
}

#endif //ENTITIES_H
