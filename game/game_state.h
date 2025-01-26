//
// Created by creep on 1/21/2025.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <stack>
#include <memory>

#include "../entity/living_entity.h"
#include "../location/location.h"


namespace rpg {
    class action;
}

namespace rpg {
    class game_state {
    protected:
        std::shared_ptr<rpg::location> current_location;
        std::stack<std::shared_ptr<rpg::location>> previous_locations;
        std::unique_ptr<std::random_device> rd;
        std::shared_ptr<rpg::living_entity> player;

    public:
        game_state();
        ~game_state() = default;
        void update_location(const std::shared_ptr<rpg::location> &location);

        void get_possible_actions(std::vector<std::shared_ptr<rpg::action>> &actions) const;

        [[nodiscard]] std::shared_ptr<rpg::location> get_current_location() const;
        [[nodiscard]] std::shared_ptr<rpg::location> get_previous_location() const;
        [[nodiscard]] uint32_t get_random_number(uint32_t min, uint32_t max) const;
        [[nodiscard]] rpg::living_entity& get_player() const;
    };
}



#endif //GAME_STATE_H
