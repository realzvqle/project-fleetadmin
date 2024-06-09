#include "window.h"
#include "externelheaders/raylib.h"
#include "scenes.h"






void start_window(){
    data dt = {
        0
    };
    SetTraceLogLevel(LOG_FATAL);
    InitWindow(1920, 1080, "Confidential");
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        check_scenes(&dt);
        EndDrawing();
    }
}