#include "GLUTHeader.h"
#include "Asteroid.h"

float set_asteroidX_random_postion(int max, int min)
{
  int astX = 0;
  int randX = min + rand() % (max - min + 1);
  
  return randX;
}

float set_asteroidY_random_postion(int max, int min)
{
  int astY ;
  int randY = min + rand() % (max - min + 1);
  
  return randY;
}

int diractionX(asteroid_t *ast)
{
  int dirX;
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if(ast[i].pos.x > 0 && ast[i].pos.y > 0)
    {
      dirX = MOVING_LEFT_DOWN;
    }
    else if(ast[i].pos.x < 0 && ast[i].pos.y < 0)
    {
      dirX = MOVING_RIGHT_UP;
    }
    else if(ast[i].pos.x > 0 && ast[i].pos.y < 0)
    {
      dirX = MOVING_LEFT_DOWN;
    }
    else if(ast[i].pos.x < 0 && ast[i].pos.y > 0)
    {
      dirX = MOVING_RIGHT_UP;
    }
  }
  return dirX;
}

int diractionY(asteroid_t *ast)
{
  int dirY;
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if(ast[i].pos.x > 0 && ast[i].pos.y > 0)
    {
      dirY = MOVING_LEFT_DOWN;
    }
    else if(ast[i].pos.x < 0 && ast[i].pos.y < 0)
    {
      dirY = MOVING_RIGHT_UP;
    }
    else if(ast[i].pos.x > 0 && ast[i].pos.y < 0)
    {
      dirY = MOVING_RIGHT_UP;
    }
    else if(ast[i].pos.x < 0 && ast[i].pos.y > 0)
    {
      dirY = MOVING_LEFT_DOWN;
    }
  }
  return dirY;
}

//rand() % (max_number + 1 - minimum_number) + minimum_number

void asteroid_int(asteroid_t *ast)
{
  ast->r = ASTEROID_RADIANS;
  ast->pos.x = set_asteroidX_random_postion(g_screen_width/2 + 100, -g_screen_width/2 - 100);
  ast->pos.y = set_asteroidY_random_postion(g_screen_height/2 + 100, -g_screen_height/2 - 100);
  ast->dir.x = diractionX(asteroid);
  ast->dir.y = diractionY(asteroid);
  ast->rc = rand() % 360;
  ast->rd = 45;
  ast->vel = rand() % (100 - 90) + 90;
  ast->isAsteroidDead = false;
  fprintf(stderr, "Ast locationX: %f\n", ast->pos.x);
  fprintf(stderr, "Ast locationY: %f\n", ast->pos.y);
  fprintf(stderr, "Ast directionX: %f\n", ast->dir.x);
  fprintf(stderr, "Ast directionY: %f\n\n", ast->dir.y);
}

void asteroid_frame(asteroid_t *ast) 
{
  int num_segments = 100;
  for(int i = 0; i < NUM_ASTEROID; i++)
  {
    if(!ast[i].isAsteroidDead)
    {
      glPushMatrix();
      glColor3f(1, 1, 1);
      // glTranslatef(ast->pos.x, ast->pos.y, 0);
      glTranslatef(ast[i].pos.x, ast[i].pos.y, 0);
      glRotatef(ast[i].rc, 0, 0, 1);
      glBegin(GL_LINE_LOOP);
      for (int j = 0; j < num_segments; j++)   
      {
        float theta = 2.0f * 3.1415926f * j / num_segments;
        float x = ast[i].r * cosf(theta);
        float y = ast[i].r * sinf(theta);
        glVertex2f(x , y);
      }
      glEnd();
      // glTranslatef(ast->pos.x, ast->pos.y, 0);
      // glTranslatef(ast[i].pos.x, ast[i].pos.y, 0);
      glBegin(GL_LINE_LOOP);
      glVertex3f(40, 20, 0);
      glVertex3f(34, 6, 0);
      glVertex3f(41, -12, 0);
      glVertex3f(14, -50, 0);
      glVertex3f(2, -36, 0);
      glVertex3f(-22, -48, 0);
      glVertex3f(-30, -14, 0);
      glVertex3f(-48, -12, 0);
      glVertex3f(-36, 32, 0);
      glVertex3f(-16, 31, 0);
      glVertex3f(-10, 42, 0);
      glEnd();
      // fprintf(stderr, "%d: (%f,%f)\n", i, ast->pos.x, ast->pos.y);
      glPopMatrix();
    }
  }
}

void delet_asteroid(asteroid_t *ast)
{
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if (ast[i].isAsteroidDead)
    {
      ast[i].pos.x = set_asteroidX_random_postion(g_screen_width/2 + 100, -g_screen_width/2 - 100);
      ast[i].pos.y = set_asteroidY_random_postion(g_screen_height/2 + 100, -g_screen_height/2 - 100);
      fprintf(stderr, "asteroid %d dead: (%f, %f)\n", i, ast[i].pos.x, ast[i].pos.y);
    }
  }
}