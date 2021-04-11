#include "GLUTHeader.h"
#include "KeyboradController.h"

bool upKeyPressed = false;
bool mouseLeftKeyPressed = false;

void move_forward(ship_t *so)
{
  so->pos.x -= so->vel * -sinf(so->rc * 3.14159 / 180);
  so->pos.y += so->vel * cosf(so->rc * 3.14159 / 180);
}

void turn_left(ship_t *so)
{

  so->rc -= so->rd;
}

void turn_right(ship_t *so)
{
  so->rc += so->rd;
}

void on_key_press(unsigned char key, int x, int y)
{
  switch (key) 
  {
    case KEY_FORWARD:
      move_forward(&ship);
      upKeyPressed = true;
      break;
    case KEY_LEFT:
      turn_left(&ship);
      break;
      case KEY_RIGHT:
      turn_right(&ship);
      break;
    case KEY_ESC:
      exit(EXIT_SUCCESS);
      break;
    default:
      break;
  }
}

void on_key_release(unsigned char key, int x, int y)
{
  switch (key) 
  {
    case KEY_FORWARD:
      upKeyPressed = false;
      break;
    case KEY_LEFT:
      break;
      case KEY_RIGHT:
      break;
    case KEY_ESC:
      exit(EXIT_SUCCESS);
      break;
    default:
      break;
  }
}

void on_mouse_button(int btn, int state, int x, int y)
{
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    mouseLeftKeyPressed = true;
  }
}

