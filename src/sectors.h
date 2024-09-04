#ifndef SECTORS_H_INCLUDED
#define SECTORS_H_INCLUDED




#include "main.h"


typedef struct _sav{
    int current_player_coords;
    char sector_names[9][255];
} sav;

void wormholes();
void generate_sectors();


#endif