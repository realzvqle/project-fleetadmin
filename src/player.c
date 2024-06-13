#include "player.h"
#include "externelheaders/raylib.h"
#include "tools.h"
#include "npc.h"
#include "ui.h"
#include <stdbool.h>
#include <threads.h>


extern float adder;


player plyer;

void shooting_mechanic(){
     if(IsKeyPressed(KEY_P)){
        plyer.bullet_active = true;
        //plyer.bullet_x = plyer.player_x;
        //plyer.bullet_y = plyer.player_y;
     }
     if(plyer.bullet_active){
        static bool init = false;
        int mouseX;
        int mouseY;
        if(!init){
            mouseX = GetMouseX();
            mouseY = GetMouseY();
            init = true;
        }    
        follow(&plyer.bullet_x, &plyer.bullet_y, mouseX, mouseY, false);
        DrawRectangle(plyer.bullet_x, plyer.bullet_x, 15, 15, RED);
        if(get_distance(plyer.player_x, plyer.player_x, plyer.bullet_x, plyer.bullet_y) > 1000){
            plyer.bullet_x = plyer.player_x;
            plyer.bullet_y = plyer.player_y;
            plyer.bullet_active = false;
        }
     }

    
}

void weapons() {
    if (GetMouseY() <= GetScreenHeight() - 300 && GetMouseX() <= GetScreenWidth() - 300) {            
        shooting_mechanic();     
    }
    
}


void run_player(){
    static bool init = false;
    if(init == false){    
        adder = 0.5;
        plyer.player_image = LoadTexture("assets/ship.png");
        plyer.player_x = GetScreenWidth() / 2.0f;
        plyer.player_y = GetScreenHeight() / 2.0f;
        plyer.bullet_active = false;
        plyer.target_activated = false;
        plyer.bullet_x = plyer.player_x;
        plyer.bullet_y = plyer.player_y;
        plyer.speed = 400.0f;
        init = true; 
    }
    float angle = calculate_angle(plyer.player_x, plyer.player_y, GetMouseX(), GetMouseY());
    DrawTextureEx(plyer.player_image, (Vector2){plyer.player_x - plyer.player_image.width / 2.0f, plyer.player_y - plyer.player_image.height / 2.0f}, angle + 80, 1, BLUE);
    if(GetMouseY() <= GetScreenHeight() - 300 && GetMouseX() <= GetScreenWidth() - 300){
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            follow(&plyer.player_x, &plyer.player_y, GetMouseX(), GetMouseY(), true);
        }
    }   
    game_ui();
    weapons();
}

