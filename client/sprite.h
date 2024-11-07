#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>

#include "../common/coordinate.h"

struct sprite_t {
    uint8_t id_texture;  // tipo de textura -> enum del tipo de arma, piso, pato, etc. lo tomo y lo
                         // mapeo con el sprite -> crear un mapa -> despues se pasa a .yaml
    Coordinate coordinate;
};

#endif  // SPRITE_H
