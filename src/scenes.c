#include "scenes.h"
#include "externelheaders/raylib.h"
#include "gameloop.h"
#include "ui.h"
#include "tools.h"


extern Font font;


void check_scenes(data* data){
    switch(data->current_scene){
        case 0:
            draw_text(
                "Project-FleetAdmin", 
                (GetScreenWidth() - MeasureTextEx(font, "Project-FleetAdmin", 70, 1).x) / 2,
                 GetScreenHeight() / 2, 70, RED);
            ButtonState button = draw_button("Play", (GetScreenWidth() - 190) / 2, GetScreenHeight() /2 + 180, 190, 90, WHITE, BLACK, GRAY, NULL);
            if(button == BUTTON_CLICK_LEFT){
                data->current_scene = 1;
            }
            draw_text("HOW TO MOVE:\n\n\nclick at a position to move the player", 10, 10, 36, WHITE);

            break;
        case 1: 
            gameloop();
            break;
        default:
            DrawText(
                "Current Scene Is Invalid", 
                (GetScreenWidth() - MeasureText("Current Scene is Invalid", 70)) / 2,
                 GetScreenHeight() / 2, 70, RED);
            break;
    }
}