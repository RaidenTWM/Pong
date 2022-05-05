#include "raylib.h"
#include "Game.h"
#include "Ball.h"

Ball* ball;
void Game::Init()
{
    ball = new Ball();
}

Game::Game()
{
}

Game::~Game() {
}

void Game::Update()
{
    point = ball->Move();
    if (point > 0) { point = 0; playerPoints += 1; }
    if (point < 0) { point = 0; enemyPoints += 1; }
}

void Game::Shutdown() 
{
    delete ball;
    ball = nullptr;
}
void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);

    DrawText(TextFormat("SCORE: %i", enemyPoints), GetScreenWidth() / 2 - 300, 10, 20, RED);
    DrawText(TextFormat("SCORE: %i", playerPoints), GetScreenWidth() / 2 + 300, 10, 20, BLUE);

    DrawCircle(ball->GetX(), ball->GetY(), ball->GetRadius(), WHITE);

    DrawRectangle(25, GetScreenHeight() / 2 - 50, 10, 100, RED);
    DrawRectangle(GetScreenWidth() - 25, GetScreenHeight() / 2 - 50, 10, 100, BLUE);

    EndDrawing();
}
