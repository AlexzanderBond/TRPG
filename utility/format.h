//
// Created by creep on 1/23/2025.
//

#ifndef FORMAT_H
#define FORMAT_H

#include <string>

namespace rpg {
    template <typename... Args>
    std::string format(const std::string &format, Args&&... args);
}

namespace helper {
    // Helper function to process a single argument and convert it to a string
    template <typename T>
    std::string to_string_helper(T&& arg) {
        std::ostringstream oss;
        oss << arg;
        return oss.str();
    }

    // Base case: no arguments left
    inline void process_placeholders(std::ostringstream& oss, const std::string& format, const size_t& pos) {
        // Append the rest of the format string
        oss << format.substr(pos);
    }

    // Variadic case: process arguments one by one
    template <typename T, typename... Args>
    void process_placeholders(std::ostringstream& oss, const std::string& format, size_t& pos, T&& first, Args&&... rest) {
        while (pos < format.size()) {
            if (format[pos] == '{' && (pos + 1 < format.size()) && format[pos + 1] == '}') {
                // Replace placeholder
                oss << to_string_helper(std::forward<T>(first));
                pos += 2; // Skip past "{}"
                // Recurse to process the remaining arguments
                process_placeholders(oss, format, pos, std::forward<Args>(rest)...);
                return;
            } else {
                // Add regular character to result
                oss << format[pos];
                ++pos;
            }
        }

        // If we run out of format string but still have arguments, throw an error
        throw std::runtime_error("Too many arguments provided for format string");
    }
}

template <typename... Args>
std::string rpg::format(const std::string& format, Args&&... args) {
    std::ostringstream oss;
    size_t pos = 0;
    helper::process_placeholders(oss, format, pos, std::forward<Args>(args)...);

    // If there are still `{}` placeholders left in the format string, throw an error
    if (pos < format.size()) {
        for (size_t i = pos; i < format.size(); ++i) {
            if (format[i] == '{' && (i + 1 < format.size()) && format[i + 1] == '}') {
                throw std::runtime_error("Not enough arguments provided for format string");
            }
        }
    }

    return oss.str();
}

#endif //FORMAT_H
