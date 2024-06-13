#include "sectors.h"
#include "externelheaders/raylib.h"
#include "main.h"
//#include "tools.h"
#include <string.h>
#include "player.h"


char* sector_names[] = {"Jupala", "Gacko", "Helium", "Solaris", "Windo", "Dubsix", "Jupitar", "Earthium", "Hexium",
                        "Mainium", "Rayium", "Unitium", "Goditium", "Unraxium", "Axisium", "Allieium", "Centrelium", "Germanium",
                        "Europium", "Amerium"};

char* prev_sector_names[9];
char* current_sector_names[9];
int current_player_coord;

// extern float player_x;
// extern float player_y;
//extern bool npc_init;
// extern bool target_activated;

extern player plyer;

void wormholes(){
    int height = (GAMEHEIGHT / 2.0f) - 90 * 6;
    if(current_player_coord > 0){
        DrawRectangle(GAMEWIDTH - 10, height, 10, 90, GREEN);
    }
    if(current_player_coord < 8){
        DrawRectangle(0, (GAMEHEIGHT / 2) - 90 * 6, 10, 90, GREEN);
    }
    if(CheckCollisionRecs((Rectangle){plyer.player_x, plyer.player_y, 25, 25}, 
                        (Rectangle){0, height, 10, 90}))
    {
        if(current_player_coord == 8){
            return;
        }
        current_player_coord++;
        plyer.player_y =  height;
        plyer.player_x = GAMEWIDTH - 70;
        //npc_init = false;   
        plyer.target_activated = false;
        printf("%s\n", current_sector_names[current_player_coord]);
    }
    if(CheckCollisionRecs((Rectangle){plyer.player_x, plyer.player_y, 25, 25}, 
                        (Rectangle){GAMEWIDTH - 10, height, 10, 90}))
    {
        if(current_player_coord <= 0){
            return;
        }
        current_player_coord--;
        plyer.player_y =  height;
        plyer.player_x = 0 + 70;
        plyer.target_activated = false;
        //npc_init = false;   
        printf("%s\n", current_sector_names[current_player_coord]);
    }
}


void generate_sectors() {
    //printf("%f\n", get_distance(player_x, player_y,(GAMEWIDTH - 10) - 25, (GAMEHEIGHT / 2.0f) - 90 * 6));
    static bool init = false;
    if (!init) {
        for (int i = 0; i < 9; i++) {
            bool unique = false;
            while (!unique) {
                int chances = GetRandomValue(0, 19);
                unique = true;
                for (int j = 0; j < i; j++) {
                    if (strcmp(prev_sector_names[j], sector_names[chances]) == 0) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    prev_sector_names[i] = sector_names[chances];
                    current_sector_names[i] = sector_names[chances];
                    printf("%s\n", current_sector_names[i]);
                }
            }
        }
        current_player_coord = 0;
        init = true;
        printf("----------------------\n");
        printf("%s\n", current_sector_names[current_player_coord]);

    }

    if(IsKeyPressed(KEY_G)){
        
    }
    if(IsKeyPressed(KEY_H)){
        if(current_player_coord >= 6){
            current_player_coord=current_player_coord;
        }
        else{
            current_player_coord++;
            current_player_coord++;
        }
        
        printf("%s\n", current_sector_names[current_player_coord]);
        
    }
    if (IsKeyPressed('R')) {
        memset(prev_sector_names, 0, sizeof(prev_sector_names));
        init = false;
    }
}


