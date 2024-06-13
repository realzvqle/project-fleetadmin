#include "ui.h"
#include "externelheaders/raylib.h"
#include "player.h"
#include "tools.h"


extern Font font;
extern float adder;
extern player plyer;
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






static inline void weapon_ui(){
    draw_text("P To Shoot", (GetScreenWidth() - 180), 40, 20, WHITE);
    ButtonState small_turrent = draw_button("Small Turret", GetScreenWidth() - 180, 90, 180, 30, GREEN, WHITE, LIME, NULL);
    if(small_turrent == BUTTON_CLICK_LEFT){
        plyer.current_bullet = 1;
    }
    ButtonState large_turrent = draw_button("Large Turret", GetScreenWidth() - 180, 120, 180, 30, SKYBLUE, WHITE, BLUE, NULL);
    if(large_turrent == BUTTON_CLICK_LEFT){
        plyer.current_bullet = 2;
    }
}

void game_ui(){
    DrawRectangleLines(GetScreenWidth() - 300, GetScreenHeight() - GetScreenHeight(), 300, GetScreenHeight(), RED);
    DrawRectangleLines(GetScreenWidth() - GetScreenWidth(), GetScreenHeight() - 300, GetScreenWidth(), 300, RED);
    ButtonState IncreaseButton = draw_button("+", GetScreenWidth() - 60, GetScreenHeight() - 200, 40, 40, WHITE, BLACK, DARKGRAY, NULL);
    if(IncreaseButton == BUTTON_CLICK_LEFT){
        if(adder >= 2) return;
        adder += 0.1;
    }
    char buffer[512];
    sprintf(buffer, "%0.1f", adder);
    draw_text(buffer, GetScreenWidth() - 60, GetScreenHeight() - 130, 40, WHITE);
    ButtonState DecreaseButton = draw_button("-", GetScreenWidth() - 60, GetScreenHeight() - 60, 40, 40, WHITE, BLACK, DARKGRAY, NULL);
    if(DecreaseButton == BUTTON_CLICK_LEFT){
        if(adder <= 0.1) return;
        adder -= 0.1;
    }
    weapon_ui();
}
