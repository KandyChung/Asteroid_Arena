#include "GLUTHeader.h"
#include "KeyboradController.h"

bool upKeyPressed = false;
bool mouseLeftKeyPressed = false;
bool rKeyPressed = false;

void move_forward()
{
  ship.pos.x -= ship.vel * -sinf(ship.rc * 3.14159 / 180);
  ship.pos.y += ship.vel * cosf(ship.rc * 3.14159 / 180);
}

void turn_left()
{
  ship.rc -= ship.rd;
}

void turn_right()
{
  ship.rc += ship.rd;
}

void disable_move()
{
  ship.pos.x += 0;
  ship.pos.y += 0;
  ship.rc += 0;
}

void on_key_press(unsigned char key, int x, int y)
{
  switch (key) 
  {
    case KEY_FORWARD:
      if(is_game_over()){
        disable_move();
      }else{
        move_forward();
        upKeyPressed = true;
      }
      break;
    case KEY_LEFT:
      if(is_game_over()){
        disable_move();
      }else{
        turn_left();
      }
      break;
    case KEY_RIGHT:
      if(is_game_over()){
        disable_move();
      }else{
        turn_right();
      }
      break;
      case 'r':
        rKeyPressed = true;
        ship.is_ship_dead = false;
        reset();
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

