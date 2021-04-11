#ifndef BULLETS_H_
#define BULLETS_H_
#include "Vector.h"
#include "Reshape.h"
#include "Ship.h"


typedef struct{
  vec2d_t pos;
  vec2d_t dir;
  float vel;
  float lifespan;  
  float r, g, b; 
  int size;
  int rc;
  bool isBulletDead;
}bullets_t;

#define NUM_BULLETS 10
bullets_t bullets[NUM_BULLETS];

extern void bullets_int(bullets_t *bul, ship_t *so);
extern void bullets_frame(bullets_t *bul);

#endif //BULLETS_H_