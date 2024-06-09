#include "gameloop.h"
#include "externelheaders/raylib.h"
#include "npc.h"
#include "player.h"
#include "player.h"
#include "sectors.h"


void gameloop(){
    wormholes();
    char buffer[512];
    sprintf(buffer, "Build %0.1f", VER);
    DrawText(buffer, 10, 10, 16, WHITE);
    run_player();
    start_npc();
    generate_sectors();

    
}




