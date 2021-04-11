#ifndef COLLISIONDETECTION_H_
#define COLLISIONDETECTION_H_
#include "Ship.h"
#include "Asteroid.h"
#include "Bullets.h"

extern void red_line_box_frame();
extern void game_box_frame();
extern bool is_close_collision(ship_t *so);
extern bool is_collied_ship(ship_t *so, asteroid_t *ast);
extern bool is_collied_bullets(bullets_t *bul, asteroid_t *ast);
extern bool is_collided_wall(ship_t *so);

#endif //COLLISIONDETECTION_H_