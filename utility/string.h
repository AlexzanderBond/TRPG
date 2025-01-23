//
// Created by creep on 1/23/2025.
//

#ifndef STRING_H
#define STRING_H

#include <sstream>
#include <string>
#include <vector>

inline std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

#endif //STRING_H
