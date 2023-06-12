#include "GLUTHeader.h"
#include "Game.h"

void text_frame(float x, float y, const char* string)
{
    int j = strlen(string);

    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);

    for (int i = 0; i < j; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void score_frame(float x, float y, int space_char, int score)
{
    int j = 0;
    int p, k;

    p = score;
    j = 0;
    k = 0;
    while(p > 9)
    {
        k = p % 10;
        glColor3f(1, 1, 1);
        glRasterPos2f((x-(j*space_char)), y);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48+k);
        j++;
        p /= 10;
    }
    glRasterPos2f((x-(j*space_char)), y);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 48+p);
}

void display_red_line_box_when_close_to_wall()
{
    if(is_close_collision(&ship))
    {
      red_line_box_frame();
    }
}

bool is_game_over()
{
    if(is_collided_wall(&ship))
    {
        ship.is_ship_dead = true;
        return true;
    }

    for (int i = 0; i < NUM_ASTEROID; i++)
    {
        if(is_collied_ship(&ship, &asteroid[i]))
        {
            update_asteroid_state(&asteroid[i], 0);
            ship.is_ship_dead = true;
            return true;
        }
    }
    return false;
}

void reset()
{
    score = 0;
    num_asteroid_destroy = 0;
    ship_int(&ship);
    for (int i = 0; i < NUM_ASTEROID; i++)
    {
        asteroid_int(&asteroid[i]);
    }
    for (int i = 0; i < NUM_BULLETS; i++)
    {
        bullets_int(&bullets[i]);
        mouseLeftKeyPressed = false;
    }
}
