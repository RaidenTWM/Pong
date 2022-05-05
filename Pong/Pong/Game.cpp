#include "raylib.h"
#include "Game.h"
#include "Ball.h"

Ball* ball;
float ballX;
float ballY;
float ballRad;
void Game::Init()
{
    ball = new Ball();
}

Game::Game()
{
}

void Game::Shutdown()
{
}

void Game::Update()
{
    ball->Move();
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);

    DrawCircle(ball->GetX(), ball->GetY(), ball->GetRadius(), WHITE);

    DrawRectangle(25, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
    DrawRectangle(GetScreenWidth() - 25, GetScreenHeight() / 2 - 50, 10, 100, WHITE);

    EndDrawing();
}
