cmake_minimum_required(VERSION 3.30)
project(TRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(TRPG main.cpp
        entity/entity.cpp
        entity/entity.h
        entity/living_entity.cpp
        entity/living_entity.h
        entity/creature.cpp
        entity/creature.h)
