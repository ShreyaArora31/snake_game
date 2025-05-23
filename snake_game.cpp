#include <iostream>
#include <conio.h> //console input output
#include <windows.h> //to avoid flickering due to continous screen clear and for sleep function
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y;
int fruitX, fruitY, score;
int tailX[100], tailY[100]; //max tail size as 100
int Tail_len;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup(){
    gameOver = false;
    dir = STOP;
    x= width/2;
    y = height/2; //snake head on centre of map
    fruitX = rand() % width; //random place from 0 to width-1
    fruitY = rand() % height;
    score = 0;
}

void Draw(){
    // Move the cursor to the top-left corner
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for(int i = 0; i<=width; i++)
        cout<<"#";
    cout<<"\n";

    for(int i =0;i<height;i++){
        for (int j = 0;j<width;j++){
            if(j==0)
            cout<<"#";
            
                if (i==y && j==x)
            cout<<"O";
            else if(i==fruitY && j == fruitX)
            cout<<"F";

            else if(j==width-1)
                cout<<"#";
                else {
                    bool print = false;
                    for(int k =0 ; k< Tail_len; k++){
                        
                        if(tailX[k] == j && tailY[k] == i)
                        {
                            cout<< "o";
                            print = true;
                        }
                    }
                    if(!print)
                    cout<<" ";  
                }
            }
            cout<<"\n";
        }
        
    for(int i = 0; i<=width; i++)
        cout<<"#";
cout<<"\n";
cout<<"Score : "<<score<<"\n";
}

void Input(){
    if (_kbhit()){ //keyboard bit is pressed
    switch(_getch()){
        case 'a':
        dir = LEFT;
        break;
        case 'd':
        dir = RIGHT;
        break;
        case 'w':
        dir = UP;
        break;
        case 's':
        dir = DOWN;
        break;
        case 'x':
        gameOver= true;
        break;
    }
    }
}
void Logic(){
    int prevX = tailX[0]; //head of tail
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i<Tail_len; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir){
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case DOWN:
        y++;
        break;
        case UP:
        y--;
        break;
        default:
        break;
    }
    
    //if(x>width || x<0 || y> height || y<0)
      //  gameOver = true; //if we hit the wall
    
    if(x>=width)
    x=0;
    else if(x<0)
    x=width-1;
    if(y>=height)
    y=0;
    else if(y<0)
    y=height-1;

    for(int i =0; i< Tail_len;i++){
        if(tailX[i] == x && tailY[i] == y)
        gameOver = true;
    }
    
    if(x == fruitX && y == fruitY)
    {
        Tail_len++;
        score +=10;
        fruitX = rand() % width; //random place from 0 to width-1
    fruitY = rand() % height;
    }
}
int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(200);//set difficulty level or the speed of snake
    }
    return 0;
}