#include "GLUTHeader.h"
#include "CollisionDetection.h"

void red_line_box_frame()
{
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(widthX - 5, heightY - 5, 0);
  glVertex3f(widthX - 5, -heightY + 5, 0);
  glVertex3f(-widthX + 5, -heightY + 5, 0);
  glVertex3f(-widthX + 5, heightY - 5, 0);
  glEnd();
}

void game_box_frame()  //will delet will all done
{
  glColor3f(0, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(widthX - 1, heightY - 1, 0);
  glVertex3f(widthX - 1, -heightY + 1, 0);
  glVertex3f(-widthX + 1, -heightY + 1, 0);
  glVertex3f(-widthX + 1, heightY - 1, 0);
  glEnd();
}

bool is_close_collision(ship_t *so)
{
  if(so->pos.y + SHIP_RADIANS < heightY && 
      so->pos.y - SHIP_RADIANS > -heightY && 
      so->pos.x + SHIP_RADIANS < widthX &&
      so->pos.x - SHIP_RADIANS > -widthX)
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
    // bool no_collied_x = so->pos.x - ast[i].pos.x > ship_asteroid_dis || ast[i].pos.x - so->pos.x > ship_asteroid_dis;
    // bool no_collied_y = so->pos.y - ast[i].pos.y > ship_asteroid_dis || ast[i].pos.y - so->pos.y > ship_asteroid_dis;
    if(so->pos.x - ast[i].pos.x > ship_asteroid_dis || ast[i].pos.x - so->pos.x > ship_asteroid_dis || 
    so->pos.y - ast[i].pos.y > ship_asteroid_dis || ast[i].pos.y - so->pos.y > ship_asteroid_dis)
    {
      return false;
    }
    else{
      fprintf(stderr, "collied ship: %d\n", i);
    }
    return true;
  }
  return false;
}

bool is_collied_bullets(bullets_t *bul, asteroid_t *ast)
{
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    // bool no_collied_x = so->pos.x - ast[i].pos.x > ship_asteroid_dis || ast[i].pos.x - so->pos.x > ship_asteroid_dis;
    // bool no_collied_y = so->pos.y - ast[i].pos.y > ship_asteroid_dis || ast[i].pos.y - so->pos.y > ship_asteroid_dis;
    if(bul->pos.x - ast[i].pos.x > ASTEROID_RADIANS*2 || ast[i].pos.x - bul->pos.x > ASTEROID_RADIANS*2 || 
    bul->pos.y - ast[i].pos.y > ASTEROID_RADIANS*2 || ast[i].pos.y - bul->pos.y > ASTEROID_RADIANS*2)
    {
      ast[i].isAsteroidDead = false;
      return false; 
    }
    else{
      fprintf(stderr, "collied bullets: %d\n", i);
    }
    ast[i].isAsteroidDead = true;
    delet_asteroid(&asteroid[i]);
    return true;
  }
  return false;
}

bool is_collided_wall(ship_t *so)
{
  if(so->pos.y < heightY && 
      so->pos.y > -heightY && 
      so->pos.x < widthX &&
      so->pos.x > -widthX)
  {
    return false;
  }
  return true;
}

