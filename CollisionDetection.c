#include "GLUTHeader.h"
#include "CollisionDetection.h"

int score = 0;
int num_asteroid_destroy = 0;

bool is_close_collision(ship_t *so)
{
  if(so->pos.y + SHIP_RADIANS + 10 < g_screen_height/2 && 
      so->pos.y - SHIP_RADIANS - 10 > -g_screen_height/2 && 
      so->pos.x + SHIP_RADIANS + 10 < g_screen_width/2 &&
      so->pos.x - SHIP_RADIANS - 10 > -g_screen_width/2)
  {
    return false;
  }
  return true;
}

bool is_collied_ship(ship_t *so, asteroid_t *ast)
{
  int ship_asteroid_dis = SHIP_RADIANS +  ASTEROID_RADIANS;
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if(so->pos.x - ast[i].pos.x > ship_asteroid_dis || ast[i].pos.x - so->pos.x > ship_asteroid_dis || 
    so->pos.y - ast[i].pos.y > ship_asteroid_dis || ast[i].pos.y - so->pos.y > ship_asteroid_dis)
    {
      return false;
    }
    fprintf(stderr, "collied ship: %d\n", i);
    return true;
  }
  return false;
}

bool is_collied_bullets_and_asteroid(bullets_t *bul, asteroid_t *ast)
{
  if (!ship.is_ship_dead)
  {
    for (int i = 0; i < NUM_ASTEROID; i++)
    {
      if(bul->pos.x - ast[i].pos.x > ASTEROID_RADIANS*2 || ast[i].pos.x - bul->pos.x > ASTEROID_RADIANS*2 || 
      bul->pos.y - ast[i].pos.y > ASTEROID_RADIANS*2 || ast[i].pos.y - bul->pos.y > ASTEROID_RADIANS*2)
      {
        ast[i].isAsteroidDead = false;
        return false; 

      }
      else{
        fprintf(stderr, "collied big asteroid: %d\n", i);
        
        ast[i].isAsteroidDead = true;
        delete_asteroid(&asteroid[i]);

        bul->isBulletDead = true;
        delete_bullets(bullets);
        mouseLeftKeyPressed = false;
      }
      score += 50;
      num_asteroid_destroy++;
      return true;
    }
  }
  return false;
}

bool is_collided_wall(ship_t *so)
{
  if(so->pos.y < g_screen_height/2 && 
      so->pos.y > -g_screen_height/2 && 
      so->pos.x < g_screen_width/2 &&
      so->pos.x > -g_screen_width/2)
  {
    return false;
  }
  return true;
}

