/*******************************************************************************************
*
*   NetWorld basic viewer
*   Copyright (c) 2020-2020 Guillaume Lozenguez
*
********************************************************************************************/

#include "networld.h"
#include "raylib.h"

// Program attributes
//-------------------
const int screenWidth = 800;
const int screenHeight = 450;
const int targetFPS = 60;

void game_update();
void game_draw();

// Game attributes
//-----------------
bool game_end;


int main(int nbArg, char ** arg)
{
    test();

    // Raylib Initialization
    //----------------------
    InitWindow(screenWidth, screenHeight, "NetWorld basic viewer");
    SetTargetFPS(targetFPS);
    
    // Game Initialization
    //--------------------
    game_end= false;

    // Main game loop
    while (!game_end && !WindowShouldClose())    // Detect window close button or ESC key
    {
        game_update();
        game_draw();
    }

    // proper closing
    //---------------
    CloseWindow();   // Close window and OpenGL context
 
    return 0;
}

void game_update()
{

}

void game_draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}