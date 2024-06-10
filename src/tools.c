#include "tools.h"
#include "externelheaders/raylib.h"
#include <math.h>




float adder;
extern Font font;

float get_distance(float x_1, float y_1, float x_2, float y_2){
    float sub_x = x_2 - x_1;
    float sub_y = y_2 - y_1;
    float sqr_x = sub_x * sub_x;
    float sqr_y = sub_y * sub_y;
    float add_x_and_y = sqr_x + sqr_y;
    float distance = sqrtf(add_x_and_y);
    return distance;
}

float calculate_angle(float x_1, float y_1, float x_2, float y_2) {
    float dx = x_2 - x_1;
    float dy = y_2 - y_1;
    return atan2f(dy, dx) * (180.0f / PI); 
}

void follow(float* x_1, float* y_1, float x_2, float y_2, bool isPlayer) {
    if(!adder){
        adder = 1;
    }
    float speed;
    if(isPlayer) speed = (400 * adder) * GetFrameTime();
    else speed = (400) * GetFrameTime();

    float distance = get_distance(*x_1, *y_1, x_2, y_2);
    if (distance >= 10) {
        if (*x_1 < x_2) {
            *x_1 += speed;
            if (*x_1 > x_2) *x_1 = x_2; 
        } else if (*x_1 > x_2) {
            *x_1 -= speed;
            if (*x_1 < x_2) *x_1 = x_2;
        }
        
        if (*y_1 < y_2) {
            *y_1 += speed;
            if (*y_1 > y_2) *y_1 = y_2; 
        } else if (*y_1 > y_2) {
            *y_1 -= speed;
            if (*y_1 < y_2) *y_1 = y_2; 
        }
    }
}


void draw_text(const char *text, int posX, int posY, int fontSize, Color color){
    
    DrawTextEx(font, text, (Vector2){posX, posY}, fontSize, 1, color);
}