#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED


#include "main.h"

float get_distance(float x_1, float y_1, float x_2, float y_2);
float calculate_angle(float x_1, float y_1, float x_2, float y_2);
void follow(float* x_1, float* y_1, float x_2, float y_2, bool isPlayer);
void draw_text(const char *text, int posX, int posY, int fontSize, Color color);
#endif