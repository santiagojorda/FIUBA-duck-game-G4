#ifndef STATE_DUCK_H
#define STATE_DUCK_H

enum states { JUMPING, RUNING, CROUNCH, RECOIL, SLIPING, PLANING, IDLE, DEATH };

enum states_frame {
    JUMPING_F = 6,
    RUNING_F = 6,
    CROUCH_F = 1,
    RECOIL_F = 3,
    SLIPING_F = 2,
    PLANING_F = 6,
    IDLE_F = 1,
    DEAHT_F = 1
};

#endif  // STATE_DUCK_H
