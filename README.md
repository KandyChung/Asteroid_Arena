## ASTEROID_ARENA_GAME

This is a 2D game built up by GLUT using Visual Studio Code. The game is about a spaceship shooting asteroids to get the score in the arena. At the same time, spaceships are not allowed to hit the wall and hit the asteroids otherwise it is gameover. Below I will provide a couple of screenshots of the game and describe how I implemented the game by using GLUT. 

The game frame<br>
![1](https://github.com/KandyChung/Asteroid_Arena/assets/80769024/744ce5d9-7442-4631-8a9b-b6d1a1476153)

Game over when a spaceship hit the asteroid.<br>
![2](https://github.com/KandyChung/Asteroid_Arena/assets/80769024/513a5703-e508-4b8d-8f1e-343d26cb3240)

When a spaceship is close to the wall it will display a red line around the screen to warn the player it is nearly hit the wall.<br>
![3](https://github.com/KandyChung/Asteroid_Arena/assets/80769024/cca50e7c-db45-4b1d-9724-dd5cdde2e8fd)

Game over when the spaceship hit the wall<br>
![4](https://github.com/KandyChung/Asteroid_Arena/assets/80769024/8d60e54b-0e1f-4c83-a948-acf0ac4ac838)


# When run the code
$ clang main.c Ship.c Reshape.c CollisionDetection.c Asteroid.c Idle.c KeyboradController.c Game.c Bullets.c Wall.c -Wno-deprecated-declarations -framework GLUT -framework OpenGL -framework Carbon -o A01_AA

$ ./A01_AA

# The complement of feature
LEVEL 1 Features:
1.1 - Screen Mode
How to build my code:
- Using glutFullScreen() and glutReshapeFunc(on_reshape)
- Using glutGet(GLUT_SCREEN_WIDTH) and glut(GLUT_SCREEN_HEIGHT) to get the width and height of the screen.
1.2 - The Arena
How to build my code:
- Used glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
1.3 - Ready Player 1
How to build my code:
- Draw the ship using glPushatrix() and glPopMatrix()
- Using glBegin(GL_LINE_LOOP) to line up the point to make a ship shape. - Using glBegin(GL_POLYGON) to fill the color black for the ship.
1.4 - Starting Location
How to build my code:
- Set ship position to be (ScreenSize/2)/2, when ever the code run is a bigger screen, which is still locate in bottom-left corner of the arena.
- Set the ship rotation to be 45 degree and rotate z. The ship is facing towards the top-right corner of the arena.
1.5 - Player Movement
How to build my code:
- Using glutKeyboardFunc(on_key_press) and glutKeyboardUpFunc(on_key_release).
1.6 - Hit The Wall
- Include when player ship close to any of the arena walls, warn the player by making that line segment turn Red.
How to build my code:
- When the ship is close to the wall, check if the ship position + ship radians + a bit more
distance is less or greater then the screen width and height.
1.7 - Math Structs/Classes and Functions
1.8 - Code Quality
- Define appropriate classes or structs to represent game object. - Code indentation and letter case.
- Use multiple source files to separate related function and class. - Comment is implemented in code.
LEVEL 2 Features:
2.1 - Launch Position
      
 - Position of asteroid is launched outside the arena.
How to build my code:
- Set the random range to be screen size + a bit more bigger. If the asteroid is launched inside the screen then set the position to be asteroid position - screen size /2, which means asteroid must launch in outside the arena no matter what size if the screen.
2.2 - Asteroid Launch
- Asteroid position and speed is generated randomly.
- Draw asteroid as a Circle.
How to build my code:
- Launch the asteroid using rand(). Include MAX and MIN.
2.3 - Asteroid / Ship Collision
- Little bug here:
- Successful collision when no more bullets in the ship.
e.g. shoot the bullets to nothing until no more bullets shows up at the head of ship. Now the collision is success.
How to build my code:
- If ship position - asteroid position or asteroid position - ship position is less than ship radians + asteroid radians mean they collied.
2.4 - Multiple Asteroid
How to build my code:
- Used array and loop the array to keep track of the current position of all asteroid.
2.5 - Particle Puff
How to build my code:
- When key ‘w’ is pressed, particle puff will display behind the ship. When key ‘w’ is up, particle puff will not display.
LEVEL 3 Features:
3.1 - Procedurally Generated Asteroids
How to build my code:
- Using asteroid radians to point out the point using sin/cos then line up the point.
3.2 - Rotating Asteroids
How to build my code:
- Using update_state() and idle() to keep loop increase the angle of the asteroid.
3.3 - Shooting
- Bullets is successful to kill the asteroid. When bullets killed the asteroid bullets will come back to the initial location. But only can shoot one time.
How to build my code:
- When mouse left button down, update_state() and idle() to increase the y axis of the bullets.
- When bullets position - asteroid position or asteroid position - bullets position is less than asteroid radians, set the bullets and asteroid is dead.
3.4 - Hit Points
How to build my code:
- Use bullets and asteroid collision checking function. If bullets has killed the asteroid score +50.
3.5 - Time and Score
- Successful to display the score and umber of Asteroid destroyed. Timer also successful to display but not able to stop when it is game over.
         
How to build my code:
- Using glutBitmapCharacter() to display the text.
- Using glRasterPos2f() to set the position of the text.
- Using glutGet(GLUT_ELAPSED_TIME) to display the timer.
3.6 - Game Over, Man
- When the first time the game is started have a message saying, “Press ‘r’ key to start. - When game over have a message saying “Game Over. Press ‘r’ to play again”
- I use key ‘r’ instead of ‘any key’.
- When ‘r’ is pressed, everything reset include score, number of asteroid destroy, ship position and asteroids position.
How to build my code:
- If ‘r’ isn't pressed, display “Press ‘r’ to start...” and do not display any frame. If ‘r’ is pressed, display all the frame and play the game.
- Using CollisionDetection class function to check if it is game over, if yes display “Game Over. Press ‘r’ to play again...”, if not keep running the game.
- Create a function call reset(), which is set the ship position and asteroids position to the initial position and set score and number of asteroid destroy to 0. If it is game over and player pressed ‘r’ call the reset() function.

