#ifndef LIST_FLOORS_H
#define LIST_FLOORS_H

#include "../utils/list_generic.h"
#include "ground.h"

class ListFloors: public ListGeneric<Ground> {

public:
    ListFloors() = default;
    ~ListFloors() = default;
};

#endif