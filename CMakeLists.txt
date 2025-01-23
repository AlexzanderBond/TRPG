cmake_minimum_required(VERSION 3.30)
project(TRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(TRPG main.cpp
        entity/entity.cpp
        entity/entity.h
        entity/living_entity.cpp
        entity/living_entity.h
        entity/creature.cpp
        entity/creature.h
        entity/entities.h
        location/location.cpp
        location/location.h
        entity/hostile_creature.cpp
        entity/hostile_creature.h
        location/locations.h
        action/action.cpp
        action/action.h
        action/actions.h
        game/game_state.cpp
        game/game_state.h
        utility/format.h
        utility/string.h
)
