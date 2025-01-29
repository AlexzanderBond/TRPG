//
// Created by creep on 1/28/2025.
//

#ifndef REGISTRY_H
#define REGISTRY_H
#include <string>
#include <unordered_map>

namespace rpg {

    template<typename K, typename T>
    class registry {
    protected:
        std::unordered_map<K, T> m_registry;

    public:
        T &get(const K& key) {
            return m_registry.at(key);
        }
        void register_item(const K& key, T item) {
            m_registry[key] = item;
        }
        void unregister_item(const K& key) {
            m_registry.erase(key);
        }
        void clear() {
            m_registry.clear();
        }

        T& operator[](const K& key) {
            return get(key);
        }
    };
} // rpg

#endif //REGISTRY_H
