#ifndef SHIP_H_
#define SHIP_H_
#include "Vector.h"
#include "Reshape.h"

typedef struct{
  vec2d_t pos;
  vec2d_t dir;
  int rc;  //current rotion amount
  int rd; //rotion delta, degrees per second 
  float vel;
}ship_t;

ship_t ship;

#define SHIP_RADIANS 30

extern void ship_int(ship_t *so);
extern void ship_frame(ship_t *so);
extern void particle_puff_frame(ship_t *so);

#endif //SHIP_H_