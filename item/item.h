//
// Created by creep on 1/24/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <cstdint>
#include <string>
#include <bits/allocator.h>
#include <bits/stl_vector.h>

namespace rpg {

class item {
private:

    int32_t id;
    std::string name;

public:
    item(int32_t id, const std::string &name);
    virtual ~item();
    bool operator==(const item& other) const;
};

} // rpg

#endif //ITEM_H
