/*******************************************************************************************
*
*   raylib [textures] example - Texture loading and drawing
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture loading and drawing");
    InitAudioDevice();
    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D background = LoadTexture("./src2/Background/img/menu/background.png");
    Music smash=LoadMusicStream("./src2/Background/img/menu/smash.mp3");
    PlayMusicStream(smash);
    // Texture loading
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(background, screenWidth/2 - background.width/2, screenHeight/2 - background.height/2, WHITE);
            DrawText("PRESS ENTER TO PLAY",220,80,30,WHITE);		
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);       // Texture unloading
    UnloadMusicStream(smash);
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
