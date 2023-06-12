#ifndef COLLISIONDETECTION_H_
#define COLLISIONDETECTION_H_
#include "Ship.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "Idle.h"

int score;
int num_asteroid_destroy;

//Check if the ship is close to the wall
extern bool is_close_collision(ship_t *so);
//Check if ship is collied with the asteroid
extern bool is_collied_ship(ship_t *so, asteroid_t *ast);
//Check if the bullets is collied with the asteroid
extern bool is_collied_bullets_and_asteroid(bullets_t *bul, asteroid_t *ast);
//Check is the ship is collied with the wall
extern bool is_collided_wall(ship_t *so);

#endif //COLLISIONDETECTION_H_