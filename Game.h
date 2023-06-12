#ifndef GAME_H_
#define GAME_H_
#include "Asteroid.h"
#include "Reshape.h"
#include "Ship.h"
#include "Bullets.h"
#include "Wall.h"
#include "KeyboradController.h"
#include "Game.h"
#include "CollisionDetection.h"

//Function of display text
extern void text_frame(float x, float y, const char* string);
//Function of display number
extern void score_frame(float x, float y, int space_char, int score);
//Display red line box when close to wall
extern void display_red_line_box_when_close_to_wall();
//Check if it is game over
extern bool is_game_over();
//Reset the game
extern void reset();

#endif //GAME_H_