#ifndef LIST_ITEMS_MAP_H
#define LIST_ITEMS_MAP_H

#include "../utils/list_generic.h"

#include "../attributes/equippable.h"

class ListItemsMap: public ListGeneric<Equippable> {

public:
    ListItemsMap() = default;
    ~ListItemsMap() = default;
};

#endif