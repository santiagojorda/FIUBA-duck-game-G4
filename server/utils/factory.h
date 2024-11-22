#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <iostream>

template <typename T1, typename T2>
class Factory {
protected:
    // cppcheck-suppress unusedStructMember
    std::map<T1, T2*> map;

public:
    explicit Factory() {}

    Factory(Factory&& other) noexcept : map(std::move(other.map)) {}
    
    T2* get(const T1& item_id){
        return map[item_id];
    }

    void add(const T1& item_id, T2* item) {
        map[item_id] = item;
    }

    ~Factory() {
        for (auto& item: map) {
            delete item.second;
        }
        map.clear();
    }
};

#endif  // EVENT_FACTORY_h
