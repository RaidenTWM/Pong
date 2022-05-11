#include "Ball.h"
#include "raylib.h"

Ball::Ball()
{
}

float Ball::GetX()
{
	return x;
}
void Ball::InvertSpeedY()
{
	ySpeed *= -1;
}
float Ball::GetSpeedX()
{
	return xSpeed;
}
float Ball::GetSpeedY()
{
	return ySpeed;
}
void Ball::InvertSpeedX()
{
	xSpeed *= -1;
}
float Ball::GetY()
{
	return y;
}
float Ball::GetRadius()
{
	return rad;
}


int Ball::OnUpdate()
{
	x += xSpeed * GetFrameTime();
	y += ySpeed * GetFrameTime();
	if (y + rad > GetScreenHeight())
	{
		y = GetScreenHeight() - rad;
		InvertSpeedY();
	}
	if (y - rad < 0)
	{
		y = 0 + rad;
		InvertSpeedY();
	}
	if (x + rad > GetScreenWidth() - 10)
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		InvertSpeedX();
		return -1;
	}
	if (x - rad < 10)
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		InvertSpeedX();
		return 1;
	}
	return 0;
}
void Ball::OnDraw()
{
	DrawCircle(GetX(), GetY(), GetRadius(), WHITE);
}