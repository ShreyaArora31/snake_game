# Snake Game in C++
A console-based Snake Game implemented in C++. The game allows the player to control a snake that moves around the screen, eats fruits, and grows longer. The game ends if the snake runs into itself.

**Features**
**Snake Movement:** The snake can move left, right, up, or down using keyboard inputs.
**Fruit Collection:** The snake eats the fruit (represented by "F"), which increases the score and length of the snake.
**Screen Wrapping:** If the snake hits the boundary of the game area, it will wrap around to the opposite side.
**Game Over Condition:** The game ends if the snake collides with its own body.
**Score Tracking:** The current score is displayed on the screen.

**Controls**
W: Move Up
A: Move Left
S: Move Down
D: Move Right
X: Exit the game

**Requirements**
C++ Compiler (e.g., GCC, Clang, or MSVC)
Windows OS (for console-related functions like system("cls") and SetConsoleCursorPosition())

**Code Explanation**
<br>
*Key Variables*
x, y: Coordinates of the snake's head.
fruitX, fruitY: Coordinates of the fruit.
tailX, tailY: Arrays that store the positions of the snake's tail segments.
Tail_len: The length of the snake's tail.
score: The current score of the player.
dir: The current direction the snake is moving in (STOP, LEFT, RIGHT, UP, DOWN).

*Core Functions*
Setup(): Initializes the game state, including snake's initial position and the first fruit's random location.
Draw(): Draws the game grid, snake, fruit, and score on the console screen. Clears the screen before each frame to prevent overlapping output.
Input(): Reads user input for controlling the snake's direction.
Logic(): Updates the game state, including snake movement, collision detection, fruit collection, and game-over condition.

*Game Loop*
The game runs in a continuous loop until the player chooses to exit the game or the snake collides with itself. 
In each loop iteration:
The screen is drawn.
The player's input is processed.
The game logic is updated (snake movement, collision checks, etc.).
The program sleeps for a short time (adjustable for difficulty level).