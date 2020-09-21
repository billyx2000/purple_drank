/*******************************************************************************************
*
*   NetWorld basic viewer
*   Copyright (c) 2020-2020 Guillaume Lozenguez
*
********************************************************************************************/

#include "networld.h"
#include "raylib.h"
#include <stdlib.h>

// Program attributes
//-------------------
const int screenWidth = 800;
const int screenHeight = 450;
const int targetFPS = 60;

void game_update(NetWorld * world);
void game_draw(NetWorld * world);

// Game attributes
//-----------------
bool game_end;


int main(int nbArg, char ** arg)
{
    // Raylib Initialization
    //----------------------
    InitWindow(screenWidth, screenHeight, "NetWorld basic viewer");
    SetTargetFPS(targetFPS);
    
    // Game Initialization
    //--------------------
    game_end= false;
    NetWorld * world= NetWorld_new(3);
    NetWorld_initNodePosition( world, 0, 10.4, 12.8 );
    NetWorld_initNodePosition( world, 1, 110.4, 52.8 );
    NetWorld_initNodePosition( world, 2, 384.5, 422.2 );

    // Main game loop
    while (!game_end && !WindowShouldClose())    // Detect window close button or ESC key
    {
        game_update(world);
        game_draw(world);
    }

    // proper closing
    //---------------
    NetWorld_delete(world);
    CloseWindow();   // Close window and OpenGL context
 
    return 0;
}

void game_update(NetWorld * world)
{

}

void game_draw(NetWorld * world)
{
    BeginDrawing();

    puts("Draw...\n");
    ClearBackground(RAYWHITE);

    for(int i= 0 ; i < world->size ; ++i )
    {
        Vector2 nodePosition= { world->nodes[i].x, world->nodes[i].y };
        printf("[%f, %f]\n", world->nodes[i].x, world->nodes[i].y);
        DrawCircleV(nodePosition, 50, MAROON);
    }

    EndDrawing();
}