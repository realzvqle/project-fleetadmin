#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED




#include "externelheaders/raylib.h"
#include "main.h"
#include "stdint.h"

void start_npc();


typedef struct _npc {
    int x;
    int y;
    uint8_t ship_type;
    unsigned int ship_speed;
    Color color;
    bool is_alive;
    Rectangle rect; 
} npc;

typedef struct _station {
    int x;
    int y;
    uint8_t station_type;
    Color color;
    bool is_alive;
} station;

#endif