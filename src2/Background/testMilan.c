/*******************************************************************************************
*
*   raylib [textures] example - Background scrolling
*
*   This example has been created using raylib 2.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#define PLAYER_JUMP_SPD 350.0f
#define G 400

typedef struct Player {
    Vector2 position;
    Texture2D player;
    float speed;
    bool canJump;
    bool sol;
} Player;

typedef struct Decor {
    float scrollingBack;
    float scrollingMid;
    float scrollingFore;
    Texture2D background;
    Texture2D midground;
    Texture2D foreground;
} Decor;


void UpdatePlayer(Player *player,Decor *decor, float delta);
void Unload(Decor *decor);


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");

    Player soinc = { 0 };
    soinc.position = (Vector2){ (float)screenWidth/2, (float)screenHeight/1.3 };
    soinc.player = LoadTexture("../Game/img/soinc.png");
    soinc.canJump = true;
    soinc.sol = true;

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect

    Decor decor = { 0 };
    decor.background = LoadTexture("img/lvl1/1.png");
    decor.midground = LoadTexture("img/lvl1/2.png");
    decor.foreground = LoadTexture("img/lvl1/3.png");
    decor.scrollingBack = 0.0f;
    decor.scrollingMid = 0.0f;
    decor.scrollingFore = 0.0f;
    
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        float deltaTime = GetFrameTime();
        
        UpdatePlayer(&soinc,&decor, deltaTime);
        
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(0x052c46ff));

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(decor.background, (Vector2){ decor.scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(decor.background, (Vector2){ decor.background.width*2 + decor.scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            DrawTextureEx(decor.midground, (Vector2){ decor.scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(decor.midground, (Vector2){ decor.midground.width*2 + decor.scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

            // Draw foreground image twice
            DrawTextureEx(decor.foreground, (Vector2){ decor.scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(decor.foreground, (Vector2){ decor.foreground.width*2 + decor.scrollingFore, 70 }, 0.0f, 2.0f, WHITE);

            DrawTextureEx(soinc.player, soinc.position, 0.0f, 0.2f, WHITE);  
            DrawText(TextFormat("Position y : %f \n Position x : %f",soinc.position.y,soinc.position.x), 10, 180,15, WHITE);



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    Unload(&decor);
    

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void Unload(Decor *decor)
{
    UnloadTexture(decor->background);  // Unload background texture
    UnloadTexture(decor->midground);   // Unload midground texture
    UnloadTexture(decor->foreground);  // Unload foreground texture
}

void UpdatePlayer(Player *player,Decor *decor, float delta)
{
    if (IsKeyDown(KEY_RIGHT)) { decor->scrollingBack -= 0.3f; decor->scrollingMid -= 0.5f; decor->scrollingFore -= 1.0f;}
    if (IsKeyDown(KEY_LEFT)) { decor->scrollingBack -= 0.3f; decor->scrollingMid += 0.5f; decor->scrollingFore += 1.0f;}

    if (IsKeyDown(KEY_SPACE) && player->canJump )
    {
        player->position.y -= 100.0f;
        player->speed = -PLAYER_JUMP_SPD;
        player->canJump = false;
        
    }

    if(player->position.y <= 345)
    {
        player->position.y -= player->speed*delta;
    }
    else 
    {
        player->canJump = true;
    }

}
