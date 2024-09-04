#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



#include "main.h"



typedef struct _player{
    float player_x;
    float player_y;
    float speed;
    Texture2D player_image;
    float target_x;
    float target_y;
    bool target_activated;
    float bullet_x;
    float bullet_y;
    int current_bullet;
    bool bullet_active;
    float adder;
} player;


typedef struct _playersave{
    player player;
} playersave;

void run_player();



#endif