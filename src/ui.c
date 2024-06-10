#include "ui.h"
#include "externelheaders/raylib.h"
#include "tools.h"


extern Font font;

ButtonState draw_button(char* text, int x, int y, int sizeX, int sizeY, Color baseColor, Color textColor, Color hoverColor, int textSize) {
    if (!textSize) {
        textSize = sizeY / 2;
    }
    bool isMouseOver = CheckCollisionPointRec(GetMousePosition(), (Rectangle) { x, y, sizeX, sizeY });
    Color buttonColor = isMouseOver ? hoverColor : baseColor;

    DrawRectangle(x, y, sizeX, sizeY, buttonColor);

    int textWidth = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        textWidth += MeasureText(&text[i], textSize);
    }

    int textX = x + (sizeX - MeasureTextEx(font, text, textSize, 4).x) / 2;
    int textY = y + (sizeY - textSize) / 2;

    draw_text(text, textX, textY, textSize, textColor);

    if (isMouseOver && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_DOWN_LEFT;
    }

    if (isMouseOver && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_DOWN_RIGHT;
    }
    if (isMouseOver && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_CLICK_LEFT;
    }

    if (isMouseOver && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_CLICK_RIGHT;
    }
    
    if (isMouseOver) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_HOVER;
    }

    return BUTTON_NOT_INTERACTED;
}