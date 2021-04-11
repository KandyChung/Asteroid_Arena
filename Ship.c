#include "GLUTHeader.h"
#include "Ship.h"

void ship_int(ship_t *so)
{
  so->pos.x = -(g_screen_width/2)/2;
  so->pos.y = -(g_screen_height/2)/2;
  so->dir.x = 0;
  so->dir.y = 0;
  so->rc = 45;
  so->rd = 10;
  so->vel = 10;
}

void ship_frame(ship_t *so)
{ 
  glPushMatrix(); 
  
  glTranslatef(so->pos.x, so->pos.y, 0);
  glRotatef(so->rc, 0, 0, -1);
  glScalef(7, 7, 0);
  
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex3f(0, 3, 0);
  glVertex3f(2, -3, 0);
  glVertex3f(0 , -1.5 , 0);
  glVertex3f(-2 , -3 , 0);
  glVertex3f(0 , 3 , 0);
  glVertex3f(0 , -1.5 , 0);
  glEnd();
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0, 3, 0);
  glVertex3f(2, -3, 0);
  glVertex3f(0 , -1.5 , 0);
  glVertex3f(-2 , -3 , 0);
  glVertex3f(0 , 3 , 0);
  glVertex3f(0 , -1.5 , 0);
  glEnd();
  glPopMatrix();
}

void particle_puff_frame(ship_t *so)
{
  glPushMatrix();
  glTranslatef(so->pos.x, so->pos.y, 0);
  glRotatef(so->rc, 0, 0, -1);
  glScalef(7, 7, 0);
  
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0, -3, 0);
  glVertex3f(0, -4, 0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex3f(-0.5, -3, 0);
  glVertex3f(-1, -4, 0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.5, -3, 0);
  glVertex3f(1, -4, 0);
  glEnd();
  glPopMatrix();
}