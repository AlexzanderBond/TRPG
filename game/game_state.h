//
// Created by creep on 1/21/2025.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <stack>

#include "../location/location.h"


namespace rpg {
    class game_state {
    protected:
        rpg::location current_location;
        std::stack<rpg::location> previous_locations;

    public:
        void update_location(rpg::location location);
    };
}



#endif //GAME_STATE_H
