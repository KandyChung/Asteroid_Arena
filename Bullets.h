#ifndef BULLETS_H_
#define BULLETS_H_
#include "Vector.h"
#include "Reshape.h"
#include "Ship.h"

/**
 * The structure of Bullets
*/
typedef struct{
  vec2d_t pos; //Position of Bullets
  vec2d_t dir; //Direction of Bullets
  float vel; //Velocity of Bullets
  float r, g, b; //Color of Bullets
  int size; //Size of Bullets
  int rc; //Current Bullets rotation amount
  bool isBulletDead; //Whether the Bullets is destroy
}bullets_t;

#define NUM_BULLETS 5
bullets_t bullets[NUM_BULLETS];

//The initial of Bullets
extern void bullets_int(bullets_t *bul);
//Draw the Bullets
extern void bullets_frame(bullets_t *bul);
//Delete the bullets when it has been destroy
extern void delete_bullets(bullets_t *bul);

#endif //BULLETS_H_