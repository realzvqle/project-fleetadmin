#include "player.h"
#include "externelheaders/raylib.h"
#include "tools.h"


float player_x;
float player_y;
float speed;
Texture2D player_image;

void run_player(){
    static bool init = false;
    if(init == false){
        player_image = LoadTexture("assets/ship.png");
        player_x = GetScreenWidth() / 2.0f;
        player_y = GetScreenHeight() / 2.0f;
        speed = 400.0f;
        init = true;

    }
        float angle = calculate_angle(player_x, player_y, GetMouseX(), GetMouseY());

    DrawTextureEx(player_image, (Vector2){player_x - player_image.width / 2.0f, player_y - player_image.height / 2.0f}, angle + 80, 1, BLUE);
    //DrawRectangleLines((int)player_x, (int)player_y, 25, 25, BLUE); 
    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
        //if(player_y <= 0 || player_y >= GetScreenHeight() - 25) player_y = player_y;
        follow(&player_x, &player_y, GetMouseX(), GetMouseY());
    }
    // if(IsKeyDown(KEY_W)){
    //     if(player_y <= 0) return;
    //     player_y -= speed * GetFrameTime();
    // } 
    // if(IsKeyDown(KEY_A)){
    //     if(player_x <= 0) return;
    //     player_x -= speed * GetFrameTime();     
    // } 
    // if(IsKeyDown(KEY_S)){
    //     if(player_y >= GetScreenHeight() - 25) return;
    //     player_y += speed * GetFrameTime();
    // } 
    // if(IsKeyDown(KEY_D)){
    //     if(player_x >= GetScreenWidth() - 25) return;
    //     player_x += speed * GetFrameTime();
    // } 
}