#include "bullet.h"

#include <cmath>
#include <iostream>

#define TEXTURE_ID 0  // cambiar
#define HORIZONTAL_STEP 4
#define VERTICAL_STEP 2

#define TICKS_PER_STEP 1

Bullet::Bullet(const ProjectileRange& _range_tiles, const Coordinate& _coordinate,
               const Direction& _direction, const int& _dispersion_angle):
        Projectile(TEXTURE_ID, _range_tiles, _coordinate, _direction),
        dispersion_angle(_dispersion_angle * M_PI / 180.0)  // lo pasa a radianes
{
    // std::cout << "Bullet was created with position: " << space.get_coordinates() << std::endl;
    // std::cout << "Dispersion angle: " << (int)dispersion_angle << std::endl;
}


void Bullet::update(GamePhysics& physics) {
    (void)physics;
    tick++;

    if ((steps * HORIZONTAL_STEP) / (16) >= int(range_tiles)) {
        state = ProjectileState::DEAD;
        std::cout << "Bala muere, completo su rango" << std::endl;
        return;
    }

    if (tick % TICKS_PER_STEP == 0) {
        steps++;
        double new_x = HORIZONTAL_STEP * std::cos(dispersion_angle);  // Velocidad inicial en X
        double new_y = VERTICAL_STEP * std::sin(dispersion_angle);    // Velocidad inicial en Y
        // deberia chequear que se pueda (colision)

        if (direction == Direction::RIGHT) {
            new_x = (-1) * new_x;
        }

        translate_x(static_cast<int>(std::round(new_x)));
        translate_y(static_cast<int>(std::round(new_y)));

        // std::cout << "new bullet position: " << space.get_coordinates() << std::endl;
    }
}
