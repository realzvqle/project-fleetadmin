#include "player.h"
#include "externelheaders/raylib.h"
#include "main.h"
#include "tools.h"
#include "ui.h"
#include <threads.h>

float player_x;
float player_y;
float speed;
extern float adder;
Texture2D player_image;
float target_x;
float target_y;
bool target_activated = false;
float bullet_x;
float bullet_y;
int current_bullet;
static bool bullet_active = false;


void weapons() {
    static bool target_activated = false;
    static int target_x = 0;
    static int target_y = 0;
    draw_text("P To Shoot", (GetScreenWidth() - 180), 40, 20, WHITE);
    ButtonState small_turrent = draw_button("Small Turret", GetScreenWidth() - 180, 90, 180, 30, RED, WHITE, ORANGE, NULL);
    if(small_turrent == BUTTON_CLICK_LEFT){
        current_bullet = 1;
    }
    ButtonState large_turrent = draw_button("Large Turret", GetScreenWidth() - 180, 120, 180, 30, GREEN, WHITE, DARKGREEN, NULL);
    if(large_turrent == BUTTON_CLICK_LEFT){
        current_bullet = 2;
    }
    if (GetMouseY() <= GetScreenHeight() - 300 && GetMouseX() <= GetScreenWidth() - 300) {
        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            target_x = GetMouseX();
            target_y = GetMouseY();
            target_activated = true;
        }
    }

    if (target_activated) {
        Color color;
        switch(current_bullet){
            case 0:
                color = RED;
                break;
            case 1:
                color = GREEN;
                break;
            case 2:
                color = SKYBLUE;
                break;
            default:
                break;
        }
        DrawRectangleLines(target_x - 15, target_y - 15, 30, 30, color);

        if (IsKeyPressed(KEY_P)) {
            bullet_x = player_x;
            bullet_y = player_y;
            bullet_active = true;
        }
        if (bullet_active) {
            
            DrawRectangle(bullet_x, bullet_y, 10, 10, color);
            follow(&bullet_x, &bullet_y, target_x, target_y, false);
                
            if (get_distance(bullet_x, bullet_y, target_x, target_y) < 10) {
                bullet_active = false;
                bullet_x = 0;
                bullet_y = 0;
            }
        }
    }
}


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
            follow(&player_x, &player_y, GetMouseX(), GetMouseY(), true);
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
    draw_text(buffer, GetScreenWidth() - 60, GetScreenHeight() - 130, 40, WHITE);
    ButtonState DecreaseButton = draw_button("-", GetScreenWidth() - 60, GetScreenHeight() - 60, 40, 40, WHITE, BLACK, DARKGRAY, NULL);
    if(DecreaseButton == BUTTON_CLICK_LEFT){
        if(adder <= 0.1) return;
        adder -= 0.1;
    }
    weapons();
}

