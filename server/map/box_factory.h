#ifndef BOX_FACTORY_H
#define BOX_FACTORY_H

#include <map>
#include <memory>
#include "box.h"
#include <functional>
#include "../../common/boxes_id.h"

class BoxFactory {
private:
    std::map<BoxesTextureID, std::function<std::shared_ptr<Box>(Coordinate)>> map_boxes;
public:
    BoxFactory(){
        map_boxes[BoxesTextureID::DEFAULT] = [](Coordinate c) { return std::make_shared<Box>(c); };
    }

    std::shared_ptr<Box> create_box(const int& id_box, const Coordinate& _coordinate) {
        return map_boxes[static_cast<BoxesTextureID>(id_box)](_coordinate);
    }


    ~BoxFactory() {}
};


#endif  // BOX_FACTORY_H
