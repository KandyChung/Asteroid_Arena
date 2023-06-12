#include "GLUTHeader.h"
#include "Ship.h"

void red_line_box_frame()
{
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(g_screen_width/2 - 5, g_screen_height/2 - 5, 0);
  glVertex3f(g_screen_width/2 - 5, -g_screen_height/2 + 5, 0);
  glVertex3f(-g_screen_width/2 + 5, -g_screen_height/2 + 5, 0);
  glVertex3f(-g_screen_width/2 + 5, g_screen_height/2 - 5, 0);
  glEnd();
}