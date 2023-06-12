#include "GLUTHeader.h"
#include "Reshape.h"

int g_screen_width = 0;
int g_screen_height = 0;
int widthX = 0;
int heightY = 0;

void on_reshape(int w, int h)
{
  fprintf(stderr, "%d\n", rand() % 50);
  fprintf(stderr, "on_reshape(%d, %d)\n", w, h);
  glViewport(0, 0, w, h);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, w, 0.0, h, -1.0, 1.0);

  g_screen_width = w;
  g_screen_height = h;
}