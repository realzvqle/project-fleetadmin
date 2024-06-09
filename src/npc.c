#include "npc.h"
#include "externelheaders/raylib.h"
#include "tools.h"
#include <math.h>

int y_arr[20];
int x_arr[20];
bool npc_init = false;
extern float player_x;
extern float player_y;

Texture2D npc_image;
Texture2D station_image;


static inline void create_npc(npc* npc) {
    float angle = calculate_angle(npc->x, npc->y, player_x, player_y);
    if (npc->is_alive){
        DrawTextureEx(npc_image,(Vector2){npc->x, npc->y}, angle + 80, 1, npc->color);
        //DrawRectangleLines(npc->x , npc->y, 25, 25, npc->color);
    }
}

static inline void create_station(station* station) {
    if (station->is_alive){
        DrawTexture(station_image, station->x, station->y, station->color);

        DrawRectangleLines(station->x, station->y, 25, 25, station->color);
    } 
}

static inline void delete_npc(npc* npc) {
    npc->is_alive = false;
}

static inline void follow_player(npc* npc){
    if(npc->likeness != 0) return;
    float speed = 40 * GetFrameTime();
    float distance = get_distance(npc->x, npc->y, player_x, player_y);
    if(distance >= 25){
        npc->rotation = distance;
        if(npc->x == player_x){
            //printf("Equal On the X Axis\n");
        }
        if(npc->x < player_x){
            npc->x = fmin(npc->x + speed, player_x);
            
        }
        if(npc->x > player_x){
            npc->x = fmax(npc->x - speed, player_x);

        }
        if(npc->y == player_y){
           //printf("Equal On the Y Axis\n");

        }
        if(npc->y < player_y){
            npc->y = fmin(npc->y + speed, player_y);

        }
        if(npc->y > player_y){
            npc->y = fmax(npc->y - speed, player_y);

        }
    }
}


static inline void npc_logic(npc* npc, int i){
    follow_player(npc);    
}

void start_npc() {
    static int station_count;
    static int ship_count;
    static station stion[3];  
    static npc ships[17];
    if (!npc_init) {
        npc_image = LoadTexture("assets/ship.png");
        station_image = LoadTexture("assets/station.png");
        
        station_count = 0;
        ship_count = 0;
        for (int i = 0; i < 20; i++) {
            if (i % 8 == 0 && station_count < 3) {  
                stion[station_count].likeness = GetRandomValue(0, 4);      
                stion[station_count].y = GetRandomValue(0, GAMEHEIGHT - 25);
                stion[station_count].x = GetRandomValue(0, GAMEWIDTH - 25);
                switch(ships[ship_count].likeness){
                    case 0:
                        stion[station_count].color = RED;
                        break;
                    case 1:
                        stion[station_count].color = ORANGE;
                        break;
                    case 2:
                        stion[station_count].color = YELLOW;
                        break;
                    case 3:
                        stion[station_count].color = LIME;
                        break;
                    case 4:
                        stion[station_count].color = DARKGREEN;
                        break;
                    default:
                        stion[station_count].color = WHITE;
                        break;
                }
                stion[station_count].is_alive = true;
                station_count++;
            } else if (ship_count < 17) {  
                ships[ship_count].rotation = 0;  
                ships[ship_count].likeness = GetRandomValue(0, 4);      
                ships[ship_count].y = GetRandomValue(0, GAMEHEIGHT - 25);
                ships[ship_count].x = GetRandomValue(0, GAMEWIDTH - 25);
                switch(ships[ship_count].likeness){
                    case 0:
                        ships[ship_count].color = RED;
                        break;
                    case 1:
                        ships[ship_count].color = ORANGE;
                        break;
                    case 2:
                        ships[ship_count].color = YELLOW;
                        break;
                    case 3:
                        ships[ship_count].color = LIME;
                        break;
                    case 4:
                        ships[ship_count].color = DARKGREEN;
                        break;
                    default:
                        ships[ship_count].color = WHITE;
                        break;
                }
                ships[ship_count].is_alive = true;
                int x = ships[ship_count].x;
                int y = ships[ship_count].x;
                ships[ship_count].rect = (Rectangle){x, y, 25, 25};
                ship_count++;
            }
        }
        npc_init = true;
    }
    station_count = 0;
    ship_count = 0;
    for (int i = 0; i < 20; i++) {
        if(IsKeyPressed(KEY_R)) npc_init = false;
        if (i % 8 == 0 && station_count < 3) {
            create_station(&stion[station_count]);
            station_count++;
        } else if (ship_count < 17) {
            create_npc(&ships[ship_count]);
            npc_logic(&ships[ship_count], i);
            ship_count++;
        }
    }
}

