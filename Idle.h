#ifndef IDLE_H_
#define IDLE_H_
#include "Asteroid.h"
#include "Reshape.h"
#include "Ship.h"
#include "Bullets.h"
#include "KeyboradController.h"

extern float g_last_time;

extern void update_game_state(asteroid_t *ast, float dt);
extern void update_bullets_state(ship_t *so, bullets_t *bul, float dt);
extern void on_idle();

#endif //IDLE_H_