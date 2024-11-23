#include "gun_factory.h"

#include <functional>
#include <map>

#include "../../common/weapons_id.h"

#include "duks_guns/ak_47.h"
#include "duks_guns/banana.h"
#include "duks_guns/cowboy_gun.h"
#include "duks_guns/dueling_gun.h"
#include "duks_guns/granade.h"
#include "duks_guns/laser_rifle.h"
#include "duks_guns/magnum.h"
#include "duks_guns/pew_pew_laser.h"
#include "duks_guns/shotgun.h"
#include "duks_guns/sniper.h"

std::map<WeaponTextureID, std::function<Gun*(Coordinate)>> map_guns;

GunFactory::GunFactory() {
    // map_guns[WeaponTextureID::GRANATE] = [](Coordinate c) { return new Granade(c); };
    // map_guns[WeaponTextureID::BANANA] = [](Coordinate c) { return new Banana(c); };
    // map_guns[WeaponTextureID::PEW_PEW_LASER] = [](Coordinate c) { return new PewPewLaser(c); };
    // map_guns[WeaponTextureID::LASER_RIFLE] = [](Coordinate c) { return new LaserRifle(c); };
    map_guns[WeaponTextureID::AK_47] = [](Coordinate c) { return new AK47(c); };
    // map_guns[WeaponTextureID::DUELING_GUN] = [](Coordinate c) { return new DuelingGun(c); };
    // map_guns[WeaponTextureID::COWBOY_GUN] = [](Coordinate c) { return new CowboyGun(c); };
    // map_guns[WeaponTextureID::MAGNUM] = [](Coordinate c) { return new Magnum(c); };
    // map_guns[WeaponTextureID::SHOTGUN] = [](Coordinate c) { return new Shotgun(c); };
    // map_guns[WeaponTextureID::SNIPER] = [](Coordinate c) { return new Sniper(c); };
}


Gun* GunFactory::create_gun(const int& id_weapon, const Coordinate& _coordinate) {
    return map_guns[static_cast<WeaponTextureID>(id_weapon)](_coordinate);
}


GunFactory::~GunFactory() {}
