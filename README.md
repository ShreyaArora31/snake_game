# Snake Game in C++
A console-based Snake Game implemented in C++. The game allows the player to control a snake that moves around the screen, eats fruits, and grows longer. The game ends if the snake runs into itself.
<br>
<br>
**Features**
<br>
- Snake Movement: The snake can move left, right, up, or down using keyboard inputs.
- Fruit Collection: The snake eats the fruit (represented by "F"), which increases the score and length of the snake.
- Screen Wrapping: If the snake hits the boundary of the game area, it will wrap around to the opposite side.
- Game Over Condition: The game ends if the snake collides with its own body.
- Score Tracking: The current score is displayed on the screen.
<br>

**Controls**
<br>
W: Move Up
<br>
A: Move Left
<br>
S: Move Down
<br>
D: Move Right
<br>
X: Exit the game
<br>

**Requirements**
<br>
C++ Compiler (e.g., GCC, Clang, or MSVC)
<br>
Windows OS (for console-related functions like system("cls") and SetConsoleCursorPosition())
<br>

**Code Explanation**
<br>
*Key Variables*
<br>
x, y: Coordinates of the snake's head.
<br>
fruitX, fruitY: Coordinates of the fruit.
<br>
tailX, tailY: Arrays that store the positions of the snake's tail segments.
<br>
Tail_len: The length of the snake's tail.
<br>
score: The current score of the player.
<br>
dir: The current direction the snake is moving in (STOP, LEFT, RIGHT, UP, DOWN).
<br>
<br>
*Core Functions*
<br>
Setup(): Initializes the game state, including snake's initial position and the first fruit's random location.
<br>
Draw(): Draws the game grid, snake, fruit, and score on the console screen. Clears the screen before each frame to prevent overlapping output.
<br>
Input(): Reads user input for controlling the snake's direction.
<br>
Logic(): Updates the game state, including snake movement, collision detection, fruit collection, and game-over condition.
<br>
<br>
*Game Loop*
<br>
The game runs in a continuous loop until the player chooses to exit the game or the snake collides with itself. 
<br>
In each loop iteration:
<br>
The screen is drawn.
<br>
The player's input is processed.
<br>
The game logic is updated (snake movement, collision checks, etc.).
<br>
The program sleeps for a short time (adjustable for difficulty level).
