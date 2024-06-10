#include "gameloop.h"
#include "externelheaders/raylib.h"
#include "player.h"
#include "player.h"
#include "sectors.h"
#include "tools.h"

extern char* current_sector_names[9];
extern int current_player_coord;

void gameloop(){
    wormholes();
    generate_sectors();

    char buffer[512];
    sprintf(buffer, "Build IN-DEVELOPMENT-PRERELEASE %0.1f" "\t\t\t\tSector: %s", VER, current_sector_names[current_player_coord]);
    draw_text(buffer, 10, GetScreenHeight() - 35, 25, WHITE);
    run_player();
    //start_npc();
    // NPC needs a MASSIVE Rewrite lmao
    
}




