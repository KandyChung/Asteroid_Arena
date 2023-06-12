#include "GLUTHeader.h"
#include "Asteroid.h"

int num_segments = 100;

float set_asteroidX_random_postion(int max, int min)
{
  int astX = 0;
  int randX = min + rand() % (max - min + 1);

  if (randX < -g_screen_width/2 || randX > g_screen_width/2)
  {
    astX = randX;
  }
  else if (randX > -g_screen_width/2 && randX < 0)
  {
    astX = randX + -g_screen_width/2;
  }
  else if (randX > 0 && randX < g_screen_width/2)
  {
    astX = randX + g_screen_width/2;
  }

  return astX;
}

float set_asteroidY_random_postion(int max, int min)
{
  int astY = 0;
  int randY = min + rand() % (max - min + 1);

  if (randY < -g_screen_height/2 || randY > g_screen_height/2)
  {
    astY = randY;
  }
  else if (randY > -g_screen_height/2 && randY < 0)
  {
    astY = randY + -g_screen_height/2;
  }
  else if (randY > 0 && randY < g_screen_height/2)
  {
    astY = randY + g_screen_height/2;
  }

  return astY;
}

void asteroid_int(asteroid_t *ast)
{
  ast->r = ASTEROID_RADIANS;
  ast->pos.x = set_asteroidX_random_postion(g_screen_width/2 + 100, -g_screen_width/2 - 100);
  ast->pos.y = set_asteroidY_random_postion(g_screen_height/2 + 100, -g_screen_height/2 - 100);
  ast->dir.x = rand() % (MAX_DIRACTION - MIN_DIRACTION + 1) + MIN_DIRACTION;
  ast->dir.y = rand() % (MAX_DIRACTION - MIN_DIRACTION + 1) + MIN_DIRACTION;
  ast->rc = rand() % 360;
  ast->rd = 40;
  ast->vel = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
  ast->isAsteroidDead = false;
  fprintf(stderr, "Ast locationX: %f\n", ast->pos.x);
  fprintf(stderr, "Ast locationY: %f\n", ast->pos.y);
  fprintf(stderr, "Ast directionX: %f\n", ast->dir.x);
  fprintf(stderr, "Ast directionY: %f\n\n", ast->dir.y);
}

void asteroid_frame(asteroid_t *ast) 
{
  
  for(int i = 0; i < NUM_ASTEROID; i++)
  {
    if(!ast[i].isAsteroidDead)
    {
      glPushMatrix();
      glColor3f(1, 1, 1);
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
      glBegin(GL_LINE_LOOP);
      glVertex3f(0, ast[i].r, 0);
      glVertex3f(ast[i].r*sin(45), ast[i].r*sin(45), 0);
      glVertex3f(ast[i].r, 0, 0);
      glVertex3f(0, -ast[i].r, 0);
      glVertex3f(-ast[i].r*sin(45), -ast[i].r*sin(45), 0);
      glVertex3f(-ast[i].r, 0, 0);
      glVertex3f(-ast[i].r*cos(45), ast[i].r*sin(45), 0);
      glEnd();
      glPopMatrix();
    }
    
  }
}

void delete_asteroid(asteroid_t *ast)
{
  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if (ast[i].isAsteroidDead)
    {
      ast[i].pos.x = set_asteroidX_random_postion(g_screen_width/2 + 100, -g_screen_width/2 - 100);
      ast[i].pos.y = set_asteroidY_random_postion(g_screen_height/2 + 100, -g_screen_height/2 - 100);
    }
  }
}