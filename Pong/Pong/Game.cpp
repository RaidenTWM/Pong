#include "raylib.h"
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"

Ball* ball;
Paddle* lPaddle;
Paddle* rPaddle;
void Game::Init()
{
    ball = new Ball();
    lPaddle = new Paddle('l');
    rPaddle = new Paddle('r');
    lPaddle->x = 25;
    rPaddle->x = (GetScreenWidth() - 25);
}

Game::Game()
{
}

Game::~Game() {
}

void Game::Update()
{
    point = ball->OnUpdate();
    lPaddle->OnUpdate(ball);
    rPaddle->OnUpdate(ball);
    if (point > 0) { point = 0; playerPoints += 1; }
    if (point < 0) { point = 0; enemyPoints += 1; }
}

void Game::Shutdown() 
{
    delete ball;
    ball = nullptr;
    delete lPaddle;
    lPaddle = nullptr;
    delete rPaddle;
    rPaddle = nullptr;
}
void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);
    ball->OnDraw();
    lPaddle->OnDraw();
    rPaddle->OnDraw();
    DrawText(TextFormat("SCORE: %i", enemyPoints), GetScreenWidth() / 2 - 300, 10, 20, RED);
    DrawText(TextFormat("SCORE: %i", playerPoints), GetScreenWidth() / 2 + 300, 10, 20, BLUE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, WHITE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 45, BLACK);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight() / 2 - 50, WHITE);
    DrawLine(GetScreenWidth() / 2, GetScreenHeight(), GetScreenWidth() / 2, GetScreenHeight() / 2 + 50, WHITE);

    EndDrawing();
}
