#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#if _WIN32
# include <windows.h>
#endif
#if __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#endif


#include "Reshape.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "KeyboradController.h"
#include "Idle.h"
#include "CollisionDetection.h"

void on_display()
{   
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 

  glTranslatef(widthX, heightY, 0);
  asteroid_frame(asteroid);
  
  if(is_close_collision(&ship)) //Simpify
  {
    red_line_box_frame();
  }
  game_box_frame();
  ship_frame(&ship);
  

  if(is_collided_wall(&ship))
  {
    ship_int(&ship);
  }

  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if(is_collied_ship(&ship, &asteroid[i]))
    {
      ship_int(&ship);
    }
  }
  

  if (upKeyPressed)
  {
    particle_puff_frame(&ship);
  }

  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    if(!is_collied_bullets(&bullets[i], &asteroid[i]))
    {
      bullets_frame(&bullets[i]);
    }
  }
  
  int err;  
  while ((err = glGetError()) != GL_NO_ERROR)    
  printf("error: %s\n", gluErrorString(err));  
  
  glutSwapBuffers();
  glutPostRedisplay();
}

void init_app(int *argcp, char **argv)
{
  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Assignment 1 -ASTEROID ARENA");
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glutFullScreen();
  glutReshapeFunc(on_reshape);
  glutKeyboardFunc(on_key_press);
  glutKeyboardUpFunc(on_key_release);
  glutMouseFunc(on_mouse_button);

  glutDisplayFunc(on_display);
  glutIdleFunc(on_idle);

  srand((unsigned)time(NULL));

  g_screen_width = glutGet(GLUT_SCREEN_WIDTH);
  g_screen_height = glutGet(GLUT_SCREEN_HEIGHT);

  ship_int(&ship);

  for (int i = 0; i < NUM_ASTEROID; i++)
  {
    asteroid_int(&asteroid[i]);
  }
  
  for (int i = 0; i < NUM_BULLETS; i++)
  {
    bullets_int(&bullets[i], &ship);
  }


  g_last_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
}

int main(int argc, char **argv) 
{
  init_app(&argc, argv);
  glutMainLoop();
  return(EXIT_SUCCESS);
}
