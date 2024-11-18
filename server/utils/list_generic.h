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

    bool remove(T* item) {
        bool item_exist = false;
        items.remove_if([item, &item_exist](T* item_list) {
            if (item == item_list) {
                item_exist = true;
                return true;
            }
            return false;
        });
        return item_exist;
    }

    void remove_and_delete(T* item) {
        bool item_exist = remove(item);
        if (item_exist) {
            delete item;
        }
    };
    
    void transfer_item(T* item, ListGeneric<T>& other_list){
        add(item);
        other_list.remove(item);
    }

    void clear() {
        for (auto* item: items) {
            delete item;
        }
        items.clear();
    }

    int size() { return items.size(); }

    const std::list<T*>& get_items() const { return items; }

    ~ListGeneric() { clear(); }
};

#endif
