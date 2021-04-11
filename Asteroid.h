#ifndef ASTEROID_H_
#define ASTEROID_H_
#include "Vector.h"
#include "Reshape.h"

typedef struct{
  vec2d_t pos;
  vec2d_t dir;
  float r;
  float rc; //current rotation amount 
  float rd; //rotation delta, drgess per second
  float vel;
  bool isAsteroidDead;
}asteroid_t;

#define ASTEROID_RADIANS 30

#define MOVING_RIGHT_UP 1
#define MOVING_LEFT_DOWN -1

#define NUM_ASTEROID 10
asteroid_t asteroid[NUM_ASTEROID];

extern float set_asteroidX_random_position(int max, int min);
extern float set_asteroidY_random_postion(int max, int min);
extern int diractionX(asteroid_t *ast);
extern int diractionY(asteroid_t *ast);
extern void asteroid_int(asteroid_t *ast);
extern void asteroid_frame(asteroid_t *ast);
extern void delet_asteroid(asteroid_t *ast);

#endif //ASTEROID_H_