#include "player.h"


float player_x;
float player_y;
float speed;


void run_player(){
    static bool init = false;
    if(init == false){
        player_x = GetScreenWidth() / 2.0f;
        player_y = GetScreenHeight() / 2.0f;
        speed = 400.0f;
        init = true;
    }

    DrawRectangle((int)player_x, (int)player_y, 25, 25, BLUE);
    if(IsKeyDown(KEY_W)){
        if(player_y <= 0) return;
        player_y -= speed * GetFrameTime();
    } 
    if(IsKeyDown(KEY_A)){
        if(player_x <= 0) return;
        player_x -= speed * GetFrameTime();     
    } 
    if(IsKeyDown(KEY_S)){
        if(player_y >= GetScreenHeight() - 25) return;
        player_y += speed * GetFrameTime();
    } 
    if(IsKeyDown(KEY_D)){
        if(player_x >= GetScreenWidth() - 25) return;
        player_x += speed * GetFrameTime();
    } 
}