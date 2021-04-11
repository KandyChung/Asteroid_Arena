#include "GLUTHeader.h"
#include "Bullets.h"

void bullets_int(bullets_t *bul, ship_t *so)
{
  bul->pos.x = 0;
  bul->pos.y = 0;
  bul->dir.x = 0;
  bul->dir.y = 0;
  bul->vel = 2;
  bul->lifespan = 0;
  bul->r = 1;
  bul->g = 1;
  bul->b = 0;
  bul->size = 7;
  bul->rc = 45;
  bul->isBulletDead = false;
}

void bullets_frame(bullets_t *bul)
{ 
  for (int i = 0; i < NUM_BULLETS; i++)
  {
    if(!bul[i].isBulletDead)
    {
      glPushMatrix();
      glTranslatef(bul[i].pos.x, bul[i].pos.y, 0);
      glRotatef(bul[i].rc, 0, 0, -1);
      glScalef(bul[i].size, bul[i].size, 0);
      
      glColor3f(bul[i].r, bul[i].g, bul[i].b);
      glBegin(GL_POINTS);
      glVertex3f(0, 4, 0);
      glEnd();
      glPopMatrix();
      // fprintf(stderr, "Bullets %d position: (%f, %f)\n", i, bul[i].pos.x, bul[i].pos.y);
    }
  }
}

// void bullets_frame(bullets_t *bul)
// { 
//   while (NUM_BULLETS != 0)
//   {
//     if(!bul->isBulletDead)
//     {
//       glPushMatrix();
//       glTranslatef(bul->pos.x, bul->pos.y, 0);
//       glRotatef(bul->rc, 0, 0, -1);
//       glScalef(bul->size, bul->size, 0);
      
//       glColor3f(bul->r, bul->g, bul->b);
//       glBegin(GL_POINTS);
//       glVertex3f(0, 4, 0);
//       glEnd();
//       glPopMatrix();
//       NUM_BULLETS++;
//       // fprintf(stderr, "Bullets %d position: (%f, %f)\n", i, bul[i].pos.x, bul[i].pos.y);
//     }
//   }
// }