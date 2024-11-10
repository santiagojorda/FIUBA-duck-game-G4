#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>

#include "../../common/coordinate.h"

struct sprite_t {
    uint8_t id_texture;  // ES EL PATH ! tipo de textura -> enum del tipo de arma, piso, pato, etc.
                         // lo tomo y lo mapeo con el sprite -> crear un mapa -> despues se pasa a
                         // .yaml -> elegir color del pato
    Coordinate coordinate;  // coordenadas con respecto a la pantalla
};

#endif  // SPRITE_H
