#include "window.h"
#include "externelheaders/raylib.h"
#include "player.h"
#include "scenes.h"



Font font;
// extern Texture2D player_image;
// extern Texture2D npc_image;
// extern Texture2D station_image;
extern player plyer;

void start_window(){
    data dt = {
        0
    };
    SetTraceLogLevel(LOG_FATAL);
    InitWindow(1920, 1080, "Confidential");
    font = LoadFontEx("assets/Pixelify_Sans/PixelifySans-VariableFont_wght.ttf", 130, NULL, 0);

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(BLACK);
        check_scenes(&dt);
        EndDrawing();
    }
    UnloadFont(font);
    UnloadTexture(plyer.player_image);
    //UnloadTexture(npc_image);
    //UnloadTexture(station_image);

    CloseWindow();
}