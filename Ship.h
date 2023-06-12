#ifndef SHIP_H_
#define SHIP_H_
#include "Vector.h"
#include "Reshape.h"

/**
 * The structure of the Ship
 */
typedef struct{
  vec2d_t pos; //Position of the Ship
  vec2d_t dir; //Diraction of the Ship
  int rc;  //Current Ship rotion amount
  int rd; //Rotion delta, degrees per second 
  float vel; // Velocity of the Ship
  bool is_ship_dead; //Whether the ship is destroy
}ship_t;

ship_t ship;

#define SHIP_RADIANS 15

//The initial of the ship
extern void ship_int(ship_t *so);
// Draw the ship
extern void ship_frame(ship_t *so);
//Draw the particle puff for the ship
extern void particle_puff_frame(ship_t *so);

#endif //SHIP_H_