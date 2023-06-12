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
#include "Wall.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "KeyboradController.h"
#include "Idle.h"
#include "CollisionDetection.h"
#include "game.h"

void on_display()
{   
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 

  glTranslatef(g_screen_width/2, g_screen_height/2, 0);

  if (!rKeyPressed)
  {
    text_frame(-150, 0,  "Press 'r' to start...");
  }
  else{
    asteroid_frame(asteroid);
    display_red_line_box_when_close_to_wall();
    ship_frame(&ship);
    
    if(is_game_over())
    {
      text_frame(-200, 0,  "Game Over. Press 'r' to play again...");
    }
    if (upKeyPressed)
    {
      particle_puff_frame(&ship);
    }

    for (int i = 0; i < NUM_ASTEROID; i++)
    {
      for (int j = 0; j < NUM_BULLETS; j++)
      {
        if(!is_collied_bullets_and_asteroid(&bullets[j], &asteroid[i]))
        {
          bullets_frame(&bullets[j]);
        }
      }
    }
    text_frame(-g_screen_width/2 + 20, g_screen_height/2 - 40, "Score:");
    score_frame(-g_screen_width/2 + 130, g_screen_height/2 - 40, 15, score);
    text_frame(g_screen_width/2 - 290, g_screen_height/2 - 40, "Asteroid Destroyed:");
    score_frame(g_screen_width/2 - 60, g_screen_height/2 - 40, 15, num_asteroid_destroy);
    score_frame(0, g_screen_height/2 - 40, 15, glutGet(GLUT_ELAPSED_TIME));
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
    bullets_int(&bullets[i]);
  }
  g_last_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
}

int main(int argc, char **argv) 
{
  init_app(&argc, argv);
  glutMainLoop();
  return(EXIT_SUCCESS);
}
