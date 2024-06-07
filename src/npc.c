#include "npc.h"
#include "externelheaders/raylib.h"

int y_arr[20];
int x_arr[20];

static inline void create_npc(npc* npc) {
    if (npc->is_alive) DrawRectangle(npc->x, npc->y, 25, 25, npc->color);
}

static inline void create_station(station* station) {
    if (station->is_alive) DrawCircle(station->x, station->y, 25, station->color);
}

static inline void delete_npc(npc* npc) {
    npc->is_alive = false;
}

void start_npc() {
    static station stion[3];  
    static npc ships[17];
    static bool init = false;
    if (!init) {
        int station_count = 0;
        int ship_count = 0;
        for (int i = 0; i < 20; i++) {
            if (i % 8 == 0 && station_count < 3) {  
                stion[station_count].y = GetRandomValue(0, 900 - 25);
                stion[station_count].x = GetRandomValue(0, 1600 - 25);
                stion[station_count].color = WHITE;
                stion[station_count].is_alive = true;
                station_count++;
            } else if (ship_count < 17) {          
                ships[ship_count].y = GetRandomValue(0, 900 - 25);
                ships[ship_count].x = GetRandomValue(0, 1600 - 25);
                ships[ship_count].color = WHITE;
                ships[ship_count].is_alive = true;
                int x = ships[ship_count].x;
                int y = ships[ship_count].x;
                ships[ship_count].rect = (Rectangle){x, y, 25, 25};
                ship_count++;
            }
        }
        init = true;
    }
        int station_count = 0;
    int ship_count = 0;
    for (int i = 0; i < 20; i++) {
        if(IsKeyPressed(KEY_R)) init = false;
        if (i % 8 == 0 && station_count < 3) {
            create_station(&stion[station_count]);
            station_count++;
        } else if (ship_count < 17) {
            create_npc(&ships[ship_count]);
            ship_count++;
        }
    }
}

