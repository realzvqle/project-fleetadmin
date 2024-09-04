#include "gameloop.h"
#include "externelheaders/raylib.h"
#include "player.h"
#include "player.h"
#include "sectors.h"
#include "tools.h"
#include "sectors.h"
extern sav save;

void gameloop(){
    wormholes();
    generate_sectors();

    char buffer[512];
    sprintf(buffer, "Build IN-DEVELOPMENT-PRERELEASE %0.1f" "\t\t\t\tSector: %s", VER, save.sector_names[save.current_player_coords]);
    draw_text(buffer, 10, GetScreenHeight() - 35, 25, WHITE);
    run_player();
    //start_npc();
    // NPC needs a MASSIVE Rewrite lmao
    
}




