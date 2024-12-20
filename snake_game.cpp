#include <iostream>
#include <conio.h> //console input output
#include <windows.h> //to avoid flickering due to continous screen clear
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y;
int fruitX, fruitY, score;
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
                else 
            cout<<" ";
            
            }
            cout<<"\n";
        }
        
    for(int i = 0; i<=width; i++)
        cout<<"#";
cout<<"\n";
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
    if(x == fruitX&& y = fruitY)
    score +=10;
    if(x>width || x<0 || y> height || y<0){
        gameOver = true; //if we hit the wall
    
    }
}
int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}