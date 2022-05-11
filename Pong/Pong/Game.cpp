#include "raylib.h"
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"

Ball* ball;
Paddle* lPaddle;
Paddle* rPaddle;
const char* winner = nullptr;
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
    if (enemyPoints == 1)
    {
        winner = "Left Player Wins!";
        playerPoints = 0; enemyPoints = 0;
        ball->Stop();
    }
    if (playerPoints == 1)
    {
        winner = "Right Player Wins!";
        playerPoints = 0; enemyPoints = 0;
        ball->Stop();
    }
    if (winner != nullptr && IsKeyPressed(KEY_SPACE))
    {
        ball->Start();
        winner = nullptr;
    }
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
    int textWidthP = MeasureText(TextFormat("SCORE: %i", playerPoints), 20);
    int textWidthE = MeasureText(TextFormat("SCORE: %i", enemyPoints), 20);
    DrawText(TextFormat("SCORE: %i", enemyPoints), GetScreenWidth() / 2 - 200 - textWidthE, 10, 20, RED);
    DrawText(TextFormat("SCORE: %i", playerPoints), GetScreenWidth() / 2 + 200 + textWidthP, 10, 20, BLUE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, WHITE);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 45, BLACK);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight() / 2 - 50, WHITE);
    DrawLine(GetScreenWidth() / 2, GetScreenHeight(), GetScreenWidth() / 2, GetScreenHeight() / 2 + 50, WHITE);
    ball->OnDraw();
    lPaddle->OnDraw();
    rPaddle->OnDraw();
    if (winner != nullptr)
    {
        int textWidth = MeasureText(winner, 100);
        DrawText(winner, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 50, 100, YELLOW);
    }

    EndDrawing();
}
