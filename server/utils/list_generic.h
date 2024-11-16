#ifndef LIST_GENERIC
#define LIST_GENERIC

#include <cstdint>
#include <list>

template <typename T>
class ListGeneric {
private:
    std::list<T*> items; 
                        
public:
    ListGeneric() {}

    void add(T* item) { items.push_back(item); }

    void remove(T* item) {
        items.remove_if([item](T* item_list) {
            if (item == item_list) { 
                delete item;  
                return true; 
            }
            return false;
        });
    };

    void clear() {
        for (auto* item: items) {
            delete item;
        }
    }

    int size() { return items.size(); }

    const std::list<T*>& get_items() const { return items; }

    ~ListGeneric() { clear(); }
};

#endif
