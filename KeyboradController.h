#ifndef KEYBORADCONTROLLER_H_
#define KEYBORADCONTROLLER_H_
#include "Ship.h"
#include "Game.h"

#define KEY_ESC 27
#define KEY_FORWARD 'w'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEYO 'o'

bool upKeyPressed;
bool mouseLeftKeyPressed;
bool rKeyPressed;

extern void move_forward();
extern void turn_left();
extern void turn_right();
extern void disable_move();
extern void on_key_press(unsigned char key, int x, int y);
extern void on_key_release(unsigned char key, int x, int y);
extern void on_mouse_button(int btn, int state, int x, int y);

#endif //KEYBORADCONTROLLER_H_