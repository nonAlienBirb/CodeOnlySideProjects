#include <iostream>
#include "raylib.h"
#include <random>
using namespace std;


int rand(int start, int finish){
    //random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(start,finish);
    return dis(gen);
}

int main() {
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    //rect1
    const int rect1Width = 10;
    const int rect1Height = 100;
    const int rect1X = 10;
    int rect1Y = (screenHeight - rect1Height)/2;
    //rect2
    const int rect2Width = 10;
    const int rect2Height = 100;
    const int rect2X = screenWidth - rect2Width -10 ;
    int rect2Y = (screenHeight - rect2Height)/2;
    //ball
    const int ballRad = 5;
    int ballX = (screenWidth - ballRad)/2;
    int ballY = (screenHeight - ballRad)/2;
    int ballXspeed;
    int ballYspeed;
    bool ballrun = false;


    InitWindow(screenWidth, screenHeight, "Raylib pong test");

    SetTargetFPS(60); 
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        //player movements
        if(IsKeyDown(KEY_W)){
            rect1Y = rect1Y - 5;
        }else if (IsKeyDown(KEY_S))
        {
            rect1Y = rect1Y + 5;
        }
        if (IsKeyDown(KEY_UP))
        {
            rect2Y = rect2Y - 5;
        }else if (IsKeyDown(KEY_DOWN))
        {
            rect2Y = rect2Y + 5;
        }
        
        //game start and set ball speed
        if(IsKeyPressed(KEY_SPACE)& (!ballrun)){
            ballrun = true;

            int signX = rand(0,1)==1? 1:-1;
            int signY = rand(0,1)==1? 1:-1;
            int x = 0 ;
            int y = 0 ;
            while (x!=5 || y!=5)
            {
                x = rand(1,5);
                y = rand(1,5);
            }
        
            ballXspeed = signX * x;
            ballYspeed = signY * y;
        }
        if(ballrun){
            ballX = ballX+ballXspeed;
            ballY = ballY+ballYspeed;    
        }
        
        //ball reflections
        if (ballY - ballRad < 0 || ballY + ballRad > screenHeight) {
            ballYspeed = -ballYspeed;
        }

        if (((ballX - ballRad <= rect1X + rect1Width) && (ballY >= rect1Y && ballY <= rect1Y + rect1Height))||((ballX + ballRad >= rect2X) && (ballY >= rect2Y && ballY <= rect2Y + rect2Height))){
            ballXspeed = -ballXspeed;
        }

        //reset game
        if (ballX <= 0 || ballX >= screenWidth){
            ballrun = false;
            ballX = (screenWidth - ballRad)/2;
            ballY = (screenHeight - ballRad)/2;
            rect2Y = (screenHeight - rect2Height)/2;
            rect1Y = (screenHeight - rect1Height)/2;
        }

        //if player goes outside screen , bring it back from the opposite side
        if (!((-rect2Height+5<=rect2Y))){
            rect2Y = screenHeight;
        }else if(!(rect2Y<=screenHeight)){
            rect2Y = 0;
        }
        if (!((-rect1Height+5<=rect1Y))){
            rect1Y = screenHeight;
        }else if(!(rect1Y<=screenHeight)){
            rect1Y = 0;
        } 
        
        //draiwngs
        DrawRectangle(rect1X,rect1Y,rect1Width,rect1Height, BLUE);
        DrawRectangle(rect2X,rect2Y,rect2Width,rect2Height, BLUE);
        DrawCircle(ballX,ballY,ballRad, GREEN);
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}
