#include "scenes.h"
#include "externelheaders/raylib.h"
#include "gameloop.h"






void check_scenes(data* data){
    switch(data->current_scene){
        case 0: 
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