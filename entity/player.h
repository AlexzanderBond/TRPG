//
// Created by creep on 1/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

namespace rpg {

    class player: public entity {
    public:
        player(int32_t max_health,
            int32_t defense)
            : entity("Player", "The player for the game", max_health, defense) {
        }
    };

} // rpg

#endif //PLAYER_H
