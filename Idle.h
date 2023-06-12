#ifndef IDLE_H_
#define IDLE_H_
#include "Asteroid.h"
#include "Reshape.h"
#include "Ship.h"
#include "Bullets.h"
#include "KeyboradController.h"

extern float g_last_time;

//Update the asteroid state
extern void update_asteroid_state(asteroid_t *ast, float dt);
//Update the bullets state
extern void update_bullets_state(bullets_t *bul, float dt);
extern void on_idle();

#endif //IDLE_H_