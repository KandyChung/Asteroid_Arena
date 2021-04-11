#include "GLUTHeader.h"
#include "Idle.h"

float g_last_time = 0;

void update_game_state(asteroid_t *ast, float dt)
{
  // fprintf(stderr, "dt=%f\n", dt);
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    float new_x = ast[i].pos.x + ast[i].dir.x*ast[i].vel*dt;
    float new_y = ast[i].pos.y + ast[i].dir.y*ast[i].vel*dt;

    if (new_x + ast[i].r > widthX + 200 || new_x - ast->r < -widthX - 200)
    {
      ast[i].dir.x *= -1;
    }
    if (new_y + ast[i].r > heightY + 200 || new_y - ast->r < -heightY - 200)
    {
      ast[i].dir.y *= -1;
    }
    else
    {
      ast[i].pos.x = new_x;
      ast[i].pos.y = new_y;
    }
    ast[i].rc += ast[i].rd * dt;
  }
}

void update_bullets_state(ship_t *so, bullets_t *bul, float dt) 
{
  while (NUM_BULLETS != 0)
  {
    float new_x = bul->pos.x - bul->vel * -sinf(so->rc * 3.14159 / 180);
    float new_y = bul->pos.y + bul->vel * cosf(so->rc * 3.14159 / 180);
    
    bul->pos.x = so->pos.x;
    bul->pos.y = so->pos.y;
    bul->dir.x = so->dir.x;
    bul->dir.y = so->dir.y;
    bul->rc = so->rc;
    
    if(mouseLeftKeyPressed == true)
    {
      bul->pos.x = new_x;
      bul->pos.y = new_y;
      
    }
  }
}

void on_idle()
{
  float cur_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
  float dt = cur_time - g_last_time;
  update_game_state(asteroid, dt);
  update_bullets_state(&ship, bullets, dt);
  g_last_time = cur_time;;
  glutPostRedisplay();
}
