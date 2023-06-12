#include "GLUTHeader.h"
#include "Bullets.h"

void bullets_int(bullets_t *bul)
{
  bul->pos.x = ship.pos.x;
  bul->pos.y = ship.pos.y;
  bul->dir.x = 0;
  bul->dir.y = 0;
  bul->vel = 8;
  bul->r = 1;
  bul->g = 1;
  bul->b = 0;
  bul->size = 7;
  bul->rc = ship.rc;
  bul->isBulletDead = false;
}

void bullets_frame(bullets_t *bul)
{ 
  for (int i = 0; i < NUM_BULLETS; i++)
  {
      glPushMatrix();
      glTranslatef(bul[i].pos.x, bul[i].pos.y, 0);
      glRotatef(bul[i].rc, 0, 0, -1);
      glScalef(bul[i].size, bul[i].size, 0);
      
      glColor3f(bul[i].r, bul[i].g, bul[i].b);
      glBegin(GL_POINTS);
      glVertex3f(0, 3.2, 0);
      glEnd();
      glPopMatrix();
  }
}

void delete_bullets(bullets_t *bul)
{
  for (int i = 0; i < NUM_BULLETS; i++)
  {
    if (bul[i].isBulletDead)
    {
      bul[i].pos.x = ship.pos.x;
      bul[i].pos.y = ship.pos.y;
      fprintf(stderr, "Bullet %d dead: (%f, %f)\n", i, bul[i].pos.x, bul[i].pos.y);
    }
  }
}