#include "raylib.h"
#include "Game.h"

void Game::Init()
{
}

Game::Game()
{
}

void Game::Shutdown()
{
}

void Game::Update()
{
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);

    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE);

    DrawRectangle(25, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
    DrawRectangle(GetScreenWidth() - 25, GetScreenHeight() / 2 - 50, 10, 100, WHITE);

    EndDrawing();
}
