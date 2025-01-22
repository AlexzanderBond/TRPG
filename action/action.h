//
// Created by creep on 1/21/2025.
//

#ifndef ACTION_H
#define ACTION_H
#include <functional>
#include <string>

namespace rpg {

    class action {
    protected:
        std::string name;
        std::string description;
        std::function<void(std::vector<std::string>)> action_function;

    public:
        action(const std::string &name, const std::string &description, const std::function<void(std::vector<std::string>)> &action_function);
        virtual ~action();

        [[nodiscard]] std::string get_name() const;
        [[nodiscard]] std::string get_description() const;
        void execute(const std::vector<std::string> &args) const;

        void operator()(const std::vector<std::string> &args) const;
    };

} // rpg

#endif //ACTION_H
