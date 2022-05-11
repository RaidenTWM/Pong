#pragma once
#include "raylib.h"
#include "Ball.h"
class Paddle :
    public Ball
{
protected:
    float speed = 300;
    float width = 10;
    float height = 100;
public:
    float x = 0;
    float y = 0;
    char side = 'a';
    Paddle(char s);
    float GetX();
    float GetY();
    Rectangle GetRect();
    void OnUpdate(Ball* ball);
    void OnDraw();
};

