#include "Ball.h"
#include "raylib.h"

Ball::Ball()
{
}

float Ball::GetX()
{
	return x;
}
float Ball::GetY()
{
	return y;
}
float Ball::GetRadius()
{
	return rad;
}

int Ball::Move()
{
	x += xSpeed * GetFrameTime();
	y += ySpeed * GetFrameTime();
	if (y + rad > GetScreenHeight())
	{
		y = GetScreenHeight() - rad;
		ySpeed *= -1;
	}
	if (y - rad < 0)
	{
		y = 0 + rad;
		ySpeed *= -1;
	}
	if (x + rad > GetScreenWidth())
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		xSpeed *= -1;
		return -1;
	}
	if (x - rad < 0)
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		xSpeed *= -1;
		return 1;
	}
	return 0;
}