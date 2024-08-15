#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED







#include "externelheaders/raylib.h"
#include <stdio.h>
#include <stdbool.h>


#define GAMEWIDTH GetScreenWidth() - 300
#define GAMEHEIGHT GetScreenHeight() - 300

#define VER 0.0

typedef struct _data{
    int current_scene;
} data;






#endif