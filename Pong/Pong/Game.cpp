#include "raylib.h"
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Menu.h"

Ball* ball;
Paddle* lPaddle;
Paddle* rPaddle;
Menu* menu;
const char* winner = nullptr;
void Game::Init()
{
    ball = new Ball();
    lPaddle = new Paddle('l');
    rPaddle = new Paddle('r');
    lPaddle->x = 25;
    rPaddle->x = (GetScreenWidth() - 25);
    menu = new Menu();
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
        winner = "LEFT PLAYER WINS!";
        ball->Stop();
    }
    if (playerPoints == 1)
    {
        winner = "RIGHT PLAYER WINS!";
        ball->Stop();
    }
    if (winner != nullptr && IsKeyPressed(KEY_SPACE))
    {
        ball->Start();
        playerPoints = 0; enemyPoints = 0;
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
    delete menu;
    menu = nullptr;
}
void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawFPS(10, 10);
    menu->OnDraw(enemyPoints, playerPoints);
    ball->OnDraw();
    lPaddle->OnDraw();
    rPaddle->OnDraw();
    if (winner != nullptr)
    {
        menu->Winner(winner);
    }
    EndDrawing();
}
