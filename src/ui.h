#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED






#include "main.h"


typedef enum ButtonState{
    BUTTON_NOT_INTERACTED,
    BUTTON_HOVER,
    BUTTON_CLICK_LEFT,
    BUTTON_CLICK_RIGHT,
    BUTTON_DOWN_LEFT,
    BUTTON_DOWN_RIGHT
} ButtonState;


ButtonState draw_button(char* text, int x, int y, int sizeX, int sizeY, Color baseColor, Color textColor, Color hoverColor, int textSize);
void game_ui();


#endif