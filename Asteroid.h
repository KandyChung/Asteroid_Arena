#ifndef ASTEROID_H_
#define ASTEROID_H_
#include "Vector.h"
#include "Reshape.h"

/**
 * The structure of Asteroid
*/
typedef struct{
  vec2d_t pos; //Position of Asteroid
  vec2d_t dir; //Direction of Asteroid
  float r; // Radians of Asteroid
  float rc; //Current Asteroid rotation amount 
  float rd; //Rotation delta, drgess per second
  float vel; //Velocity of Asteroid
  bool isAsteroidDead; //Whether the Asteroid is destroy
}asteroid_t;

#define ASTEROID_RADIANS 40
#define SMALL_ASTEROID_RADIANS 20

#define MAX_DIRACTION 5
#define MIN_DIRACTION -5

#define MAX_SPEED 20
#define MIN_SPEED 10

#define NUM_ASTEROID 50
asteroid_t asteroid[NUM_ASTEROID];

//Generate the random x position of Asteroid
extern float set_asteroidX_random_position(int max, int min);
//Generate the random y position of Asteroid
extern float set_asteroidY_random_postion(int max, int min);
//The initial of the Asteroid
extern void asteroid_int(asteroid_t *ast);
//Draw the Asteroid
extern void asteroid_frame(asteroid_t *ast);
//Delete the Asteroid when it has been destroy
extern void delete_asteroid(asteroid_t *ast);

#endif //ASTEROID_H_