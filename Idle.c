#include "GLUTHeader.h"
#include "Idle.h"

float g_last_time = 0;

void update_asteroid_state(asteroid_t *ast, float dt)
{
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    float new_x = ast[i].pos.x + ast[i].dir.x*ast[i].vel*dt;
    float new_y = ast[i].pos.y + ast[i].dir.y*ast[i].vel*dt;

    if (new_x + ast[i].r > g_screen_width/2 + 200 || new_x - ast->r < -g_screen_width/2 - 200)
    {
      ast[i].dir.x *= -1;
    }
    if (new_y + ast[i].r > g_screen_height/2 + 200 || new_y - ast->r < -g_screen_height/2 - 200)
    {
      ast[i].dir.y *= -1;
    }
    if(ship.is_ship_dead)
    {
      ast[i].pos.x += 0;
      ast[i].pos.y += 0;
    }
    else
    {
      ast[i].pos.x = new_x;
      ast[i].pos.y = new_y;
    }
    ast[i].rc += ast[i].rd * dt;
  }
}

void update_bullets_state(bullets_t *bul, float dt) 
{
  for (int i = 0; i < NUM_BULLETS; i++)
  {
    float new_x = bul[i].pos.x - bul[i].vel * -sinf(bul[i].rc * 3.14159 / 180);
    float new_y = bul[i].pos.y + bul[i].vel * cosf(bul[i].rc * 3.14159 / 180);

    if(mouseLeftKeyPressed == true)
    {
      bul[i].pos.x = new_x;
      bul[i].pos.y = new_y;
    }
    else{
      bul[i].rc = ship.rc;
      bul[i].pos.x = ship.pos.x;
      bul[i].pos.y = ship.pos.y;
      mouseLeftKeyPressed = false;
    }
  }
}

void on_idle()
{
  float cur_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
  float dt = cur_time - g_last_time;
  update_asteroid_state(asteroid, dt);
  update_bullets_state(bullets, dt);

  g_last_time = cur_time;;
  glutPostRedisplay();
}
