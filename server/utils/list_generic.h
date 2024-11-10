#ifndef LIST_GENERIC
#define LIST_GENERIC

#include <list>
#include <cstdint>

template <typename T>
class ListGeneric { 
private:
    std::list<T*> items; // esta deberia ser otro objeto, llamado map_item porque positionable puede ser cualquiera
public:
    ListGeneric() {}

    void add(T* item) { items.push_back(item); }

    void remove(T* item) { 
        items.remove(item);
        delete item;
    };

    void clear(){
        for (auto* item : items){
            delete item;
        }    }

    ~ListGeneric() { clear();}
};

#endif
