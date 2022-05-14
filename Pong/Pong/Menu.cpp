#include "Menu.h"
#include "raylib.h"

void Menu::OnDraw(int enemy, int player)
{
    int textWidthP = MeasureText(TextFormat("SCORE: %i", player), 20);
    int textWidthE = MeasureText(TextFormat("SCORE: %i", enemy), 20);
    DrawText(TextFormat("SCORE: %i", enemy), GetScreenWidth() / 4 - textWidthE, 10, 20, RED);
    DrawText(TextFormat("SCORE: %i", player), GetScreenWidth() / 4 * 3 - textWidthP, 10, 20, BLUE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, WHITE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 45, BLACK);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight() / 2 - 50, WHITE);
    DrawLine(GetScreenWidth() / 2, GetScreenHeight(), GetScreenWidth() / 2, GetScreenHeight() / 2 + 50, WHITE);
}

void Menu::Winner(const char* winner)
{
        int textWidth = MeasureText(winner, 100);
        DrawText(winner, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 50, 100, YELLOW);
        int newTextWidth = MeasureText("PRESS 'SPACE' TO RESTART", 25);
        DrawText("PRESS 'SPACE' TO RESTART", GetScreenWidth() / 2 - newTextWidth / 2, GetScreenHeight() / 2 + 50, 25, YELLOW);
}