#include "player.h"
#include "externelheaders/raylib.h"
#include "tools.h"
#include "ui.h"

float player_x;
float player_y;
float speed;
extern float adder;
Texture2D player_image;

void run_player(){
    static bool init = false;
    if(init == false){
        adder = 0.5;
        player_image = LoadTexture("assets/ship.png");
        player_x = GetScreenWidth() / 2.0f;
        player_y = GetScreenHeight() / 2.0f;
        speed = 400.0f;
        init = true;

        
    }
    float angle = calculate_angle(player_x, player_y, GetMouseX(), GetMouseY());
    DrawTextureEx(player_image, (Vector2){player_x - player_image.width / 2.0f, player_y - player_image.height / 2.0f}, angle + 80, 1, BLUE);
    //DrawRectangleLines((int)player_x, (int)player_y, 25, 25, BLUE); 
    if(GetMouseY() <= GetScreenHeight() - 300 && GetMouseX() <= GetScreenWidth() - 300){
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            follow(&player_x, &player_y, GetMouseX(), GetMouseY());
        }
    }   
    DrawRectangleLines(GetScreenWidth() - 300, GetScreenHeight() - GetScreenHeight(), 300, GetScreenHeight(), RED);
    DrawRectangleLines(GetScreenWidth() - GetScreenWidth(), GetScreenHeight() - 300, GetScreenWidth(), 300, RED);
    ButtonState IncreaseButton = draw_button("+", GetScreenWidth() - 60, GetScreenHeight() - 200, 40, 40, WHITE, BLACK, DARKGRAY, NULL);
    if(IncreaseButton == BUTTON_CLICK_LEFT){
        if(adder >= 2) return;
        adder += 0.1;
    }
    char buffer[512];
    sprintf(buffer, "%0.1f", adder);
    DrawText(buffer, GetScreenWidth() - 60, GetScreenHeight() - 130, 40, WHITE);
    ButtonState DecreaseButton = draw_button("-", GetScreenWidth() - 60, GetScreenHeight() - 60, 40, 40, WHITE, BLACK, DARKGRAY, NULL);
    if(DecreaseButton == BUTTON_CLICK_LEFT){
        if(adder <= 0.1) return;
        adder -= 0.1;
    }
}